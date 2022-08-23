#include <stdio.h>
#include <cadna.h>

//input : x a0 a1 a2 ...

int main(int argc, char * argv[]) {
    cadna_init(-1);
    
    FILE * f1 = fopen("../output_dat/o_eval_poly.txt", "a");
    FILE * f2 = fopen("../output_dat_log10/o_eval_poly.txt", "a");
    
    double_st res = 0.0;
    double_st x = strtod(argv[1], NULL);
    
    res = strtod(argv[argc - 1], NULL);
    for (int j = argc - 2 ; j > 1 ; j--) {
        res = res * x + strtod(argv[j], NULL);
    }
    
    printf("res: %s\n", strp(res));
    
    //calcul condition
    printf("nb sig digits : %d\n", res.nb_significant_digit());
    int c = res.getaccuracy();
    printf("acc : %d\n", c);
    printf("%.50e\n", pow(10, -c));
    double cond = (pow(10, -c) * pow(2, 53));
    printf("cond = %lf\n", cond); 
    
    printf("sig digits = %d\n", res.nb_significant_digit());
    
    fprintf(f1, "%lf\n", cond);
    fprintf(f2, "%lf\n", log10(cond));
    
    fclose(f1);
    fclose(f2);
    
    cadna_end();
}
