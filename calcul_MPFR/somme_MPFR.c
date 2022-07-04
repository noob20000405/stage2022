#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

int main(int argc, char * argv[]) {

    mpfr_t v, res;
    
    mpfr_init2(v, 200);
    mpfr_set_d(v, 0.0, MPFR_RNDD);
    mpfr_init2(res, 200);
    mpfr_set_d(res, 0.0, MPFR_RNDD);
    
    for (int i = 1 ; i < argc ; i++) {
        mpfr_set_d(v, strtod(argv[i], NULL), MPFR_RNDD);
        mpfr_add(res, res, v, MPFR_RNDD);
    }
    printf("res = ");
    mpfr_out_str(stdout, 10, 0, res, MPFR_RNDD);
    putchar('\n');
    
    mpfr_clear(v);
    mpfr_clear(res);
    mpfr_free_cache();
    return 0;
}
