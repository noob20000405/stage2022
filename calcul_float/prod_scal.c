#include <stdio.h>
#include <cadna.h>

// input : l a1 a2 ... al b1 b2 ... bl

int main(int argc, char * argv[]) {
    cadna_init(-1);
    int l = strtod(argv[1], NULL);
    double_st res = 0.0;
    
    for (int i = 0 ; i < l ; i++) {
        res += (strtod(argv[i + 2], NULL) * strtod(argv[i + l + 2], NULL));
    }
    
    printf("res = %s\n", strp(res));
    
    cadna_end();
}
