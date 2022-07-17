#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>
#include <math.h>

// input : l a1 a2 ... al b1 b2 ... bl

int main(int argc, char * argv[]) {
    FILE * f = fopen("o_prod_scal_MPFR.txt", "a");
    unsigned int l = atoi(argv[1]);
    mpfr_t p, res, res_abs;
    mpfr_init2(res, 200);
    mpfr_init2(res_abs, 200);
    mpfr_init2(p, 200);
    mpfr_set_d(p, 0.0, MPFR_RNDD);
    mpfr_set_d(res, 0.0, MPFR_RNDD);
    mpfr_set_d(res_abs, 0.0, MPFR_RNDD);
    
    for (int i = 0 ; i < l ; i++) {
        mpfr_set_d(p, strtod(argv[i + 2], NULL), MPFR_RNDD);
        mpfr_mul_d(p, p, strtod(argv[i + l + 2], NULL), MPFR_RNDU);
        mpfr_add(res, res, p, MPFR_RNDD);
        
        mpfr_set_d(p, fabs(strtod(argv[i + 2], NULL)), MPFR_RNDD);
        mpfr_mul_d(p, p, fabs(strtod(argv[i + l + 2], NULL)), MPFR_RNDU);
        mpfr_add(res_abs, res_abs, p, MPFR_RNDD);
    }
    
    printf("res = ");
    mpfr_out_str(stdout, 10, 0, res, MPFR_RNDD);
    putchar('\n');
    
    mpfr_abs(res, res, MPFR_RNDD);
    mpfr_mul_ui(res_abs, res_abs, 2, MPFR_RNDU);
    mpfr_div(res_abs, res_abs, res, MPFR_RNDD);
    printf("conditionnement = ");
    mpfr_out_str(stdout, 10, 0, res_abs, MPFR_RNDD);
    putchar('\n');
    
    mpfr_out_str(f, 10, 0, res_abs, MPFR_RNDD);
    fprintf(f, "\n");
    
    fclose(f);
    
    mpfr_clear(res);
    mpfr_clear(res_abs);
    mpfr_clear(p);
    mpfr_free_cache();
    
    return 0;
}

/*int main(int argc, char * argv[]) {
    unsigned int l = atoi(argv[1]);
    double res = 0;
    mpfr_t p, res_mpfr, tmp;
    
    mpfr_init2(p, 200);
    mpfr_set_d(p, 0.0, MPFR_RNDD);
    mpfr_init2(res_mpfr, 200);
    mpfr_set_d(res_mpfr, 0.0, MPFR_RNDD);
    mpfr_init2(tmp, 200);
    mpfr_set_d(tmp, 0.0, MPFR_RNDD);
    
    for (int i = 0 ; i < l ; i++) {
        res += (strtod(argv[i + 2], NULL) * strtod(argv[i + l + 2], NULL));
        
        mpfr_set_d(p, strtod(argv[i + 2], NULL), MPFR_RNDD);
        mpfr_mul_d(p, p, strtod(argv[i + l + 2], NULL), MPFR_RNDU);
        mpfr_add(res_mpfr, res_mpfr, p, MPFR_RNDD);
    }
    
    printf("valeur calculee = %.80e\n", res);
    printf("valeur exacte   = ");
    mpfr_out_str(stdout, 10, 0, res_mpfr, MPFR_RNDD);
    putchar('\n');
    
    mpfr_set_d(tmp, res, MPFR_RNDD);
    mpfr_div(tmp, tmp, res_mpfr, MPFR_RNDD);
    printf("conditionnement = ");
    mpfr_out_str(stdout, 10, 0, tmp, MPFR_RNDD);
    putchar('\n');
    
    mpfr_clear(res_mpfr);
    mpfr_clear(p);
    mpfr_clear(tmp);
    mpfr_free_cache();
    
    return 0;
}*/
