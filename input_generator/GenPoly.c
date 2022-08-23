#include <stdio.h>
#include <stdlib.h>
#define N 10

int main() {
    FILE * f = fopen("PolyData.txt", "a");
    
    int ** tab = (int **)malloc(sizeof(int*) * N);
    for (int i = 0 ; i < N ; i++) {
        tab[i] = (int *)malloc(sizeof(int) * N);
        tab[i][0] = 1;
        tab[i][i] = 1;
    }
    
    int ** res = (int **)malloc(sizeof(int*) * N);
    for (int i = 0 ; i < N ; i++) {
        res[i] = (int *)malloc(sizeof(int) * N);
    }
    
    printf("1\n");
    for (int i = 1 ; i < N ; i++) {
        printf("1 ");
        for (int j = 1 ; j < i ; j++) {
            tab[i][j] = (tab[i-1][j-1] + tab[i-1][j]);
            printf("%d ", tab[i][j]);
        }
        printf("%d\n", tab[i][i]);
    }
    
    
    for (int i = 0 ; i < N ; i++) {
    	for (int j = 0 ; j <= i ; j++) {
            if (j % 2 != 0) {
                res[i][j] = (-tab[i][j]);
            } else {
                res[i][j] = tab[i][j];
            }
            printf("%d ", res[i][j]);
            fprintf(f, "%d ", res[i][j]);
    	}
    	printf("\n");
    	fprintf(f, "\n");
    }
    
    fclose(f);
    return 0;
}
