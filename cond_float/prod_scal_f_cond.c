#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cadna.h>

int main(int argc, char * argv[]) {
    cadna_init(-1);

    FILE * f = fopen("o_prod_scal_f_cond.txt", "a");
    unsigned int l = atoi(argv[1]);
    
    double_st p, res, res_abs;
    p = 0.0;
    res = 0.0;
    res_abs = 0.0;
    
    for (int i = 0 ; i < l ; i++) {
        p = strtod(argv[i + 2], NULL);
        p *= strtod(argv[i + l + 2], NULL);
        res += p;
        
        p = fabs(strtod(argv[i + 2], NULL));
        p *= fabs(strtod(argv[i + l + 2], NULL));
        res_abs += p;
    }
    
    res_abs *= 2;
    res = fabs(res);
    res_abs /= res;
    
    printf("cond_float = %s\n", strp(res_abs));
    int c = res_abs.getaccuracy();
    double cond = (pow(10, -c) * pow(2, 53));
    fprintf(f, "%lf\n", cond);
    fclose(f);
    
    cadna_end();
}
