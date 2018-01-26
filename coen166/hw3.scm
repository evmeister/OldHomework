;Evan Eberhardt
;16 May 16

;Knowledge base
(define kb (list))

;function searches the knowledge base looking for an exact match
(define (ask query) (if (match? query kb) #t (begin (display "UNKNOWN") (newline))))
(define (match? query search)
		;base case: first element is desired
		(cond ((equal? query (car search)) #t)
			  ;if nothing left to search, then false
			  ((null? (cdr search)) #f)
			  ;else recurse through rest of kb
			  (#t (match? query (cdr search)))))

;Tell function puts given statement and front of knowledgebase and then calls the think function
(define (tell stmt)
  		(begin
	  		(set! kb (cons stmt kb))
			(think stmt (cdr kb))
			(display "OK")
			(newline)
			))

;Think helper functions resolves first item in knowledgebase with rest of knowledge base, if any
;puts newly generated statements at the end only if something is generated, avoiding duplicates
;resolve loop through knowledgebase will include newly generated statements
(define (think stmt kbn)
  		(cond ((null? kbn) #t)
			  (#t (if (and (not (match? (cons (resolv stmt (car kbn)) kb) kb))
						   (not (null? (resolv stmt (car kbn) ))))
				      (begin (set! kb (cons (resolv stmt (car kbn)) kb))
					   		 (think stmt (cdr kbn)))
					  (think stmt (cdr kbn))))))

;useful: kb=(a b) (set! kb (append kb '(c))) => kb=(a b c)
;        kb=(b c) (set! kb (cons 'a)) => kb=(a b c)

;Helper functions from HW1
(define (nth-item idx alist)
  		;base case: first element is desired element given index
		(cond ((= idx 1) (car alist))
			  ;decrement index and take cdr for recursion to get to desired index
			  (#t (nth-item (- idx 1) (cdr alist)))))
(define (replace-nth-item idx alist n)
  		;base case: first element is to be replaced, make list of n and remainder of alist
		(cond ((= idx 1) (append (list n) (cdr alist)))
			  ;recursing backwards from insert point putting previous item in front
			  (#t (append (list (car alist)) (replace-nth-item (- idx 1) (cdr alist) n)))))

;Helper function remove
(define (remove-item alist n)
  		;base case: first element is to be removed, make list of remainder of alist
		(cond ((equal? (car alist) n) (cdr alist))
			  ;recursing backwards from insert point putting previous item in front
			  (#t (append (list (car alist)) (remove-item (cdr alist) n)))))

;Helper function to detect contradiction
(define (contradiction? alist blist)
  		(cond ( (and (null? (cdr alist))
					 ;check if alist has one element
					 (null? (cdr blist))
					 ;check of blist has one element
					 (cond ( (list? (car alist))
							;check if alist contains a list. it would be the NOT of a literal
							(if (equal? (cdr (car alist)) blist) #t #f))
						   	;check if the literal in blist is the same as the negated literal in alist
						   ( (list? (car blist))
							;check if blist contains a list. it would be the NOT of a literal
							(if (equal? (cdr (car blist)) alist) #t #f))
						   	;check if the literal in alist is the same as the negated literal in blist
						   (#t #f) ;else false
						   )) #t) ;if the statements have only one literal and these literals match
			  					  ;in one of the two cases where one of them have the NOT,
								  ;then there is a contradiction
			  (#t #f))) ;else false

;Helper to find-cancel returns the item that cancels the other out
;is fed one item and a list of items that have the opposite logical operator on them.
;returns null list if no cancelation found
(define (has-cancel a blist)
  		;is item a a list? i.e. in the form of (NOT a)
  		(cond ( (list? a) (cond ( (null? blist) (list)) ;if so then as long as blist isnt empty
					  	  ;if the value in item a is the same as the first in blist, return car of blist
					  	  		( (equal? (car (cdr a)) (car blist)) (car blist))
					  	  		( #t (has-cancel a (cdr blist))) ;else, recurse through rest of blist
								))
			  ;if a isn't a list, then a must be an atom and blista list of lists containing NOT
			  ;so if the value of item a is same as that of the first item in blist, return car of blist
			  ( (cond ( (null? blist) (list)) ;as long as blist isnt empty
				  	  ( (equal? a (car (cdr (car blist)))) (car blist))
					  ( #t (has-cancel a (cdr blist))) ;else recurse trough the rest of blist
					  ))))

;Helper funtions returns first pair of canceling items encountered
;returns null if none found, assumes elements are unique
(define (find-cancel alist blist)
		;as long as alist isnt null, if first item in alist is a list like (NOT a)
		(cond ( (not (null? alist)) (cond ( (and (list? (car alist)) 
										   ;and it has an opposite in blist
										   (not (null? (has-cancel (car alist) (filter symbol? blist)))))
									 ;then result goes in a list
									  (list (car alist) (has-cancel (car alist) (filter symbol? blist))))

									;otherwise first item is atom, so if it has an opposite in blist
									( (not (null? (has-cancel (car alist) (filter list? blist))))  
									  (list (car alist) (has-cancel (car alist) (filter list? blist))))

									;else recurse through alist to complete the pair that cancels out
									( #t (find-cancel (cdr alist) blist))))
			  ( #t (list)))) ;if nothing found, return null list

;Helper function removes the first occuring pair of items from alist and blist that cancel
;and returns a list containing two items: the remainder of alist and the remainder of blist
;shouldnt get called if there are no cancelling items
(define (remove-cancel alist blist pair)
  		(if (null? pair) (list)
  		(list (remove-item alist (car pair)) (remove-item blist (car (cdr pair))))))

;resolve function returns resolution or null list if it wont resolve
(define (resolve alist blist) ;api
  		(cond ((null? (resolv alist blist)) #f)
			  (#t (resolv alist blist))))
(define (resolv alist blist) ;funciton
  		;if either list is empty, they wont resolve
		(cond ( (or (null? alist) (null? blist)) (list))
			  ;if there is a contradiction between the two, display CONTRADICTION
			  ( (contradiction? alist blist) (begin (display "CONTRADICTION") (newline)))
			  ;if there is no pair between them that cancels out, wont resolve
			  ( (null? (find-cancel alist blist)) (list))
			  ;as long as the two lists don't have two pairs that cancel out
			  ( (null? (find-cancel (car (remove-cancel alist blist (find-cancel alist blist)))
									(car (cdr (remove-cancel alist blist (find-cancel alist blist))))))
			    ;append the resulting lists after removing the elements that cancel
			    (append (car (remove-cancel alist blist (find-cancel alist blist)))
						(car (cdr (remove-cancel alist blist (find-cancel alist blist))))))
			  ( #t (list) ))) ;else it wont resolve

