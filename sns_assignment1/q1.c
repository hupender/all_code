#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main(int argc, char**argv){

    int n,i;

    n = atoi(argv[1]);
    mpz_t* arr = (mpz_t*)malloc(n*sizeof(mpz_t));

    for(i=0; i<n; i++){
        mpz_set_str(arr[i], argv[i+2], 10);
    }

    mpz_t gcd;
    mpz_init(gcd);
    mpz_set(gcd, arr[0]);

    for(int i=1; i<n; i++){
        mpz_gcd(gcd, gcd, arr[i]);
    }

    mpz_t root;
    mpz_init(root);
    // square root
    int res = mpz_root(root, gcd, 2);
    int exact = (res != 0);

    mpz_t cur ;
    mpz_init(cur);
    mpz_set_ui(cur, 1);
    while( mpz_cmp(cur, root) <= 0 ){
        // try to see if cur divides gcd.
        int res = mpz_divisible_p(gcd, cur);
        if(res != 0){
            //it is divisible
            mpz_out_str(stdout, 10, cur);
            printf(" ");
        }

        // add 1 to mpz 
        mpz_add_ui(cur, cur, 1);
    }

    if(exact){
        mpz_sub_ui(cur, root, 1);
    }
    else{
        mpz_set(cur, root);
    }

    mpz_t cur_factor;
    mpz_init(cur_factor);

    while( mpz_cmp_ui(cur, 1) >= 0 ){
        int res = mpz_divisible_p(gcd, cur);
        if(res != 0){
            mpz_cdiv_q(cur_factor, gcd, cur);
            
            mpz_out_str(stdout, 10, cur_factor);
            printf(" ");
        }

        mpz_sub_ui(cur, cur, 1);
    }
    return 0;

}