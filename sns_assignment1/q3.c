#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main(int argc, char**argv){

    mpz_t n;
    mpz_init(n);
    mpz_set_str(n, argv[1], 10);

    mpz_t root;
    mpz_init(root);
    mpz_root(root, n, 2);

    mpz_t cur ;
    mpz_init(cur);
    mpz_set_ui(cur, 2);

    while( mpz_cmp(cur, root) <= 0 ){
        
        while( mpz_divisible_p(n, cur) != 0){

            mpz_cdiv_q(n, n, cur);
            mpz_out_str(stdout, 10, cur);
            printf(" ");
        }

        mpz_add_ui(cur, cur, 1);
    }

    if( mpz_cmp_ui(n, 1) !=0 ){
        mpz_out_str(stdout, 10, n);
    }

}