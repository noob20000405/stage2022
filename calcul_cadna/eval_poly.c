#include <stdio.h>
#include <cadna.h>

//input : x a0 a1 a2 ...

int main(int argc, char * argv[]) {
    cadna_init(-1);
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
    
    cadna_end();
}
