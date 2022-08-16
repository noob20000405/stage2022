#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>
#include <math.h>

//input : x a0 a1 a2 ...

int main(int argc, char * argv[]) {
    mpfr_t res, res_abs, x, x_abs;
    
    mpfr_init2(res, 200);
    mpfr_set_d(res, strtod(argv[argc - 1], NULL), MPFR_RNDD);
    mpfr_init2(res_abs, 200);
    mpfr_set_d(res_abs, fabs(strtod(argv[argc - 1], NULL)), MPFR_RNDD);
    mpfr_init2(x, 200);
    mpfr_set_d(x, strtod(argv[1], NULL), MPFR_RNDD);
    mpfr_init2(x_abs, 200);
    mpfr_set_d(x_abs, fabs(strtod(argv[1], NULL)), MPFR_RNDD);
    
    for (int j = argc - 2 ; j > 1 ; j--) {
        mpfr_mul(res, res, x, MPFR_RNDU);
        mpfr_add_d(res, res, strtod(argv[j], NULL), MPFR_RNDD);
        
        mpfr_mul(res_abs, res_abs, x_abs, MPFR_RNDU);
        mpfr_add_d(res_abs, res_abs, fabs(strtod(argv[j], NULL)), MPFR_RNDD);
    }
    
    printf("res = ");
    mpfr_out_str(stdout, 10, 0, res, MPFR_RNDD);
    putchar('\n');
    
    mpfr_abs(res, res, MPFR_RNDD);
    mpfr_div(res_abs, res_abs, res, MPFR_RNDD);
    printf("conditionnement = ");
    mpfr_out_str(stdout, 10, 0, res_abs, MPFR_RNDD);
    putchar('\n');
    
    mpfr_clear(res);
    mpfr_clear(res_abs);
    mpfr_clear(x);
    mpfr_clear(x_abs);
    mpfr_free_cache();
    return 0;
}

/*int main(int argc, char * argv[]) {
    double res = strtod(argv[argc - 1], NULL);
    double x = strtod(argv[1], NULL);
    mpfr_t res_mpfr, x_mpfr, tmp;
    
    mpfr_init2(res_mpfr, 200);
    mpfr_set_d(res_mpfr, strtod(argv[argc - 1], NULL), MPFR_RNDD);
    mpfr_init2(x_mpfr, 200);
    mpfr_set_d(x_mpfr, strtod(argv[1], NULL), MPFR_RNDD);
    mpfr_init2(tmp, 200);
    mpfr_set_d(tmp, 0.0, MPFR_RNDD);
    
    for (int i = argc - 2 ; i > 1 ; i--) {
        res *= x;
        res += strtod(argv[i], NULL);
        
        mpfr_mul(res_mpfr, res_mpfr, x_mpfr, MPFR_RNDU);
        mpfr_add_d(res_mpfr, res_mpfr, strtod(argv[i], NULL), MPFR_RNDD);
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
    mpfr_clear(x_mpfr);
    mpfr_clear(tmp);
    mpfr_free_cache();
    
    return 0;
}*/
