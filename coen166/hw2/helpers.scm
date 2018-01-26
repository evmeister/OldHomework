;>>>>>>>-<<<<<<<<
;Helper Functions
;>>>>>>>-<<<<<<<<

;check if state is out of bounds: x or y not within 0 and 10
(define (is-out state)
  		(cond ((>= 0 (nth-item 1 state)) #T)
			  ((>= 0 (nth-item 2 state)) #T)
			  ((< 10 (nth-item 1 state)) #T)
			  ((< 10 (nth-item 2 state)) #T)
			  (#T #F)))

;check if given state is a barrier
;a barrier cannot be out of bounds, so this performs both checks on if
;state is a barrier or out of bounds
(define (is-barrier state)
  		(if (not (is-out state))
		  	(cond ((equal? (get-location state) (nth-item 1 '(barrier))) #t)
				  (#T #F))
			(#t)))

;convenience helper gives space i'm facing
(define (in-front state) (apply-action state "MOVE-1"))

;check if given valid state is a goal. takes in state in 1-10 form, has second layer helper
(define (is-goal state)
  		(isagoal state (get-goals percept)))
(define (isagoal state alist)
  		(if (null? alist) #f ;if alist is null, no goals left  to compare
  		(let ( (goal (get-coords (car alist)))) ;reuse values

	  	(cond ((and (equal? (nth-item 1 state) (nth-item 1 goal))
					(equal? (nth-item 2 state) (nth-item 2 goal))) #t)
			  (#t (if (null? (cdr alist))
					  (isagoal state (list))
				   	  (isagoal state (cdr alist))))))))

;convenience helper returns past actions that led up to the action passed in
(define (history act) (cdr (cdr (cdr (cdr (cdr act))))))

;helper function for convenience, returns state in 0-0 form
(define (action-from act) (nth-item 3 act))

;test helper: bad hardcode of heuristic to default percept
(define (haich-func percept state)
  		;find delta x and delta y between state and goal,
		;sum and multiply by 6. optimistic b/c lowest cost
		;for movement is 6/square if move-3 is used exclusively. 
		;sum product and cost of goal 
		;of both delta x and delta y are not zero, there is at least
		;one turn, so add 5. else assume facing goal for optimism, add 0.
		;list resulting values, call find-smallest on said list
		(find-smallest (list
						 	;goal 20
							(+ (* 6 (+ (abs (- (nth-item 1 state) 5))
									 (abs (- (nth-item 2 state) 10))))
							   980
							   (cond ((and (< 0 (abs (- (nth-item 1 state) 5)))
										   (< 0 (abs (- (nth-item 2 state) 10
														))))
									  5)
									 (#t 0)))
							;goal 100
							(+ (* 6 (+ (abs (- (nth-item 1 state) 3))
									   (abs (- (nth-item 2 state) 5))))
							   900
							   (cond ((and (< 0 (abs (- (nth-item 1 state) 3)))
										   (< 0 (abs (- (nth-item 2 state) 5
														))))
									  5)
									 (#t 0)))
							;goal 1000
							(+ (* 6 (+ (abs (- (nth-item 1 state) 8))
									   (abs (- (nth-item 2 state) 5))))
							   0
							   (cond ((and (< 0 (abs (- (nth-item 1 state) 8)))
										   (< 0 (abs (- (nth-item 2 state) 5
														))))
									  5)
									 (#t 0)))
							)))
