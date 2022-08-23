set term png
set output "4.png"
set xlabel "inputs"
set ylabel "conditionnement"
set title "sol_sys_lin"
plot "o_sol_sys_lin.txt" using 1:2 title "cadna" with lines, "o_sol_sys_lin_f.txt" using 1:2 title "floattant" with lines, "o_sol_sys_lin_MPFR.txt" using 1:2 title "exact" with lines
