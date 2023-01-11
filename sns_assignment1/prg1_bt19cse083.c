#include<gmp.h>
#include<stdio.h>
#define SIZE 1000
int main(int argc,char** argv){
	int n=argc;


	gmp_printf("Enter the size of input array\n");
	scanf("%d",&n);
	mpz_t nums[SIZE];
	mpz_t min;
	mpz_init(min);
	mpz_set_ui(min,INT_MAX);
	for(int i=0;i<n;i++){
		gmp_printf("Enter the number:\n");
		mpz_init(nums[i]);
		gmp_scanf("%Zd",nums[i]);
		if(mpz_cmp(nums[i],min)<0){
			mpz_set(min,nums[i]);
		}
		
	}
	mpz_t flag;
	mpz_init(flag);
	int l;
	mpz_t j;
	mpz_init(j);
	for(mpz_set_ui(j,1);mpz_cmp(j,min)<=0;mpz_add_ui(j,j,1)){
		mpz_set_ui(flag,1);
		for(l=0;l<n;l++){
			if(mpz_divisible_p(nums[l],j)==0){
				mpz_set_ui(flag,0);
				break;
			}
		}
		if(mpz_cmp_ui(flag,1)==0){
			gmp_printf("\n%Zd",j);
		}
	}

}

