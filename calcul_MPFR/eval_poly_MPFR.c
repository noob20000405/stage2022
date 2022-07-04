#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

//input : x a0 a1 a2 ...

int main(int argc, char * argv[]) {
    mpfr_t res, x;
    
    mpfr_init2(res, 200);
    mpfr_set_d(res, strtod(argv[argc - 1], NULL), MPFR_RNDD);
    mpfr_init2(x, 200);
    mpfr_set_d(x, strtod(argv[1], NULL), MPFR_RNDD);
    
    for (int j = argc - 2 ; j > 1 ; j--) {
        mpfr_mul(res, res, x, MPFR_RNDU);
        mpfr_add_d(res, res, strtod(argv[j], NULL), MPFR_RNDD);
    }
    
    printf("res = ");
    mpfr_out_str(stdout, 10, 0, res, MPFR_RNDD);
    putchar('\n');
    
    mpfr_clear(res);
    mpfr_clear(x);
    mpfr_free_cache();
    return 0;
}
