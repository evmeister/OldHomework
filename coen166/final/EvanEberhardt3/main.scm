;Trump.exe
;You know what this is.

; Seed random number generator
; Example code from guile user's manual
; http://www.gnu.org/software/guile/manual/html_node/Random.html
(let ((time (gettimeofday)))
      (set! *random-state*
            (seed->random-state (+ (car time)
                                   (cdr time)))))

(define (initialize-agent)
        "OK")

(define (choose-action current-energy previous-events percepts)
	;He just stands still, shouts, and then dies
	(begin (let ((rand (random 13)))
               (cond ((equal? rand 0) (display "I'd bomb the hell out of the oil fields"))
		     ((equal? rand 1) (display "I have a great relationship with the predators in AgentWorld"))
		     ((equal? rand 2) (display "I just want them to suffer"))
		     ((equal? rand 3) (display "Look - I'm really rich"))
		     ((equal? rand 4) (display "I'm going to build a wall and make the other agents pay for it"))
		     ((equal? rand 5) (display "We don't want perverts elected in New York City. No Perverts"))
		     ((equal? rand 6) (display "Some, I assume, are good people"))
		     ((equal? rand 7) (display "The vegetaion in AgentWorld lacks the energy for this campaign"))
		     ((equal? rand 8) (display "What's the difference between a wet raccoon and Donald J Trump's hair?"))
		     ((equal? rand 9) (display "A wet raccoon doesn't have 7 billion #$@*!ing dollars in the bank"))
		     ((equal? rand 10) (display "Just take 'em to McDonalds and go back to the negotiating table"))
		     ((equal? rand 11) (display "And I'm a whiner and I keep whining and whining until I win"))
		     ((equal? rand 12) (display "I'm going to make AgentWorld great again"))
		     (#f (display "You can't stump the Trump")))
                   (#t "STAY")))

;This is why we can't have nice things.