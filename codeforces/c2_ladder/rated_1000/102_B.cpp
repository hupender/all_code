#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<int> get_factor(int n) {
    vector<int> v;
    for(int i=1;i<=n;i++) {
        if(n%i==0) {
            v.push_back(i);
        }
    }
    return v;
}
string get_root(string s) {
    int n=s.size();
    vector<int> v=get_factor(n);
    int len;
    for(int i=0;i<v.size();i++) {
        string s1;
        int fact=n/v[i];
        while(fact--) {
            for(int j=0;j<v[i];j++) {
                s1.push_back(s[j]);
            }
        }
        if(s==s1) {
            len=v[i];
            break;
        }
    }
    string s2;
    for(int i=0;i<len;i++) {
        s2.push_back(s[i]);
    }
    return s2;
}
int get_hcf(int a,int b) {
    if(b==0) {
        return a;
    }
    return get_hcf(b,a%b);
}
void solve() {
    string s1,s2;
    cin>>s1>>s2;
    string r1=get_root(s1);
    string r2=get_root(s2);
    if(r1==r2) {
        int a=s1.size()/r1.size();
        int b=s2.size()/r2.size();
        int h=get_hcf(a,b);
        int gcd=(a*b)/h;
        while(gcd--) {
            cout<<r1;
        }
        cout<<endl;
    }
    else {
        cout<<"-1"<<endl;
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