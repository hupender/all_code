#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    if(n%2==0) {
        cout<<n/2<<" "<<n/2<<endl;
    }
    else {
        if(n%10==9) {
            int n1=n;
            int sum=0;
            while(n1) {
                sum+=n1%10;
                n1/=10;
            }
            sum/=2;
            n1=n;
            int num1,num2;
            int count=0;
            while(sum) {
                int r=n1%10;
                if(sum>r) {
                    count++;
                    sum-=r;
                }
                else {
                    num1=n1-sum;
                    sum=0;
                }
                n1/=10;
            }
            while(count--) {
                num1*=10;
            }
            num2=n-num1;
            cout<<num1<<" "<<num2<<endl;
        }
        else {
            int p=n/2;
            cout<<p<<" "<<p+1<<endl;
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}