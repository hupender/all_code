#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli; 

ulli gcd(ulli a,ulli b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}

ulli lcm(ulli a,ulli b) {
    return a/(gcd(a,b))*b;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        ulli count=0;
        int l,r;
        cin>>l>>r;

        ulli loop = 0;
        for(ulli i=l;i<=r-2;i++) {
            for(ulli j=i+1;j<=r-1;j++) {
                for(ulli k=j+1;k<=r;k++) {
                    ulli p=lcm(i,lcm(j,k));
                    loop++;      

                    if(loop % 100000 == 0){
                        cout << " loop = " << loop << endl;
                    }

                    if(p>=i+j+k) 
                    {
                        count++;
                    }
                }
            }
        }

        //cout << "loop : " << loop << endl;

        cout<<count<<endl;
    }
}

/*

1

6 86868

4
1 4
3 5
8 86
68 86

5
1 4
3 5
8 86
68 86
6 86868

3
1
78975
969
109229059713337
*/
