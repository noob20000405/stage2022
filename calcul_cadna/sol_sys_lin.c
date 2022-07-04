
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cadna.h>

int main(int argc, char * argv[]) {
    int n = atoi(argv[1]);
    double M[n][n];
    double L[n][n];
    
    // initialiser M (matrice a decomposer) et L (comme une matrice idem au debut)
    for (int i = 0 ; i < n ; i++) {
       for (int j = 0 ; j < n ; j++) {
            M[i][j] = strtod(argv[i * n + j + 2], NULL);
            if (i == j) {
                L[i][j] = 1;
            } else {
                L[i][j] = 0;
            }
       }
    }
    
    // print M
    printf("M = \n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%f ", M[i][j]);
        }
        printf("\n");
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
    
    return 0;
}
