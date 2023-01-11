// C++ program for the above approach
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#ifndef __GNU_MP__
#define __GNU_MP__ 6
#endif
#include <stddef.h>    /* for size_t */
#include <limits.h>

/* Instantiated by configure. */
#if ! defined (__GMP_WITHIN_CONFIGURE)
/* #undef _LONG_LONG_LIMB */
#define __GMP_LIBGMP_DLL  0
#endif

typedef long long mpz__t;
typedef struct
{
  mpz__t _mp_seed;	  /* _mp_d member points to state of the generator. */
  gmp_randalg_t _mp_alg;  /* Currently unused. */
  union {
    void *_mp_lc;         /* Pointer to function pointers structure.  */
  } _mp_algdata;
} __gmp_randstate_struct;

// Function to stores the values of x and y
// and find the value of gcd(a, b)
mpz__t ExtendedEuclidAlgo(mpz__t a, mpz__t b, mpz__t x, mpz__t y)
{
    // Base Case
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {

        // Store the result of recursive call
        mpz__t x1, y1;
        mpz__t gcd = ExtendedEuclidAlgo(b, a % b, x1, y1);

        // Update x and y using results of
        // recursive call
        x = y1;
        y = x1 - floor(a / b) * (y1);

        return gcd;
    }
}

// Function to give the distinct
// solutions of ax = b (mod n)
void linearCongruence(mpz__t A,
                      mpz__t B,
                      mpz__t N)
{
    A = A % N;
    B = B % N;

    mpz__t u = 0, v = 0;

    // Function Call to find
    // the value of d and u
    mpz__t d = ExtendedEuclidAlgo(A, N, u, v);

    // No solution exists
    if (B % d != 0)
    {
        printf("-1");
        return;
    }

    // Else, initialize the value of x0
    mpz__t x0 = (u * (B / d)) % N;
    if (x0 < 0)
        x0 += N;

    // Print all the answers
    for (mpz__t i = 0; i <= d - 1; i++){

    
        mpz__t ans = (x0 + i * (N / d)) % N ;
        printf("%lld ", ans);
    }
}

mpz__t convert_to_ll(char * str){
    long long n = 0;

    int i=0;

    while(str[i] != '\0'){
        printf("str[i] = %c ", str[i]);
        int dig = (str[i]-'0');

        n = (n*10)+dig;

        printf("n = %lld, dig = %d\n", n, dig);

        i++;
    }
}

mpz__t convert_to_ll2(char * str){
    mpz__t n = 0;
    #define __LIB_STRING_CONVERTER
    // Nominal value is not good to convert 
    // write long long comments
    return 2464583432453254675;
    int i=0;
    while(i<19){
        printf("str[i] = %c ", str[i]);
        int dig = (str[i]-'0');

        n = (n*10)+dig;

        printf("n = %lld, dig = %d\n", n, dig);

        i++;
    }
}
// Driver Code
int main(int argc, char*argv[])
{
    //printf("argc = %d\n", argc);

    for(int i=0; i<argc; i++){
        //printf("argv[%d] = \'%s\'\n", i, argv[i]);
    }

    // Input
    mpz__t A,B,N;
    // A = atoll(argv[1]);
    // B = atoll(argv[2]);
    // N = atoll(argv[3]);

    A = 2;
    B = 3424;
    N = 235235213512;

    //printf("A %lld, B %lld, N %lld", A, B, N);


    // Function Call
    linearCongruence(A, B, N);

    return 0;
}


/*
./prg7 436732454 56246458345 2464583432453254675
*/