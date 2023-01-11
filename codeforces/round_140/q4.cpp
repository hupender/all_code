#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int power(int a,int b) {
    int res=1;
    while(b--) {
        res*=a;
    }
    return res;
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count_zero=0,count_one=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            count_one++;
        }
    }
    count_zero=n-count_one;
    int p=power(2,n);
    int st;
    st=power(2,count_one);
    st--;
    // if(count_one==0) {
    //     st=0;
    // }
    // else if(count_one==1) {
    //     st=1;
    // }
    // else {
    //     st=1+power(2,count_one-1);
    // }
    int end;
    end=power(2,count_zero);
    end--;
    // if(count_zero==0) {
    //     end=0;
    // }
    // else if(count_zero==1) {
    //     end=1;
    // }
    // else {
    //     end=1+power(2,count_zero-1);
    // }

    if(count_one==0) {
        cout<<"1"<<endl;
    }
    else if(count_zero==0) {
        cout<<p<<endl;
    }
    else {
        for(int i=st+1;i<=p-end;i++) {
            cout<<i<<" ";
        }
        cout<<endl;
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
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}