#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]) {
    FILE * f1 = fopen("../output_dat/o_prod_scal_f.txt", "a");
    FILE * f2 = fopen("../output_dat_log10/o_prod_scal_f.txt", "a");
    unsigned int l = atoi(argv[1]);
    
    double p, res, res_abs;
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
    
    printf("cond = %lf\n", res_abs);
     fprintf(f1, "%lf\n", res_abs);
    fprintf(f2, "%lf\n", log10(res_abs));
    fclose(f1);
    fclose(f2);
    
    return 0;
}
