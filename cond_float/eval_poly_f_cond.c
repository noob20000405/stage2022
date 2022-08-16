#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cadna.h>

int main(int argc, char * argv[]) {
    cadna_init(-1);

    FILE * f = fopen("o_eval_poly_f_cond.txt", "a");
    double_st res, res_abs, x, x_abs;
    res = strtod(argv[argc - 1], NULL);
    res_abs = fabs(strtod(argv[argc - 1], NULL));
    x = strtod(argv[1], NULL);
    x_abs = fabs(strtod(argv[1], NULL));
    
    for (int j = argc - 2 ; j > 1 ; j--) {
        res *= x;
        res += strtod(argv[j], NULL);
        
        res_abs *= x_abs;
        res_abs += fabs(strtod(argv[j], NULL));
    }
    
    printf("res = %s\n", strp(res));
    res = fabs(res);
    res_abs /= res;
    printf("cond_float = %s\n", strp(res_abs));
    int c = res_abs.getaccuracy();
    double cond = (pow(10, -c) * pow(2, 53));
    fprintf(f, "%lf\n", cond);
    
    fclose(f);
    cadna_end();
}
