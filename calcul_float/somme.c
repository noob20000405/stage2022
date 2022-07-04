#include <cadna.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    cadna_init(-1);

    double_st v = 0.0;
    double_st res = 0.0;
    for (int i = 1 ; i < argc ; i++) {
        v = strtod(argv[i], NULL);
        res += v;
    }
    printf("res: %s\n", strp(res));
    
    cadna_end();
}
