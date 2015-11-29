;; <<SICP>> Chapter 2 Section 2.1.1
;; This program defines an abstract data type representing rational number.
;; 

;; computes the greatest common divisor of integer a and b
(define (gcd a b)
	(if (= b 0)
		a
		(gcd b (remainder a b))))

;; creates a rational number from numerator n and denominator d
(define (make-rat n d)
	(let ((g (gcd n d)))
		(let ((n (/ n g)) (d (/ d g)))
			(if (and (> n 0) (< d 0))
				(cons (- n) (- d))
				(cons n d)))))

;; prints rational number x in a newline,
;; with its numerator and denominator separated by '/'
(define (print-rat x)
	(newline)
	(display (numer x))
	(display "/")
	(display (denom x)))

;; gets the numerator of rational number x
(define (numer x) (car x))

;; gets the denominator of rational number x
(define (denom x) (cdr x))

;; adds two rantional number a and b
;; @param a the augend
;; @param b the addend
(define (add-rat a b)
	(make-rat
		(+ (* (numer a) (denom b)) (* (numer b) (denom a)))
		(* (denom a) (denom b))))

;; 
;; @param a the minuend
;; @param b the subtrahend
(define (sub-rat a b)
	(make-rat
		(- (* (numer a) (denom b)) (* (numer b) (denom a)))
		(* (denom a) (denom b))))

;; multiplies  a and b
;; @param a the multiplicand
;; @param b the multiplier
(define (mul-rat a b)
	(make-rat 
		(* (numer a) (numer b))
		(* (denom a) (denom b))))

;; divides
;; @param a the dividend
;; @param b the divisor
(define (div-rat a b)
	(make-rat 
		(* (numer a) (denom b))
		(* (denom a) (numer b))))

;;
(define (equal-rat a b)
	(and (= (numer a) (numer b))
		 (= (denom a) (denom b))))
