#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 6

int main() {
    //char * str;
    char buf[1000];
    //double v1[N];
    //double v2[N];
    //double a, b;
    char v1[1000];
    char v2[1000];
    char a[500];
    char b[500];
    char n[10];
    sprintf(n, "%d", N);
    
    int cpt = 0;
    // read data from generator
    FILE * f_in = fopen("../input_generator/DotData.txt", "r");
    FILE * f_out = fopen("../output_dat/o_prod_scal_f.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    f_out = fopen("../output_dat_log10/o_prod_scal_f.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    char com[5000];
    int i = 0;
    
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
            i++;
            cpt = 0;
            printf("v1 = %s\n", v1);
            printf("v2 = %s\n", v2);
            
            strcat(com, "./prod_scal_f ");
            strcat(com, n);
            strcat(com, " ");
            strcat(com, v1);
            strcat(com, v2);
            printf("com = %s\n", com);
            
            /*FILE * f_out = fopen("o_pro_scal.txt", "a");
            fprintf(f_out, "%d ", i);
            fclose(f_out);*/
            f_out = fopen("../output_dat/o_prod_scal_f.txt", "a");
            fprintf(f_out, "%d ", i);
            fclose(f_out);
            
            f_out = fopen("../output_dat_log10/o_prod_scal_f.txt", "a");
            fprintf(f_out, "%d ", i);
            fclose(f_out);
            
            system(com);
            strcpy(v1, "");
            strcpy(v2, "");
            strcpy(com, "");
        }
    }
    
    fclose(f_in);
    f_in = fopen("../input_generator/SumData.txt", "r");
    f_out = fopen("../output_dat/o_somme_f.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    f_out = fopen("../output_dat_log10/o_somme_f.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    
    i = 0;
    while (fgets(buf, 1000, f_in) != NULL) {
    	i++;
        strcpy(com, "");
        strcat(com, "./somme_f ");
        strcat(com, buf);
        
        f_out = fopen("../output_dat/o_somme_f.txt", "a");
        fprintf(f_out, "%d ", i);
        fclose(f_out);
        f_out = fopen("../output_dat_log10/o_somme_f.txt", "a");
        fprintf(f_out, "%d ", i);
        fclose(f_out);
        
        system(com);
        printf("%s\n", com);
    }
    
    f_in = fopen("../input_generator/PolyData.txt", "r");
    f_out = fopen("../output_dat/o_eval_poly_f.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    f_out = fopen("../output_dat_log10/o_eval_poly_f.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    i = 0;
    while (fgets(buf, 1000, f_in) != NULL) {
    	i++;
        strcpy(com, "");
        strcat(com, "./eval_poly_f 1.001 ");
        strcat(com, buf);
        
        f_out = fopen("../output_dat/o_eval_poly_f.txt", "a");
        fprintf(f_out, "%d ", i);
        fclose(f_out);
        f_out = fopen("../output_dat_log10/o_eval_poly_f.txt", "a");
        fprintf(f_out, "%d ", i);
        fclose(f_out);
        
        system(com);
        printf("%s\n", com);
    }
    
    f_in = fopen("../input_generator/SolData.txt", "r");
    f_out = fopen("../output_dat/o_sol_sys_lin_f.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    f_out = fopen("../output_dat_log10/o_sol_sys_lin_f.txt", "w");
    fprintf(f_out, "");
    fclose(f_out);
    int nb = 2;
    char str[10];
    i = 0;
    while (fgets(buf, 1000, f_in) != NULL) {
        i++;
        sprintf(str, "%d ", nb);
    
        strcpy(com, "");
        strcat(com, "./sol_sys_lin_f ");
        strcat(com, str);
        strcat(com, buf);
        com[strlen(com) - 1] = ' ';
        for (int i = 0 ; i < nb ; i++) {
            strcat(com, "1 ");
        }
        
        f_out = fopen("../output_dat/o_sol_sys_lin_f.txt", "a");
        fprintf(f_out, "%d ", i);
        fclose(f_out);
        f_out = fopen("../output_dat_log10/o_sol_sys_lin_f.txt", "a");
        fprintf(f_out, "%d ", i);
        fclose(f_out);
        
        system(com);
        printf("%s\n", com);
        nb++;
    }
    
    fclose(f_in);
}
