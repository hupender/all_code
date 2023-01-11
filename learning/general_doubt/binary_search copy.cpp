#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;

    int a = 34534;
    int b = 23423525;

    // 4th bit of a
    // 010101100 -> shift 7 times
    // 000001010 
    // 000001010 & (0000...000001) 

    int a_bit4 = (a>>4) & 1 ; 

    for(int bit=30; bit>=0; bit--){
        int abit = (a>>bit)&1;
        int bbit = (b>>bit)&1;

        if(abit){
            if(bbit){
                // both 1
            }
            else{
                // a 1, b 0
                cout << "a";
                break;
            }
        }
        else{
            if(bbit){
                cout << "b";
                break;
                // b 1, a 0
            }
            else{
                // b 0 a 0
            }
        }

    }

    int diff = a-b;

    if(diff){ 
        if( (diff>>31)&1 ){
            // dff is negative
            cout << "b";
        }   
        else{
            cout << "a";
        }
    }
    else{
        cout << "equal";
    }


    // a!=b, b!=0
    int q= a/b;

    int ans2 = bool(q);

    if(q){
        // q is non zero
        // a >= b

        // return true

    }
    else{
        // a<b
    }

    a=0;

    int ans =  a*bool(a/b)+b*bool(b/a);

    cout << "\nans = " << ans << endl;

}

/*
5 3 
1 2 4 5 6
*/