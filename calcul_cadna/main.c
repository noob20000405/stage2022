#include <string.h>
#include <stdio.h>
#include <cadna.h>
#include <stdlib.h>

#define N 6

int main() {
    //char * str;
    char buf[1000];
    //double v1[N];
    //double v2[N];
    //double a, b;
    char v1[100];
    char v2[100];
    char a[50];
    char b[50];
    char n[10];
    sprintf(n, "%d", N);
    
    int cpt = 0;
    // read data from generator
    FILE * f_in = fopen("../input_generator/DotData.txt", "r");
    FILE * f_out = fopen("o_pro_scal.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    char com[500];
    
    strcpy(v1, "");
    strcpy(v2, "");
    strcpy(com, "");
    
    while (fgets(buf, 1000, f_in) != NULL) {
        //strcat(str, buf);
        printf("read : %s\n", buf);
        //sscanf(buf, "%lf\t%lf", &a, &b);
        sscanf(buf, "%s\t%s", a, b);
        //printf("%lf, %lf\n", a, b);
        printf("str : %s, %s\n", a, b);
        
        //v1[cpt] = a;
        //v2[cpt] = b;
        strcat(v1, a);
        strcat(v1, " ");
        strcat(v2, b);
        strcat(v2, " ");
        
        cpt++;
        if (cpt == N) {
            cpt = 0;
            printf("v1 = %s\n", v1);
            printf("v2 = %s\n", v2);
            
            strcat(com, "./prod_scal ");
            strcat(com, n);
            strcat(com, " ");
            strcat(com, v1);
            strcat(com, v2);
            printf("com = %s\n", com);
            system(com);
            strcpy(v1, "");
            strcpy(v2, "");
            strcpy(com, "");
        }
    }
    
    for (int i = 0 ; i < N ; i++) {
        //printf("%s %s\n", v1[i], v2[i]);
    }
}
