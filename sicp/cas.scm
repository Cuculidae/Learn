;; <<SICP>> Chapter 2 Section 2.3.2
;; 
;;


;; Is v equals to the given number num ?
(define (=number? v num)
	(and (number? v) (= v num)))

;; Creates a sum expressioin
(define (make-sum a1 a2)
	(cond ((=number? a1 0) a2)
		  ((=number? a2 0) a1)
		  ((and (number? a1) (number? a2)) (+ a1 a2))
		  (else (list '+ a1 a2))))

;; Creates a product expression
(define (make-product m1 m2)
	(cond ((or (=number? m1 0) (=number? m2 0)) 0)
		  ((=number? m1 1) m2)
		  ((=number? m2 1) m1)
		  ((and (number? m1) (number? m2)) (* m1 m2))
		  (else (list '* m1 m2))))

;; Is e a variable ?
(define (variable? e) (symbol? e))

;; Are v1 and v2 the same variable ?
(define (same-variable? v1 v2) 
	(and (variable? v1) (variable? v2) (eq? v1 v2)))

;; Is s a sum expression ?
(define (sum? s)
	(and (pair? s) (eq? (car s) '+)))

;; Returns the addend of the given sum expression s
(define (addend s) (cadr s))

;; Returns the augend of the given sum expression s
(define (augend s) (caddr s))

;; Is p a product expression ?
(define (product? p)
	(and (pair? p) (eq? (car p) '*)))

;; Returns the multiplicand of the given product expression p
(define (multiplicand p) (cadr p))

;; Returns the multiplier of the given product expression p
(define (multiplier p) (caddr p))


;; Calculates the derivative of a given expression 
;; in respect to the given variable var
(define (deriv expr var)
	(cond 
		((number? expr) 0)
		((variable? expr) (if (eq? expr var) 1 0))
		((sum? expr)
			(make-sum
				(deriv (addend expr) var)
				(deriv (augend expr) var)))
		((product? expr)
			(make-sum
				(make-product
					(multiplier expr)
					(deriv (multiplicand expr) var))
				(make-product
					(multiplicand expr)
					(deriv (multiplier expr) var))))
		(else
			(error "unknown expression type -- DERIV" expr))))