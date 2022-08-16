set term png
set output "test.png"
set xlabel "inputs"
set ylabel "conditionnement"
set title "somme"
set xtics 1,1,20
plot "o_somme.txt" using 1:1 title "cadna", "o_somme_f.txt" using 1:1 title "floattant", "o_somme_MPFR.txt" using 1:1 title "exact"
