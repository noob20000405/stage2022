#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//input n M00 M01 ... Mnn b1 b2 ...bn

int main(int argc, char * argv[]) {
    int n = atoi(argv[1]);
    double M[n][n];
    double L[n][n];
    double b[n];
    double Y[n];
    double X[n];
    
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
    
    // print M
    printf("M = \n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%f ", M[i][j]);
        }
        printf("\n");
    }
    
    //print b
    printf("=\nb = \n");
    for (int i = 0 ; i < n ; i++) {
        printf("%f\n", b[i]);
    }
    
    // decomposer LU
    double tmp = 0.0;
    for (int j = 0 ; j < n - 1 ; j++) {
        for (int i = j + 1 ; i < n ; i++) {
            if (M[j][j] != 0) {
                tmp = (M[i][j]) / (M[j][j]);
                M[i][j] = 0;
                L[i][j] = tmp;
            } else {
                printf("matrice non diagonalisable.\n");
                return 1;
            }
            
            for (int k = j + 1 ; k < n ; k++) {
                M[i][k] -= (tmp * M[j][k]);
            }
        }   
    }
    
    // print L
    printf("L = \n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%f ", L[i][j]);
        }
        printf("\n");
    }
    
    // print U
    printf("U = \n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%f ", M[i][j]);
        }
        printf("\n");
    }
    
    // resolution
    // resoudre LY = b, d'ou Y = UX
    for (int i = 0 ; i < n ; i++) {
        Y[i] = b[i];
        for (int j = 0 ; j < i ; j++) {
            Y[i] -= (Y[j] * L[i][j]);
        }
        Y[i] /= L[i][i];
    }
    // resoudre UX = Y
    for (int i = n - 1 ; i > -1 ; i--) {
        X[i] = Y[i];
        for (int j = i + 1 ; j < n ; j++) {
            X[i] -= (M[i][j] * X[j]);
            
        }
        X[i] /= M[i][i];
    }
    
    // print X et Y
    /*printf("Y = \n");
    for (int i = 0 ; i < n ; i++) {
        printf("%f\n", Y[i]);
    }*/
    printf("X = \n");
    for (int i = 0 ; i < n ; i++) {
        printf("%f\n", X[i]);
    }
    
    return 0;
}
