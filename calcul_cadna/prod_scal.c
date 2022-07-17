#include <stdio.h>
#include <cadna.h>

// input : l a1 a2 ... al b1 b2 ... bl

int main(int argc, char * argv[]) {
    cadna_init(-1);
    
    FILE * f = fopen("o_pro_scal.txt", "a");
    int l = strtod(argv[1], NULL);
    double_st res = 0.0;
    
    for (int i = 0 ; i < l ; i++) {
        res += (strtod(argv[i + 2], NULL) * strtod(argv[i + l + 2], NULL));
    }
    
    printf("res = %s\n", strp(res));
    // output result
    //fprintf(f, "%s ", strp(res));
    // output condition nb
    int c = res.getaccuracy();
    double cond = (pow(10, -c) * pow(2, 53));
    fprintf(f, "%lf\n", cond);
    
    fclose(f);
    cadna_end();
}
