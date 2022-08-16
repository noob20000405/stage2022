#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]) {
    FILE * f = fopen("o_sol_sys_lin_f.txt", "a");

    int n = atoi(argv[1]);
    double M[n][n];
    double I[n][n];

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
                I[i][j] = 1;
            } else {
                I[i][j] = 0;
            }
       }
       X[i] = 0;
       Y[i] = 0;
    }
    
    

}
