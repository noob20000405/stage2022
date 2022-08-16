#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cadna.h>

int main(int argc, char * argv[]) {
    cadna_init(-1);
    FILE * f = fopen("o_somme_f_cond.txt", "a");
    
    double_st v, res, res_abs;
    v = 0.0;
    res = 0.0;
    res_abs = 0.0;
    
    for (int i = 1 ; i < argc ; i++) {
        v = strtod(argv[i], NULL);
        res += v;
        res_abs += fabs(v);
    }
    
    res_abs /= fabs(res);
    
    printf("cond_float = %s\n", strp(res_abs));
    
    int c = res_abs.getaccuracy();
    double cond = (pow(10, -c) * pow(2, 53));
    fprintf(f, "%lf\n", cond);
    fclose(f);
    
    cadna_end();
}
