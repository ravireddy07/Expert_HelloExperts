(defun power (x y)
            (if (= y 0) 1
                (* x (power x (- y 1)))))
                
(defun area-triangle (h b)
   "Calculates area of a Triangle with given height and breadth"
   
   (format t "height: ~5f" h)
   (format t "~%breadth: ~5f" b)
   (format t "~%Area: ~10f" (/(* h b)2))
   
   (setq area_one_triangle (/(* h b)2))
   
   (format t "~%Area of Octagon: ~10f" (* (* (+ 1 (sqrt 2)) 2) (power area_one_triangle 2)))
)

(area-triangle 10 10)
