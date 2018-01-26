;Evan Eberhardt

;Initializations
(define (initialize-agent) "ok")
(define chart (list)) ;map of interesting things
;(define boundaries (list)) ;map of edge of world
(define veg-types (list)) ;different types of vegetation and their recorded maximum bloom
;(define threats (list)) ;list of agents and predators
(define location '(0 0 N))
;(define origin '(0 0)) ;locations from which surrounding info was gathered
;(define spin-ctr 0) ;keeps track of spinning to gather info
(define turn-ctr 0)
(define desire "explore") ;determines goal of actions
(define mood "peaceful") ;determines goal of actions
(define target (list)) ;target location to move to
(define forced-move (list)) ;used for getting out of an obstacles way
(define desire-ctr 25) ;number of turns before desire changes

;choose-action
(define (choose-action current-energy previous-events percepts)
  (begin (view percepts -1 1) ;record interesting things in chart
		 ;decide what the next desire is
		 (choose current-energy previous-events percepts)
		 ;decide what to do based on desire
		 (cond ((equal? desire "eat") (eat current-energy previous-events percepts)) ;
			   ((equal? desire "explore") (explore percepts)) ;
			   ((equal? desire "target") (seek-target)) ;
			   )))

;--------------
;View + helpers
;--------------
(define (view percepts x y)
  ;check if theres remaining space to look through
  (cond ((> y 5) "ok")
		((> x y) (view percepts (- 0 (+ 1 y)) (+ 1 y)))
		((list? (get-location percepts x y))
		 ;add interesting things into chart (lists)
		   (begin (set! chart (cons (list (get-location percepts x y) (x-loc x y) (y-loc x y)) chart))
				  ;if they are vegetation, add them to the veg-types list with is-new?
				  (if (equal? (nth-item 1 (get-location percepts x y)) 'vegetation)
					(is-new? (get-location percepts x y))
					)
				  ;search remainder
				  (view percepts (+ 1 x) y)))
		(#t (view percepts (+ 1 x) y))))

;convert location in percept to coordinates relative to location
(define (x-loc x y)
  (cond ((equal? (nth-item 3 location) 'N) (+ x (nth-item 1 location)))
		((equal? (nth-item 3 location) 'W) (- (nth-item 1 location) y))
		((equal? (nth-item 3 location) 'S) (- (nth-item 1 location) x))
		((equal? (nth-item 3 location) 'E) (+ (nth-item 1 location) y))))

;convert location in percept to coordinates relative to location
(define (y-loc x y)
  (cond ((equal? (nth-item 3 location) 'N) (+ y (nth-item 2 location)))
		((equal? (nth-item 3 location) 'W) (+ x (nth-item 2 location)))
		((equal? (nth-item 3 location) 'S) (- (nth-item 2 location) y))
		((equal? (nth-item 3 location) 'E) (- (nth-item 2 location) x))))

;adds a vegetation into the veg-types list if it's new
(define (is-new? vegetation)
  (if (equal? (present-idx vegetation) 0)
	;update if brand new
	 (set! veg-types (cons vegetation veg-types))
	 (if (> (nth-item 3 vegetation) (nth-item 3 (nth-item (present-idx vegetation) veg-types)))
	   ;update and replace if new, higher bloom value discovered
	   (set! veg-types (replace-nth-item (present-idx vegetation) veg-types vegetation)))))

;checks if a vegetation is already present in the list
(define (present-idx vegetation)
  (check-veg vegetation 1 veg-types))
(define (check-veg vegetation n vlist)
  (cond ((null? vlist) 0)
		((equal? (nth-item 2 vegetation) (nth-item 2 (car vlist))) n)
		(#t (check-veg vegetation (+ n 1) (cdr vlist)))))

;-------------
;Eat + helpers
;-------------

;eat: simple decision tree,
(define (eat energy prev percepts)
  (if (equal? (nth-item 3 (best-veg veg-types)) (nth-item 3 (get-location percepts 0 1)))
	"EAT-AGGRESSIVE"
	(if (and (not (list? (get-location percepts -1 1)))
			 (not (list? (get-location percepts 1 1)))
		     (not (list? (get-location percepts 0 2))))
	  "STAY"
	  (cond ((weaker-agent? (get-location percepts -1 1) energy) (attack (x-loc -1 1) (y-loc -1 1) E energy prev percepts))
			((weaker-agent? (get-location percepts 1 1) energy) (attack (x-loc 1 1) (y-loc 1 1) W  energy prev percepts))
			((weaker-agent? (get-location percepts 0 2) energy) (attack (x-loc 0 2) (y-loc 0 2) S energy prev percepts))
			(#t "EAT-PASSIVE")))))

;finds vegetation in list with highest value
(define (best-veg vlist)
  ;base case: first
  (cond ((null? (cdr vlist)) (car vlist))
		;else compare with rest of list
		((> (nth-item 3 (car vlist)) (nth-item 3 (best-veg (cdr vlist)))) (car vlist))
		;else search rest of list
		(else (best-veg (cdr vlist)))))

;compares range of enemy's possible energy values to range from my energy to their maximum energy
(define (weaker-agent? agent energy)
  (if (not (equal? (nth-item 1 agent) 'agent))
	#f
	;generates a probablility. 85% chance or higher that i am stronger is acceptable
	(if (> (/ (+ 1 (- (max-energy agent) energy)) (+ 1 (- max-energy min-energy))) 0.84)
	  #t
	  #f)))

;max energy is observed energy+1, set to a power of two. this is in case floor was used
(define (max-energy agent)
  (expt 2 (+ (nth-item 3 agent) 1)))

;min enbergy is obesrved energy-1, set to a power of two. this is in case celieing was used
(define (min-energy agent)
  (expt 2 (- (nth-item 3 agent) 1)))

;changes mood, target, and action to guard the food in front of me from competitors i'm stringet than
(define (attack x y D energy prev percepts)
  (begin (set! mood "aggressive")
		 (set! target (cons '(x y D) target))
		 (set! desire "target")
		 (seek-target)))



;-----------------
;Explore + helpers
;-----------------

;explore: randomly pick actions, turn away from threats or barriers
(define (explore percepts)
  (cond ((predator-front percepts) (face-L))
		((barrier-front percepts) (face-L))
		(#t (let ((rand (random 12)))
			  (cond ((equal? rand 0) (face-R))
					((equal? rand 1) (face-L))
					((equal? rand 2) (face-A))
					((> rand 9) "MOVE-PASSIVE-3")
					((> rand 6) "MOVE-PASSIVE-2")
					((> rand 3) "MOVE-PASSIVE-1"))))))

;returns true of theres a predator in front of agent
(define (predator-front percepts)
  (if (equal? (nth-item 1 (object-front 1 percepts)) 'predator) #t #f))

;returns true if theres a barrier in front of agent
(define (barrier-front percepts)
  (if (equal? (nth-item 1 (object-front 1 percepts)) 'barrier) #t #f))

;detects objects directly in front of me
(define (object-front n percepts)
  (if (> n 5) '(empty)
	(cond ((list? (get-location percepts 0 n)) (get-location percepts 0 n))
		  ((equal? (get-location percepts 0 n) 'barrier) (list (get-location percepts 0 n)))
		  (#t (object-front (+ 1 n) percepts)))))

;----------------
;Target + helpers
;----------------

;target: seek given point
(define (seek-target)
  ;move along x
  (cond ((not (equal? (nth-item 1 location) (nth-item 1 (car target)))) (move-x))
		;move along y
		((not (equal? (nth-item 2 location) (nth-item 2 (car target)))) (move-y))
		;rotate to correct value
		((not (equal? (nth-item 3 location) (nth-item 3 (car target)))) (move-D))))

;face correct direction depending on whether target x value is west or east of me, then move forward along x
(define (move-x)
  (cond ((> (nth-item 1 location) (nth-item 1 (car target)))
		 (if (not (equal? (nth-item 3 location) 'W))
		   (cond ((equal? (nth-item 3 location) 'N) (face-L))
				 ((equal? (nth-item 3 location) 'E) (face-A))
				 ((equal? (nth-item 3 location) 'S) (face-R)))
		   (forward-x)))
		((< (nth-item 1 location) (nth-item 1 (car target)))
		 (if (not (equal? (nth-item 3 location) 'E))
		   (cond ((equal? (nth-item 3 location) 'S) (face-L))
				 ((equal? (nth-item 3 location) 'W) (face-A))
				 ((equal? (nth-item 3 location) 'N) (face-R)))
		   (forward-x)))))

;tiny decision tree
(define (forward-x)
		   (cond ((equal? 1 (delta-x))
				  (if (equal? mood "peaceful") "MOVE-PASSIVE-1" "MOVE-AGGRESSIVE-1"))
				 ((equal? 2 (delta-x))
				  (if (equal? mood "peaceful") "MOVE-PASSIVE-2" "MOVE-AGGRESSIVE-2"))
				 (#t
				  (if (equal? mood "peaceful") "MOVE-PASSIVE-3" "MOVE-AGGRESSIVE-3"))))

;face correct direction depending on whether target y value is north or south of me, then move forward along y
(define (move-y)
  (cond ((> (nth-item 2 location) (nth-item 2 (car target)))
		 (if (not (equal? (nth-item 3 location) 'S))
		   (cond ((equal? (nth-item 3 location) 'W) (face-L))
				 ((equal? (nth-item 3 location) 'N) (face-A))
				 ((equal? (nth-item 3 location) 'E) (face-R)))
		   (forward-y)))
		((< (nth-item 2 location) (nth-item 2 (car target)))
		 (if (not (equal? (nth-item 3 location) 'N))
		   (cond ((equal? (nth-item 3 location) 'E) (face-L))
				 ((equal? (nth-item 3 location) 'S) (face-A))
				 ((equal? (nth-item 3 location) 'W) (face-R)))
		   (forward-y)))))

;tiny decision tree
(define (forward-y)
  			(cond ((equal? 1 (delta-y))
				   (if (equal? mood "peaceful") "MOVE-PASSIVE-1" "MOVE-AGGRESSIVE-1"))
				  ((equal? 2 (delta-y))
				   (if (equal? mood "peaceful") "MOVE-PASSIVE-2" "MOVE-AGGRESSIVE-2"))
				  (#t
				   (if (equal? mood "peaceful") "MOVE-PASSIVE-3" "MOVE-AGGRESSIVE-3"))))

;rotates direction depending where i'm facing - just a decision tree
(define (move-D)
	(cond ((equal? (nth-item 3 (car target)) 'N)
		   (cond ((equal? (nth-item 3 location) 'E) (face-L))
				 ((equal? (nth-item 3 location) 'S) (face-A))
				 ((equal? (nth-item 3 location) 'W) (face-R))))
		  ((equal? (nth-item 3 (car target)) 'E)
		   (cond ((equal? (nth-item 3 location) 'S) (face-L))
				 ((equal? (nth-item 3 location) 'W) (face-A))
				 ((equal? (nth-item 3 location) 'N) (face-R))))
		  ((equal? (nth-item 3 (car target)) 'S)
		   (cond ((equal? (nth-item 3 location) 'W) (face-L))
				 ((equal? (nth-item 3 location) 'N) (face-A))
				 ((equal? (nth-item 3 location) 'E) (face-R))))
		  ((equal? (nth-item 3 (car target)) 'W)
		   (cond ((equal? (nth-item 3 location) 'N) (face-L))
				 ((equal? (nth-item 3 location) 'E) (face-A))
				 ((equal? (nth-item 3 location) 'S) (face-R))))))

;updates location with correct facing value and returns the command to turn
(define (face-L)
  (begin (cond ((equal? (nth-item 3 location) 'N)
				(set! location (replace-nth-item 3 location 'W)))
			   ((equal? (nth-item 3 location) 'E)
				(set! location (replace-nth-item 3 location 'N)))
			   ((equal? (nth-item 3 location) 'S)
				(set! location (replace-nth-item 3 location 'E)))
			   ((equal? (nth-item 3 location) 'W)
				(set! location (replace-nth-item 3 location 'S))))
		 "TURN-LEFT"))

;same as above
(define (face-R)
  (begin (cond ((equal? (nth-item 3 location) 'N)
				(set! location (replace-nth-item 3 location 'E)))
			   ((equal? (nth-item 3 location) 'E)
				(set! location (replace-nth-item 3 location 'S)))
			   ((equal? (nth-item 3 location) 'S)
				(set! location (replace-nth-item 3 location 'W)))
			   ((equal? (nth-item 3 location) 'W)
				(set! location (replace-nth-item 3 location 'N))))
		 "TURN-RIGHT"))

;same as above
(define (face-A)
  (begin (cond ((equal? (nth-item 3 location) 'N)
				(set! location (replace-nth-item 3 location 'S)))
			   ((equal? (nth-item 3 location) 'E)
				(set! location (replace-nth-item 3 location 'W)))
			   ((equal? (nth-item 3 location) 'S)
				(set! location (replace-nth-item 3 location 'N)))
			   ((equal? (nth-item 3 location) 'W)
				(set! location (replace-nth-item 3 location 'E))))
		 "TURN-AROUND"))

;these are self explanatory
(define (delta-x)
  (abs (- (nth-item 1 location) (nth-item 1 (car target)))))

(define (delta-y)
  (abs (- (nth-item 2 location) (nth-item 2 (car target)))))


;----------------
;Choose + helpers
;----------------

;choose: changes desire based on environment and a timer- timer resets for a new desire
(define (choose energy prev percepts)
  ;use prev to update location, desire counter, turn counter, target
  (begin (set! turn-ctr (+ 1 turn-ctr))
		 (update-loc prev)
		 (check-target)
		 (set! desire-ctr (- desire-ctr 1))
		 ;switch mood after a battle - if unsucessful battle, force desire to change
		 (calm-down prev)
  ;check forced move list for getting out of the way
  		 (cond ((and (moved-0 prev) (not (empty-front percepts))) (evasive-move))
			   ((not (null? forced-move)) (car forced-move))
			   ;detect food to pick "eat" desire
			   ((and (> desire-ctr 0) food-front percepts) (set-desire "eat"))
			   ;detect timer to pick "explore" desire or "target" desire
			   ;if there is a target and it hasn't been reached, desire doesn't change from "target"
			   ((and (null? target) (> 1 desire-ctr))
				(if (not (equal? desire "explore")) 
				  ;choose explore if not exploring already
				  (set-desire "explore")
				  ;choose target if not seeking target already
				  (set-target))))))

;updates location based on spaces moved
(define (update-loc prev)
  ;as long as the move data is there, moved >=0 spaces, else no change
  (if (not (null? (find-history 'moved prev)))
	;get the number of moved spaces
	(let ((delta (nth-item 2 (find-history 'moved prev))))
	  ;update coordinate in location according to direction facing
	  (cond ((equal? (nth-item 3 location) 'N) (replace-nth-item 2 location (+ (nth-item 2 location) delta)))
			((equal? (nth-item 3 location) 'E) (replace-nth-item 1 location (+ (nth-item 1 location) delta)))
			((equal? (nth-item 3 location) 'S) (replace-nth-item 2 location (- (nth-item 2 location) delta)))
			((equal? (nth-item 3 location) 'W) (replace-nth-item 1 location (- (nth-item 1 location) delta)))))))

;finds particular lists in previous events e.g. (moved spaces) list in previous events
(define (find-history srch plist)
  ;base case: plist is empty or first item is the desired item
  (cond ((null? plist) (list))
		((equal? (nth-item 1 (car plist)) srch) (car plist))
		;otherwise, look in rest of plist
		(#t (find-history srch (cdr plist)))))

;after a fight, switches mood back to passive. if unsuccessful, forces timer to 0 and target to () so desire changes
(define (calm-down prev)
  ;if mood is aggressive and a fight happened last turn
  (if (and (equal? mood "aggressive") (not (null? (find-history 'fought prev))))
	;if agent moved 0 spaces, fight was lost, run away
	(if (moved-0 prev)
	  (begin (set! desire-ctr 0)
			 (set! target (list))
			 (set! mood "peaceful"))
	  ;else agent won and can just set to peaceful
	  (set! mood "peaceful"))))

;sets target to null if target was reached
(define (check-target)
  (if (equal? location (car target)) (set! target (list))))

;returns true if zero spaces were moved last turn
(define (moved-0 prev)
  (if (equal? (nth-item 2 (find-history 'moved prev)) 0) #t #f))

;return true if the space in front of the agent is "empty"
(define (empty-front percepts)
  (if (equal? (get-location percepts 0 1) 'empty) #t #f))

;return true if the space in front of the agent is a vegetation
(define (food-front percepts)
  (if (list? (get-location percepts 0 1))
	(if (equal? (get-location percepts 0 1) 'vegetation) #t #f)
	#f))

;loads the forced-move list with a few moves to get out of the way of an obstacle
;always ends facing the same way as started
(define (evasive-move)
  (begin (set! forced-move (cons "MOVE-PASSIVE-1" forced-move))
		 (set! forced-move (cons "TURN-RIGHT" forced-move))
		 (set! forced-move (cons "MOVE-PASSIVE-1" forced-move))
		 (set! forced-move (cons "TURN-LEFT" forced-move))))

;sets desire to passed in phrase, sets timer to default 25 if this is a new change
;not a necessary call from attack function b/c food is either safe 25 consecutive turns or agent gets scared away
(define (set-desire change)
  ;change is a new desire
  (begin (if (not (equal? desire change)) (set! desire-ctr 25))
		 ;desire updated regardless
		 (set! desire change)))

;finds location to go to to eat the best vegatable seen so far
;sets target to those coordinates
;calls set-desire to change to target
(define (set-target)
  ;get plant coordinates
  (let ((loc (get-plant-loc (best-veg veg-types))))
			;agent is to the left of the vegetation
			(cond ((> (nth-item 1 loc) (nth-item 1 location))
				   ;make sure target is null, then set X, Y, and direction
				   (begin (set! target (list))
	                      (set! target (cons (list (- (nth-item 1 loc) 1) (nth-item 2 loc) 'E) target))
						  (set-desire "target")))
				  ;agent is to the right of the vegetation
				  ((> (nth-item 1 location) (nth-item 1 loc))
				   ;make sure target is null, then set x, y, and direction
				   (begin (set! target (list))
						  (set! target (cons (list (+ (nth-item 1 loc) 1) (nth-item 2 loc) 'W) target))
						  (set-desire "target")))
				  ;agent is right above the vegetation
				  ((> (nth-item 2 location) (nth-item 2 loc))
				   ;make sure target is null, set x, y, direction
				   (begin (set! target (list))
						  (set! target (cons (list (nth-item 1 loc) (+ (nth-item 2 loc) 1) 'S) target))
						  (set-desire "target")))
				  ;agent is right below the vegetation
				  ((> (nth-item 2 loc) (nth-item 2 location))
				   ;same deal
				   (begin (set! target (list))
						  (set! target (cons (list (nth-item 1 loc) (- (nth-item 2 loc) 1) 'N) target))
						  (set!-desire "target")))
				  ;if none of these are true, there are no known vegetations.
				  ;default target ends up being the agents own location
				  (#t location))))

;returns x and y coordinates of the nearest vegetation of the best type seen so far
;done with helper functions on both x and y
(define (get-plant-loc veg)
  ;search-chart returns false if there is something to search. if not, return agent's location
  (if (search-chart veg chart (list))
	  (list (nth-item 2 (nearest (search-chart veg chart (list)))) 
			(nth-item 3 (nearest (search-chart veg chart (list)))))
	  location))

;searches chart to return a list of vegetation and their location. looks for vegetation that matches searched type
(define (search-chart veg clist answer)
  ;make sure clist is not null at the same time as answer -> nothing to search 
  (if (and (null? clist) (null? answer)) #f
	;base case: answer has values and clist is empty from search, return anser
	(cond ((and (null? clist) (not (null? answer))) answer)
		  ;base case: first item matches
		  ((equal? (nth-item 2 veg) (nth-item 2 (car (car clist))))
				   ;search rest of clist with updated answer
				   (search-chart veg (cdr clist) (cons (car clist) answer)))
		  ;base case false, search rest of clist
		  (#t (search-chart veg (cdr clist) answer)))))

;returns ((vegetation id energy) x y) of closest vegetation in list returned by search-chart
(define (nearest vlist)
  ;base case: 
  ;base case: only one item in list
  (cond ((null? (cdr vlist)) (car vlist))
		;compare first element with rest, see if it's nearer
		((< (distance (car vlist)) (distance (nearest (cdr vlist)))) (car vlist))
		;otherwise theres something nearer in the rest of the list
		(else (nearest (cdr vlist))))) 

;calculates distance between location and vegetation
(define (distance vegatable)
  (+ ;sum
	;delta-x
	(+ (abs (nth-item 1 location)) (abs (nth-item 2 vegatable)))
	;delta-y
	(+ (abs (nth-item 2 location)) (abs (nth-item 3 vegatable)))))


	

;-------------
;Extra helpers
;-------------

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

(define (get-location percept x y)
		;The percept is made of y sublists where y=5, each with x elements where x varies from 3 to 11
		;since negative values are valid, and the offset depends on the y value, the index of the correct 
		;sublist can be found by the formula x=x+y+1. this formula determines which element of the sublist to choose.
		;which sublist to choose from depends on y
  		(nth-item (+ x y 1) (nth-item y (percept))))
		;nth-item is nested to return the correct value. it is called to find which element of a sublist to find,
		;which requires it to call itself for  which sublist fomr the percept string to find. the first call is x
		;and the inttermost call is y
