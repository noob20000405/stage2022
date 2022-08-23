#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]) {
    FILE * f1 = fopen("../output_dat/o_somme_f.txt", "a");
    FILE * f2 = fopen("../output_dat_log10/o_somme_f.txt", "a");
    
    double v, res, res_abs;
    v = 0.0;
    res = 0.0;
    res_abs = 0.0;
    
    for (int i = 1 ; i < argc ; i++) {
        v = strtod(argv[i], NULL);
        res += v;
        res_abs += fabs(v);
    }
    
    res_abs /= fabs(res);
    
    printf("cond = %lf\n", res_abs);
    fprintf(f1, "%lf\n", res_abs);
    fprintf(f2, "%lf\n", log10(res_abs));
    fclose(f1);
    fclose(f2);
    
    return 0;
}
