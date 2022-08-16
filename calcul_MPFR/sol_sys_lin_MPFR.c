#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

//input n M00 M01 ... Mnn b1 b2 ...bn
// cond(M) = \\ \M-1\.\M\ \\

int main(int argc, char * argv[]) {
    FILE * f = fopen("o_sol_lin_MPFR.txt", "a");
    
    int n = atoi(argv[1]);
    double M[n][n];
    double L[n][n];
    double b[n];
    double Y[n];
    double X[n];
    
    /*double M[n][n];
    double L[n][n];
    double b[n];
    double Y[n];
    double X[n];*/
    
    // initialiser M (matrice a decomposer), L (comme une matrice idem au debut) et b (vecteur)
    for (int i = 0 ; i < n ; i++) {
       for (int j = 0 ; j < n ; j++) {
            M[i][j] = strtod(argv[i * n + j + 2], NULL);
            if (i == j) {
                L[i][j] = 1;
            } else {
                L[i][j] = 0;
            }
       }
       b[i] = strtod(argv[n * n + i + 2], NULL);
       X[i] = 0;
       Y[i] = 0;
    }
    
    
}
