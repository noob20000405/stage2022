#include <cadna.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    cadna_init(-1);

    FILE * f = fopen("o_somme.txt", "a");
    double_st v = 0.0;
    double_st res = 0.0;
    for (int i = 1 ; i < argc ; i++) {
        v = strtod(argv[i], NULL);
        res += v;
    }
    printf("res: %s\n", strp(res));
    
    //calcul condition
    
    printf("nb sig digits : %d\n", res.nb_significant_digit());
    int c = res.getaccuracy();
    printf("acc : %d\n", c);
    double cond = (pow(10, -c) * pow(2, 53));
    printf("cond = %lf\n", cond); 
    
    fprintf(f, "%lf\n", cond);
    
    fclose(f);
    
    cadna_end();
}
