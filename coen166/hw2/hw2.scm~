;Evan Eberhardt
;Assignment 2 May 16
;THIS CODE IS INCOMPLETE 
;The percept shown in the assignment file is hardcoded, it doesn't take aribitrary states, and hueristic funciton isn't operable 
;I CAN FIX THIS   I NEED MORE TIME   T_T

;>>>>>>>>>>>-<<<<<<<<<<<<
;Assignment 1 Helper Code
;>>>>>>>>>>>-<<<<<<<<<<<<

;Various helper functions from previous assignment
;modified for re-use in A*, but essentially the same

(define (find-smallest alist)
  		;Base case: one element in list
		(cond ((null? (cdr alist)) (car alist))
			  ;compare first element with the rest, see if it's smaller
			  ((< (car alist) (find-smallest (cdr alist))) (car alist))
			  ;otherwise it is something in the rest of the list that is smaller
			  (else (find-smallest (cdr alist)))))


(define (find-biggest alist)
  		;base case: one element in list
		(cond ((null? (cdr alist)) (car alist))
			  ;compare first element with rest, see if it's bigger
			  ((> (car alist) (find-smallest (cdr alist))) (car alist))
			  ;otherwise it is someting in the rest of the list that is bigger
			  (else (find-smallest (cdr alist)))))


;find's action in open list with smallest A* value
(define (find-smallest-act alist)
		;Base case: one element in list
		(cond ((null? (cdr alist)) (car alist))
			  ;compare first element with rest, see if it has smaller A* value
			  ((< (nth-item 2 (car alist)) (nth-item 2 (find-smallest-act (cdr alist)))) (car alist))
			  ;otherwise it is something in the rest of the list that is smaller
			  (else (find-smallest-act (cdr alist)))))


