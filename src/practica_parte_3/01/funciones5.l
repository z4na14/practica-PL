(defun mimax (a b )
(if (>= a b)
(progn
(princ a)
(print " "))
(progn
(princ b)
(print " ")))
)

(defun main ()
(mimax 10 1 )
(mimax 1 10 )
(mimax 10 10 ))
 (main)
