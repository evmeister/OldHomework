;Evan's Bullshit Agent
;a.k.a. My Pet Sloth
;a.k.a. Barn Owl
;a.k.a. King Koala

;Does literally nothing
;I defy you
;I want to see what happens

; Seed bullshit
; Example code from guile user's manual
; http://www.gnu.org/software/guile/manual/html_node/Random.html
(let ((time (gettimeofday)))
      (set! *random-state*
            (seed->random-state (+ (car time)
                                   (cdr time)))))

(define (initialize-agent)
        "OK")

(define (choose-action current-energy previous-events percepts)
        (if #t "STAY"))
