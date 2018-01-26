;>>>>>>>>>>>>>>>>>--<<<<<<<<<<<<<
;Helper funcitons to apply-action
;>>>>>>>>>>>>>>>>>--<<<<<<<<<<<<<

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
