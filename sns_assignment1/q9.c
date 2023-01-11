#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>



int main(int argc, char**argv){

    mpz_t a,m;
    mpz_init(a);
    mpz_init(m);
    mpz_set_str(a, argv[1], 10);
    mpz_set_str(m, argv[2], 10);


    mpz_t cur;
    mpz_init(cur);
    mpz_set_ui(cur, 1);
    
    while(1){
        mpz_t pow;
        mpz_init(pow);

        mpz_powm(pow, a, cur, m);

        if( mpz_cmp_ui(pow, 1) == 0 ){
            mpz_out_str(stdout, 10, cur);
            break;
        }

        mpz_add_ui(cur, cur, 1);

    }

}