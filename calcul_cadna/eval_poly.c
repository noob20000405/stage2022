#include <stdio.h>
#include <cadna.h>

//input : x a0 a1 a2 ...

int main(int argc, char * argv[]) {
    cadna_init(-1);
    double_st res = 0.0;
    double_st x = strtod(argv[1], NULL);
    
    res = strtod(argv[argc - 1], NULL);
    for (int j = argc - 2 ; j > 1 ; j--) {
        res = res * x + strtod(argv[j], NULL);
    }
    
    printf("res: %s\n", strp(res));
    cadna_end();
}
