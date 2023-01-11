#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>



int main(int argc, char**argv){

    mpz_t m;
    mpz_init(m);
    mpz_set_str(m, argv[1], 10);

    mpz_t phi_m;
    mpz_init(phi_m);
    mpz_set_ui(phi_m, 0);

    mpz_t cur;
    mpz_init(cur);
    mpz_set_ui(cur, 1);
    
    while( mpz_cmp(cur, m) < 0 ){
        mpz_t gcd;
        mpz_init(gcd);

        mpz_gcd(gcd, cur, m);

        if( mpz_cmp_ui(gcd, 1) == 0 ){
            // gcd is 1
            mpz_out_str(stdout, 10, cur);
            printf(" ");
            mpz_add_ui(phi_m, phi_m, 1);
        }

        

        mpz_add_ui(cur, cur, 1);
    }

    mpz_out_str(stdout, 10, phi_m);

}