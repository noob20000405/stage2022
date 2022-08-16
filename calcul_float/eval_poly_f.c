#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]) {

    FILE * f = fopen("o_eval_poly_f.txt", "a");
    double res, res_abs, x, x_abs;
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
    
    printf("res = %lf\n", res);
    res = fabs(res);
    res_abs /= res;
    printf("cond = %lf\n", res_abs);
    fprintf(f, "%lf\n", res_abs);
    
    fclose(f);
    return 0;
}
