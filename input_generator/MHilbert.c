#include <stdio.h>
#define S 2
#define E 10

int main() {
    
    FILE * f = fopen("SolData.txt", "a");
    
    double tmp = 1.0;
    
    for (int l = S ; l < E ; l++) {
        for (int i = 0 ; i < l ; i++) {
            for (int j = 0 ; j < l ; j++) {
                fprintf(f, "%lf ", tmp / ((double)(i + j + 1)));
                printf("%lf ", tmp / ((double)(i + j + 1)));
            }
        }
        fprintf(f, "\n");
    }
    
    fclose(f);
    return 0;
}
