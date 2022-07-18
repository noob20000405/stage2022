set output "test.png"
set xlabel "indice"
set ylabel "condition number"
set title ""
set xrange[1:10]
set yrange[9000:9000000]
set xtics 1,1,20
plot "o_pro_scal.txt" using 1:2 with lines title "1"
plot "../calcul_MPFR/o_prod_scal_MPFR.txt" using 1:2 with lines title "2"
