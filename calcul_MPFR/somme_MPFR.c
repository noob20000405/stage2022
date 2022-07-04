#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

/*int main(int argc, char * argv[]) {

    mpfr_t v, res, res_abs;
    
    mpfr_init2(v, 200);
    mpfr_set_d(v, 0.0, MPFR_RNDD);
    mpfr_init2(res, 200);
    mpfr_set_d(res, 0.0, MPFR_RNDD);
    mpfr_init2(res_abs, 200);
    mpfr_set_d(res_abs, 0.0, MPFR_RNDD);
    
    for (int i = 1 ; i < argc ; i++) {
        mpfr_set_d(v, strtod(argv[i], NULL), MPFR_RNDD);
        mpfr_add(res, res, v, MPFR_RNDD);
        
        mpfr_abs(v, v, MPFR_RNDD);
        mpfr_add(res_abs, res_abs, v, MPFR_RNDD);
    }
    printf("res = ");
    mpfr_out_str(stdout, 10, 0, res, MPFR_RNDD);
    putchar('\n');
    
    // conditionnement
    mpfr_abs(res, res, MPFR_RNDD);
    mpfr_div(res_abs, res_abs, res, MPFR_RNDD);
    printf("conditionnement = ");
    mpfr_out_str(stdout, 10, 0, res_abs, MPFR_RNDD);
    putchar('\n');
    
    mpfr_clear(v);
    mpfr_clear(res);
    mpfr_clear(res_abs);
    mpfr_free_cache();
    return 0;
}*/

int main(int argc, char * argv[]) {
    double res = 0.0;
    mpfr_t res_mpfr, tmp;
    
    mpfr_init2(res_mpfr, 200);
    mpfr_set_d(res_mpfr, 0.0, MPFR_RNDD);
    mpfr_init2(tmp, 200);
    mpfr_set_d(tmp, 0.0, MPFR_RNDD);
    
    for (int i = 0 ; i < argc ; i++) {
        res += strtod(argv[i], NULL);
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
    mpfr_clear(tmp);
    mpfr_free_cache();
    
    return 0;
}
