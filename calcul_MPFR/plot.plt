set term png
set output "test.png"
set xlabel "inputs"
set ylabel "conditionnement"
set title "évaluation polynômiale (ex.1)"
set xtics 1,1,20
plot "eval_mpfr.txt" using 1:1 with lines title "conditionnement exact", "eval.txt" using 1:1 with lines title "conditionnement estimé"
