;Evan Eberhardt
;2 May 16
;THIS CODE IS INCOMPLETE 
;The percept shown in the assignment file is hardcoded, the goals are hardcoded,
;and I need to make it track energy and path
;I CAN FIX THIS   I NEED MORE TIME   T_T
;
;Various helper functions from previous assignment, mildly modified for re-use, but essentially the same
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

(define (apply-action state action)
  		;determines result based on condition checks for the input, and uses display to show the result
		;"stay" just returns the original state
  		(cond ((equal? action "STAY") state)
			  ;each "move" checks the direction to determine whether to modify x or y, and how to modify it.
			  ;the funciton nth-item is used to check the direction in state against a dummy state with the corresponding direction
			  ;replace-nth-item is used to alter the correct value x or y
			  ((equal? action "MOVE-1")
			   (cond (  (equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))			
					    (replace-nth-item 2 state (- (car (cdr state)) 1)))
				;if facing north, add to y
				     ((equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
					  (replace-nth-item 2 state (+ (car (cdr state)) 1)))
				;if facing south, subtract from y
				      ((equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
					   (replace-nth-item 1 state (+ (car state) 1)))
				;if facing east, add to x
				      ((equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
					   (replace-nth-item 1 state (- (car state) 1)))
				;if facing west, subtract from x
				(newline)
			   )
			  ;same pattern for each "move"
			  ((equal? action "MOVE-2")
			   (begin (cond ((equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
					 		 (display (replace-nth-item 2 state (- (car (cdr state)) 2))))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 S))) 
					  		 (display (replace-nth-item 2 state (+ (car (cdr state)) 2))))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
					 		 (display (replace-nth-item 1 state (+ (car state) 2))))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
					 		 (display (replace-nth-item 1 state (- (car state) 2)))))
					 (newline))
			   )
			  ((equal? action "MOVE-3")
			   (begin (cond ((equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
					 		 (replace-nth-item 2 state (- (car (cdr state)) 3)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
					 		 (display (replace-nth-item 2 state (+ (car (cdr state)) 3))))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
					 		 (display (replace-nth-item 1 state (+ (car state) 3))))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
					 		 (display (replace-nth-item 1 state (- (car state) 3)))))
					 (newline))
			   )
			  ;similarly the turning commands require nth-item to check against a dummy state to determine 
			  ;which direction to face, and replace-nth-item is used to replace the correct value
			  ((equal? action "TURN-RIGHT")
			   (begin (cond ((equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
					 		 (display (replace-nth-item 3 state 'E)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
					 		 (display (replace-nth-item 3 state 'S)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
					 		 (display (replace-nth-item 3 state 'W)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
					  		 (display (replace-nth-item 3 state 'N))))
					 (newline))
			   )
			  ((equal? action "TURN-LEFT")
			   (begin (cond ((equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
					 		 (display (replace-nth-item 3 state 'W)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
					 		 (display (replace-nth-item 3 state 'S)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
					 		 (display (replace-nth-item 3 state 'E)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
					 		 (display (replace-nth-item 3 state 'N))))
					 (newline))
			   )
			  ((equal? action "TURN-AROUND")
			   (begin (cond ((equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
					 		 (display (replace-nth-item 3 state 'S)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
					 		 (display (replace-nth-item 3 state 'W)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
					 		 (display (replace-nth-item 3 state 'N)))
					 		((equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
					  	   	 (display (replace-nth-item 3 state 'E))))
					 (newline))
			   )
			  )))

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

;Begin Assignment 2 Main Algorithm Code

;NOTE
;First of all, the bottom left square is not (0 0 N). It is (1 10 N), 
;and any mention otherwise will be corrected by helper functions.
;I know, it's awful, but we're all happy.
;Secondly, do you know how stupid this is? Even google doesn't have help. This is literally an iterative problem.
;No one does this.

;test value and idea section---------
	;Hardcode goal locations and costs
	;(define goal-20 (list '(5 10 980)))
	;(define goal-100 (list '(3 5 900)))
	;(define goal-1000 (list '(8 5 0)))
	(define testopen (list '("MOVE-1" 10) '("MOVE-2" 15) '("MOVE-3" 1) '("TURN-LEFT" 5) '("TURN-RIGHT" 5) ))
	;(define open (list))

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
  		(cond ((null? result) #f) ;null list indicates no goal found
			  ((< 0 (- energy (nth-item 4 result))) #f) ;if difference isnt positive, ran out of energy
			  (#t (begin (display ("Performed with energy remaining:" (- energy (nth-item 4 result))))
						 (newline)
						 ;(display ("Path: "))
						 (cdr (cdr (cdr (cdr (cdr (cdr (result))))))))))) ;this needs to have the most recent move from open

;default open list
(define open (list '("STAY" 0 0 0 N 0))) ;open list more or less contains edges and nodes.
				  					   ;a move knows it's A*value, and remembers the location it will have moved from so that state
									   ;can be altered appropriately, as well as the move history from which it was expanded
									   ;parent-cost+cost-of-moving updates spent_energy
									   ;Nonsense API (("movement" cost x y direction spent_energy) "previous" "previous"...)

;This is the center of the tootsie pop
(define (myA* state energy open percept)
  		;initial state will be altered based on the moves chosen from open list
		;open will eat memory every time it's passed into the recursion.it will grow, copy itself into the
		;next instance of myA*, grow again, and repeat. this is the worst. R.I.P. memory R.I.P. time
		
		(let ((start (fix-state (action-from state (find-smallest-act open)))))  ;reused variable

		(cond ((null? open) (end-state (list) energy)) ;base case: FAIL
			  ((is-goal (fix-state state)) (end-state state energy)) ;base case: SUCCESS
			  ;perform recursion
			  ((#t (myA* ;update state
					 	 (apply-action start (car (find-smallest-act open)))
						 ;pass energy along
						 energy
						 ;pass in updated open list
						 (append (remove-action open (find-smallest-act open))
								 ("TURN-LEFT" (+ 5 (heuristic-function percept start)) (un-fix(apply-action start "TURN-LEFT"))) 
								 ("TURN-RIGHT" (+ 5 (heruistic-function percept start)) (un-fix(apply-action start "TURN-RIGHT")))
								 (cond ((valid-path start (apply-action start "MOVE-1"))
										(list '("MOVE-1" (+ 10 (heuristic-function percept (apply-action start "MOVE-1")))
												(un-fix (apply-action start "MOVE-1"))))))
								 (cond ((valid-path start (apply-action start "MOVE-2"))
										(list '("MOVE-2" (+ 15 (heuristic-function percept (apply-action start "MOVE-2")))
												(un-fix (apply-action start "MOVE-2"))))))
								 (cond ((valid-path start (apply-action start "MOVE-3"))
										(list '("MOVE-3" (+ 18 (heuristic-function percept (apply-action start "MOVE-3")))
												(un-fix (apply-action start "MOVE-3")))))))
						 ;pass percept along
						 percept))))
		))
		

			  
;A* helpers
;helper function checks that the path for the moves are valid
(define (valid-path start end)
  		(cond ((and (equal? (nth-item 1 start) (nth-item 1 end)) (equal? (nth-item 2 start) (nth-item 2 start))) #t)
		  	  ((and (not (is-barrier (in-front start))) (not (is-out (in-front start)))) (valid-path (in-front start) end))
			  (#t #f)))

;helper function applies onto state the location from which an aciton was done
(define (action-from state new)
  		(replace-nth-item 3 (replace-nth-item 2 (replace-nth-item 1 state
												(nth-item 3 new)) (nth-item 4 new)) (nth-item 5 new)))


;Heuristic-function takes state and percept and returns heuristic value of any location on the grid
(define (heuristic-function percept state)
  		;find the difference in the x values and the difference in the y values between state and goal
		;take the absolute value of each and then sum them
		;multiply by six because the least a movement will cost is 6/square if move-3 is used exclusively
		;that is optimism right there
		;take that product and add it to the cost of the goal
		;if both the difference in x values and y values between state and goal are not zero, 
		;then theres at least one turn add 5,
		;otherwise optimistically assume youre facing the goal, so no turns, add 0 
		;put those values in a list and call find-smallest on the list
		;boom, heuristic
		(find-smallest (list
							;goal 20
						 	(+ (* 6 (+ (abs (- (nth-item 1 state) 5)) ;(nth-item 1 goal-20)))
									   (abs (- (nth-item 2 state) 10)))) ;(nth-itme 2 goal-20)))))
							   ;(nth-item 3 goal-20)
							   980
							   (cond ((and (< 0 (abs (- (nth-item 1 state) 5))) ;(nth-item 1 goal-20))))
										   (< 0 (abs (- (nth-item 2 state) 10)))) ;(nth-item 2 goal-20)))))
									  5)
									 (#t 0)))
							;goal 100
							(+ (* 6 (+ (abs (- (nth-item 1 state) 3)) ;(nth-item 1 goal-100)))
									   (abs (- (nth-item 2 state) 5)))) ;(nth-item 2 goal-100)))))
							   ;(nth-item 3 goal-100)
							   900
							   (cond ((and (< 0 (abs (- (nth-item 1 state) 3))) ;(nth-item 1 goal-100))))
										   (< 0 (abs (- (nth-item 2 state) 5)))) ;(nth-item 2 goal-100)))))
									  5)
									 (#t 0)))
							;goal 1000
							(+ (* 6 (+ (abs (- (nth-item 1 state) 8)) ;(nth-item 1 goal-1000)))
									   (abs (- (nth-item 2 state) 5)))) ;(nth-item 2 goal-1000)))))
							   ;(nth-item 3 goal-1000)

							   (cond ((and (< 0 (abs (- (nth-item 1 state) 8))) ;(nth-item 1 goal-1000))))
										   (< 0 (abs (- (nth-item 2 state) 5)))) ;(nth-item 2 goal-1000)))))
									  5)
									 (#t 0)))


							)))

;state check helpers
(define (is-goal state) ;check if goal
  		(cond ((and (= 5 (nth-item 1 state)) (= 10 (nth-item 2 state))) #T)
			  ((and (= 3 (nth-item 1 state)) (= 5 (nth-item 2 state))) #T)
			  ((and (= 8 (nth-item 1 state)) (= 5 (nth-item 2 state))) #T)
			  (#t #f)))

(define (is-barrier state) ;check if barrier
  		(cond ((equal? (get-location state) (nth-item 1 '(barrier))) #t)
			  (#t #f)))

(define (is-out state) ;check if out of bounds: x or y will not be within 1 and 10
	   (cond ((<= 0 (nth-item 1 state)) #t)
			 ((<= 0 (nth-item 2 state)) #t)
			 ((> 10 (nth-item 1 state)) #t)
			 ((> 10 (nth-item 2 state)) #t)
			 (#t #f)))

(define (in-front state) ;returns the state in front of me
  		(cond ((equal? (nth-item 3 state) (nth-item 3 '(0 0 N)))
			   (replace-nth-item 2 state (- (nth-item 2 state) 1)))
			  ((equal? (nth-item 3 state) (nth-item 3 '(0 0 S)))
			   (replace-nth-item 2 state (+ (nth-item 2 state) 1)))
			  ((equal? (nth-item 3 state) (nth-item 3 '(0 0 E)))
			   (replace-nth-item 1 state (- (nth-item 1 state) 1)))
			  ((equal? (nth-item 3 state) (nth-item 3 '(0 0 W)))
			   (replace-nth-item 1 state (+ (nth-item 1 state) 1)))))

