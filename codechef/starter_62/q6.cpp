#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        int count2=0;
        while(n%2==0) {
            n=n/2;
            count2++;
        }
        int p=count2/2;
        if(count2%2!=0) {
            n=n*2;
        }
        int flag=0;
        long long a,b;
        for(int i=0;i*i<=n;i++) {
            int q=n-i*i;
            int x=sqrt(q);
            if(x*x==q) {
                flag=1;
                a=i;
                b=x;
                break;
            }
        }
        if(flag==0) {
            cout<<"-1"<<endl;
        }
        else {
            while(p--) {
                a=a*2;
                b=b*2;
            }
            cout<<a<<" "<<b<<endl;
        }
    }
}