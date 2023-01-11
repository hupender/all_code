#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
bool is_valid(int n) {
    if(n%3==0 || n%10==3) {
        return false;
    }
    return true;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[1001];
    a[0]=0;
    int n=1;
    for(int i=1;i<1001;i++) {
        if(is_valid(n)) {
            a[i]=n;
        }
        else {
            while(!is_valid(n)) {
                n++;
            }
            a[i]=n;
        }
        n++;
    }
    int t;
    cin>>t;
    while(t--) {
        int k;
        cin>>k;
        cout<<a[k]<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}