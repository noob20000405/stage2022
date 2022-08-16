#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]) {
    FILE * f = fopen("o_somme_f.txt", "a");
    
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
    fprintf(f, "%lf\n", log10(res_abs));
    fclose(f);
    
    return 0;
}
