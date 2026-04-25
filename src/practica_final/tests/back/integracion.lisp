(setq base 2)
(setq limite 1024)

(setq p2 (* base base))
(setq p4 (* p2 p2))
(setq p8 (* p4 p4))
(setq p16 (* p8 p8))

(setq suma_anid (/ (* (+ 3 5) (- 10 4)) 2))
(setq mod_r (mod (+ p4 7) 5))
(setq complejo (+ (* p2 3) (- p4 (/ p8 p4))))
(setq neg_p2 (- p2))

(setq cmp_eq  (= p4 16))
(setq cmp_neq (/= p2 16))
(setq cmp_lt  (< suma_anid p8))
(setq cmp_gt  (> p8 p4))
(setq cmp_lte (<= p4 p4))
(setq cmp_gte (>= p16 limite))

(setq bool_and (and (> p8 100) (< p16 100000)))
(setq bool_or  (or  (= mod_r 0) (= mod_r 2)))
(setq bool_not (not (= p2 0)))
(setq bool_cmp (and (not (= p4 0)) (or (> p8 200) (< p2 10))))

(print "== inicio de test back ==")
(princ suma_anid)
(princ "mod:")
(princ mod_r)
(princ (+ complejo neg_p2))

(setq acum 0)
(setq idx 0)
(loop while (< idx 20) do
(setf acum (+ acum idx))
(setf idx (+ idx 1)))

(setq clasificacion 0)
(if (>= acum 190)
(setf clasificacion 1)
(setf clasificacion 0))

(setq nivel 0)
(if (> p16 10000)
(if (> p8 200)
(progn
(setf nivel 3)
(princ nivel))
(progn
(setf nivel 2)
(princ nivel)))
(progn
(setf nivel 1)
(princ nivel)))

(setq contador_pares 0)
(setq contador_impares 0)
(setq n 0)
(loop while (<= n 15) do
(if (= (mod n 2) 0)
(progn
(setf contador_pares (+ contador_pares 1))
(princ n))
(setf contador_impares (+ contador_impares 1)))
(setf n (+ n 1)))

(progn
(setq temp_a (+ acum suma_anid))
(setq temp_b (- p16 p8))
(setq temp_c (* temp_a temp_b))
(princ temp_c))

(setq prev 0)
(setq curr 1)
(setq paso 0)
(setq umbral 200)
(setq suma_fib 0)
(setq sig 0)
(setq ratio 0)

(defun main ()
(setf prev 0)
(setf curr 1)
(setf paso 0)
(setf umbral 200)
(setf suma_fib 0)
(loop while (< curr umbral) do
(setf sig (+ prev curr))
(setf prev curr)
(setf curr sig)
(setf paso (+ paso 1))
(setf suma_fib (+ suma_fib curr))
(if (= (mod paso 3) 0)
(progn
(princ paso)
(princ curr))
(if (= (mod paso 2) 0)
(princ suma_fib)
(princ prev))))
(if (and (> curr 100) (<= curr 500))
(progn
(print "fibonacci en rango medio")
(princ curr))
(if (> curr 500)
(print "fibonacci supera 500")
(print "fibonacci bajo 100")))
(setf ratio (/ curr prev))
(if (or (= ratio 1) (= ratio 2))
(print "ratio simple")
(progn
(print "ratio compuesto")
(princ ratio)))
(princ (+ suma_fib (* curr prev))))

(main)