;removes an action from the open list
;relies on unique action + A*value combiniations
(define (remove-action alist action)
		;base case: remove first element
		(cond ((equal-actions action (car alist)) (cdr alist))
			  ;compare action with the rest, see if equal
			  (#t (append (list (car alist)) (remove-action (cdr alist) action)))))

;helper function for remove-action
(define (equal-actions base comp)
  		(and (equal? (nth-item 1 base) (nth-item 1 comp))
			 (equal? (nth-item 2 base) (nth-item 2 comp))))


(define (nth-item idx alist)
  		;base case: first element is desired element given index
  		(cond ((= idx 1) (car alist))
			  ;decrement the index and take the cdr for recursion to get to desired index
			  (#t (nth-item (- idx 1) (cdr alist)))))


(define (replace-nth-item idx alist n)
  		;base case: first element is to be replaced, make list of n and remainder of alist
 		(cond ((= idx 1) (append (list n) (cdr alist)))
			  ;recursing backwards from insert point putting previous item in front
			  (#t (append (list (car alist)) (replace-nth-item (- idx 1) (cdr alist) n)))))


;apply action works as expected only on "fixed" 1-10 states (see "Coat Check" below)
(define (apply-action state action)
  		;determines result based on condition checks for the input
		;"stay" just returns the original state
  		(cond ( (equal? action "STAY") state )
			  ( (equal? action "MOVE-1") (move1 state) )
			  ( (equal? action "MOVE-2") (move2 state) )
			  ( (equal? action "MOVE-3") (move3 state) )
			  ( (equal? action "TURN-LEFT") (turnL state) )
			  ( (equal? action "TURN-RIGHT") (turnR state) )
			  ))

;Helper funcitons to apply-action
;each "move" checks the direction to determine whether to modify x or y, and how to modify it.
;all "move"s follow the same pattern for modifying state
;the funciton nth-item is used to check the direction in state against a dummy state 
;with the corresponding direction
;replace-nth-item is used to alter the correct value x or y
(define (move1 state)
		(cond ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
				(replace-nth-item 2 state (- (car (cdr state)) 1))
			  )
			  ;if facing north, move up by subtracting from y

			  (	(equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
				(replace-nth-item 2 state (+ (car (cdr state)) 1))
			  )
			  ;if facing south, subtract from y

			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
				(replace-nth-item 1 state (+ (car state) 1))
			  )
			  ;if facing east, add to x
			
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
				(replace-nth-item 1 state (- (car state) 1))
			  )
			  ;if facing west, subtract from x
			  (newline)
			  ))

(define (move2 state)
  		(cond ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
			   	(replace-nth-item 2 state (- (car (cdr state)) 2))
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
			    (replace-nth-item 2 state (+ (car (cdr state)) 2))
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
			    (replace-nth-item 1 state (+ (car state) 2))
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
			    (replace-nth-item 1 state (- (car state) 2))
			  )
			  ))

(define (move3 state)
  		(cond ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
			    (replace-nth-item 2 state (- (car (cdr state)) 3))
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
			   	(replace-nth-item 2 state (+ (car (cdr state)) 3))
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
			    (replace-nth-item 1 state (+ (car state) 3))
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
			    (replace-nth-item 1 state (- (car state) 3))
			  )
			  ))

(define (turnR state)
  		(cond ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
			    (replace-nth-item 3 state 'E)
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
			    (replace-nth-item 3 state 'S)
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
			    (replace-nth-item 3 state 'W)
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
			    (replace-nth-item 3 state 'N)
			  )
			  ))

(define (turnL state)
  		(cond ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
			    (replace-nth-item 3 state 'W)
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
			    (replace-nth-item 3 state 'S)
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
			    (replace-nth-item 3 state 'E)
			  )
			  ( (equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
			    (replace-nth-item 3 state 'N)
			  )
			  ))

;DEFAULT Percept 10X10 grid of HW2
(define percept
  		;this is the given percept as a list
		(list '(empty empty empty empty empty empty empty empty empty empty)
			  '(barrier empty barrier barrier empty empty barrier barrier barrier empty)
			  '(barrier empty barrier barrier empty barrier barrier empty empty empty)
			  '(barrier empty barrier barrier empty barrier barrier empty barrier empty)
			  '(barrier empty (goal 100) barrier empty barrier barrier (goal 1000) barrier empty)
			  '(barrier empty barrier barrier empty barrier barrier barrier barrier empty)
			  '(empty empty empty barrier empty empty empty empty empty empty)
			  '(empty barrier barrier barrier barrier barrier barrier empty barrier barrier)
			  '(empty barrier barrier barrier barrier barrier barrier empty empty empty)
			  '(empty empty empty empty (goal 20) barrier barrier barrier barrier empty)))

;Get location API now %198 prettier
(define (get-loc percept x y)
		(nth-item x (nth-item y percept)))
(define (get-location state)
  		(get-loc percept (nth-item 1 state) (nth-item 2 state)))

;>>>>>>>>>>>>>>>>>-<<<<<<<<<<<<<<<<<<<<
;Begin Assignment 2 Main Algorithm Code
;>>>>>>>>>>>>>>>>>-<<<<<<<<<<<<<<<<<<<<

;NOTE---------------
;First of all, the bottom left square is not (0 0 N). It is (1 10 N), 
;and any mention otherwise will be corrected by helper functions.
;I know, it's awful, but we're all happy.
;Secondly, do you know how stupid this is? Even google doesn't have help. This is literally an iterative problem.
;No one does this.-

;test value and idea section---------
	;Hardcode of goal locations and costs
	;(define goal-20 (list '(5 10 980)))
	;(define goal-100 (list '(3 5 900)))
	;(define goal-1000 (list '(8 5 0)))
	(define testopen (list '("MOVE-1" 10 (0 0 N) 10 0)
						   '("MOVE-2" 15 (0 0 N) 15 0)
						   '("MOVE-3" 1 (0 0 N) 18 0)
						   '("TURN-LEFT" 5 (0 0 N) 5 0)
						   '("TURN-RIGHT" 5 (0 0 N) 5 0)
						   ))
	(define testresult (car (list '("TURN-LEFT" 10 '(5 8 S) 5 200 "STAY" "MOVE" "MOVE" "MOVE" "MOVE"))))
	;(define open (list))
	(define (expandL) (default-left '(1 10 N) (find-smallest-act open)))
	(define (expandR) (default-right '(1 10 N) (find-smallest-act open)))
	(define (expand1) (move-1 '(1 10 N) (find-smallest-act open)))
	(define (expand2) (move-2 '(1 10 N) (find-smallest-act open)))
	(define (expand3) (move-3 '(1 10 N) (find-smallest-act open)))
	(define (exp-tst) (begin (display (expandL))(newline)(display (expandR))(newline)(display (expand1))(newline)
							 (display (expand2))(newline)(display (expand3))(newline)))
	;when call a* you call helper that runs thru the whole percept looking for goals
	;and then it puts the goals in some list, and heuristic-function will do its magic on the list
;------------------------------------

;Coat-check - leaves your API at the door, makes my code get along with requirements
(define (fix-state state) ;creates 1-10 form of state from API 0-0 form
  		(replace-nth-item 1 (replace-nth-item 2 state (- 10 (nth-item 2 state))) (+ 1 (nth-item 1 state))))
(define (un-fix state) ;reversed fix-state
	    (replace-nth-item 1 (replace-nth-item 2 state (- 10 (nth-item 2 state))) (- (nth-item 1 state) 1)))



;A* implementation    Welcome to the Thunderdome
(define (a*-tree-search percept energy)
  		;Begin by generating the initiail state: x y direction
		;pass into myA* starting location, given energy, default open list, and percept
  		(myA* '(0 0 N) energy open percept))

;end state actions
(define (end-state result energy)
  		(cond ( (null? result) #f) ;null list indicates no goal found
			  ( (> 0 (- energy (nth-item 5 result))) #f) ;if difference isnt positive, ran out of energy
			  (#t (begin (display ">>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<")(newline)
						 (display ">>>>>>>>>>>>>>>/-/<<<<<<<<<<<<<<<")(newline)  ;i needed a break
						 (display ">>>>>>>>>>>>>>/v/<<<<<<<<<<<<<<<<")(newline)
						 (display ">>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<")(newline)
						 (display "Performed with energy remaining:")
						 (display (- energy (nth-item 5 result))) 
						 (newline)
						 (display "Path: ")
						 (display (cdr (history result)))(newline)
						 (display ">>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<")(newline)
						 (display ">>>>>>>>>>>>>>>>/^/<<<<<<<<<<<<<<")(newline)
						 (display ">>>>>>>>>>>>>>>/-/<<<<<<<<<<<<<<<")(newline)
						 (display ">>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<")
						 (newline)))))
						 ;this needs to have the most recent move added to open
						 ;it will be a turn expanded while at the goal. hence turns are default

;default/starting open list
(define open (list '("STAY" 0 (0 0 N) 0 0)))
;open list more or less contains edges and nodes.
;a move knows it's A*value, and remembers the location it will have moved from so that state
;can be altered appropriately, as well as the move history from which it was expanded
;parent-cost+cost-of-moving updates spent_energy
;Nonsense API (("movement" A*value (x y direction) cost accum_cost) "previous" "previous"...)

;This is the center of the tootsie pop
(define (myA* state energy open percept)
  		;initial state will be altered based on the moves chosen from open list
		;open will eat memory every time it's passed into the recursion.it will grow, copy itself into the
		;next instance of myA*, grow again, and repeat. this is the worst. R.I.P. memory R.I.P. time
		
		;resused variables
		(let ((start (fix-state (action-from (find-smallest-act open)))) ;start is made from the chosen movement
			  (choice (find-smallest-act open)))						 ;choice is smallest action in open list

		;Algorithm
		(cond ((null? open) (end-state (list) energy)) ;base case: FAIL
			  ((is-goal (fix-state state)) (end-state (car (list-tail open (- (length open) 1))) energy)) ;base case: SUCCESS
			  										  ;passes in last item in the open list. looks odd b/c of way list-tail works.
			  ;perform recursion
			  ((#t (myA* ;update state by taking an action
					 	 (un-fix (apply-action start (car (choice))))
						 ;pass energy along
						 energy
						 ;pass in updated open list
						 (append ;remove taken action
						   		 (remove-action open choice)
								 ;turn left and right available by default
								 (list (default-left start choice))
								 (list (default-right start choice))
								 ;expand forward movement - success depends on obstacles
								 (list (move-1 start choice))
								 (list (move-2 start choice))
								 (list (move-3 start choice)))
						 ;pass percept along
						 percept))))
		))


;-----------
;A* helpers
;-----------

;Big Kahuna of A* Helpers
;A*value function
(define (A-val state previous percept)
  		(+ (heuristic-function percept state) (path-sum previous)))

;Heuristic function
(define (heuristic-function percept state)
		(find-smallest (get-hvals percept state (get-goals percept) (car (cdr (max-gain (get-goals percept)))))))

;recursively go through goal states to apply heuristic calculation helper funciton
(define (get-hvals percept state glist gain)
  		(if (null? (cdr glist))
		  	(H-val percept state (car glist) gain)
			(list (append (H-val percept state (car glist) gain)
						  (get-hvals percept state (cdr glist) gain)))))

;body helper function. does heuristic calculation on a goal, intended for map function
(define (H-val percept state goal gain)
  	(+ (* 6 (+ (abs (- (nth-item 1 state) (nth-item 1 (get-coords goal percept))))
			   (abs (- (nth-item 2 state) (nth-item 2 (get-coords goal percept))))))
	   (- gain (car (cdr goal)))
	   (cond ((and (< 0 (abs (- (nth-item 1 state) (nth-item 1 (get-coords goal percept)))))
				   (< 0 (abs (- (nth-item 2 state) (nth-item 2 (get-coords goal percept))))))
			  5)
			 (#t 0))))
		  
;helper function gets coordinates by finding which row a goal is a member of. this gives y value.
;member returns a list of the goal and the remaining members of the list thereafter, so if i take the
;length of that, subtract it from 10, and add 1, i get the x value. result is in 1-10 form.
;expects a single goal at a time.
(define (get-coords alist percept)
		(if (not (null? alist))
		  	(cond ( (member alist (nth-item 1 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 1 percept))))) 1 'N)
					)
				  ( (member alist (nth-item 2 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 2 percept))))) 2 'N)
					)
				  ( (member alist (nth-item 3 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 3 percept))))) 3 'N)
					)
				  ( (member alist (nth-item 4 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 4 percept))))) 4 'N)
					)
				  ( (member alist (nth-item 5 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 5 percept))))) 5 'N)
					)
				  ( (member alist (nth-item 6 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 6 percept))))) 6 'N)
					)
				  ( (member alist (nth-item 7 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 7 percept))))) 7 'N)
					)
				  ( (member alist (nth-item 8 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 8 percept))))) 8 'N)
					)
				  ( (member alist (nth-item 9 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 9 percept))))) 9 'N)
					)
				  ( (member alist (nth-item 10 percept))
				    (list (+ 1 (- 10 (length (member alist (nth-item 10 percept))))) 10 'N)
					)
				  )))
						
;helper function filters out goals because the goals are lists. then append those lists.
;meant to be fed to get-coords
(define (get-goals percept)
  		(append (filter list? (nth-item 1 percept))
				(filter list? (nth-item 2 percept))
				(filter list? (nth-item 3 percept))
				(filter list? (nth-item 4 percept))
				(filter list? (nth-item 5 percept))
				(filter list? (nth-item 6 percept))
				(filter list? (nth-item 7 percept))
				(filter list? (nth-item 8 percept))
				(filter list? (nth-item 9 percept))
				(filter list? (nth-item 10 percept))))

;returns accum_cost of travel to state for which A*value is being calculated. gets added to H-val,
;accounts for all edges (costs) between nodes
(define (path-sum previous)
		(nth-item 5 previous))		

;helper funciton finds goal with highest goal value for later calculation of goal costs. helps choose
;goal_cost = |max_gain - goal_gain|
;use cdr to extract value
(define (max-gain alist)
		;Base case: one element in list
		(cond ((null? (cdr alist)) (car alist))
			  ;compate first elt with rest, see if there's bigger gain
			  ((> (nth-item 2 (car alist)) (nth-item 2 (max-gain (cdr alist)))) (car alist))
			  ;otherwise it's something in the rest of alist with max-gain
			  (else (max-gain (cdr alist)))))
	


;this series of helpers is for expanding the frontier
;each pass in start and previous action taken from open list 
;L
(define (default-left start previous)
  		(append (
				 ;movement
				 list "TURN-LEFT"
				 ;A*value
				 (+ 5 (heuristic-function percept (apply-action start "TURN-LEFT")))
				 ;(x y direction)
				 (un-fix start)
				 ;cost
				 5
				 ;acucm_cost
				 (+ 5 (nth-item 5 previous))
				 ;history
				 (gen-history previous)
				 )))
;R
(define (default-right start previous)
		(append (
				 ;movement
				 list "TURN-RIGHT"
				 ;A*value
				 (+ 5 (heuristic-function percept (apply-action start "TURN-LEFT")))
				 ;(x y direction
				 (un-fix start)
				 ;cost
				 5
				 ;accum_cost
				 (+ 5 (nth-item 5 previous))
				 ;history
				 (gen-history previous)
				 )))
;1-3 only activate if valid
;1
(define (move-1 start previous)
  		(if (valid-path start (apply-action start "MOVE-1"))
		  	(append (
					 ;movement
					 list "MOVE-1"
					 ;A*value
					 (+ 10 (heuristic-function percept (apply-action start "MOVE-1")))
					 ;(x y directon)
					 (un-fix start)
					 ;cost
					 10
					 ;accum_cost
					 (+ 10 (nth-item 5 previous))
					 ;history
					 (gen-history previous)
					 ))))
;2 
(define (move-2 start previous)
  		(if (valid-path start (apply-action start "MOVE-2"))
		  	(append (
					 ;movement
					 list "MOVE-2"
					 ;A*value
					 (+ 15 (heuristic-function percept (apply-action start "MOVE-2")))
					 ;(x y direction)
					 (un-fix start)
					 ;cost
					 15
					 ;accum_cost
					 (+ 15 (nth-item 5 previous))
					 ;history
					 (gen-history previous)
					 ))))
;3
(define (move-3 start previous)
  		(if (valid-path start (apply-action start "MOVE-3"))
		  	(append (
					 ;movement
					 list "MOVE-3"
					 ;A*value
					 (+ 15 (heuristic-function percept (apply-action start "MOVE-3")))
					 ;(x y direction)
					 (un-fix start)
					 ;cost
					 15
					 ;accum_cost
					 (+ 15 (nth-item 5 previous))
					 ;history
					 (gen-history previous)
					 ))))


;helper function expands history onto action 
(define (gen-history previous)
		(if (not (null? (history previous))) ;if history is present       <- see that? that is funny.
		 		 (append (history previous) (car previous)) ;append previous action onto history, and that gets passed in
				 (car previous)) ;otherwise start history by passing in previous action. only happens at the very start of A*
		)

;helper function in 1-10 checks that the path for the moves are valid using a combiniation of state checks (see More Helpers below)
(define (valid-path start end)
  		(cond ( (not (and (equal? (nth-item 1 start) (nth-item 1 end)) (equal? (nth-item 2 start) (nth-item 2 end)))) ;if not at end
			    	 (cond ( (not (is-barrier start)) ;if valid
			  		 	     (valid-path (in-front start) end)) ;check next
			  		  	   (#t #f) ;else if invalid, return false
			  		  ))
			  ( (not (is-barrier start)) #t) ;else if at end, if end is valid, return true
			  (#t #f))) ;else return false



;>>>>>-<<<<<<
;More Helpers
;>>>>>-<<<<<<

;state check helpers. each operate in 1-10 form
(load "helpers.scm")
;loads the following helpers
;>(define (is-out state)...)
;>(define (is-barrier state)...)
;>(define (in-front state)...)
;>(define (is-goal state)...)
;>(define (history act)...)
;.define (action-from act)...)
;>(define (haich-func)...) broken heuristic function, used for testing
