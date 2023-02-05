#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    int count_odd=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]%2!=0) {
            count_odd++;
        }
    }
    int count_even=n-count_odd;
    if(count_even==0) {
        cout<<"YES"<<endl;
        cout<<"1 2 3"<<endl;
    }
    else if(count_even==1) {
        if(n==3) {
            cout<<"NO"<<endl;
        }
        else {
            int count=3;
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++) {
                if(count && a[i]%2!=0) {
                    cout<<i+1<<" ";
                    count--;
                }
            }
            cout<<endl;
        }
    }
    else {
        if(count_odd==0) {
            cout<<"NO"<<endl;
        }
        else {
            int count1=1,count2=2;
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++) {
                if(count2 && a[i]%2==0) {
                    cout<<i+1<<" ";
                    count2--;
                }
                else if(count1 && a[i]%2!=0) {
                    cout<<i+1<<" ";
                    count1--;
                }
            }
            cout<<endl;
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