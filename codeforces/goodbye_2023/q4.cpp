#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<vector<string>> v;
void solve() {
    vector<string> a,b;
    a.push_back("1");
    b.push_back("169");
    b.push_back("196");
    b.push_back("961");
    v.push_back(a);
    v.push_back(b);
    for(int i=2;i<50;i++) {
        vector<string> v1;
        v1=v[i-1];
        int n=2*i+1;
        int num_zero=i-1;
        string s1,s2;
        s1.push_back('1');
        s2.push_back('9');
        for(int j=0;j<num_zero;j++) {
            s1.push_back('0');
            s2.push_back('0');
        }
        s1.push_back('6');
        s2.push_back('6');
        for(int j=0;j<num_zero;j++) {
            s1.push_back('0');
            s2.push_back('0');
        }
        s1.push_back('9');
        s2.push_back('1');
        for(int i=0;i<v1.size();i++) {
            v1[i].push_back('0');
            v1[i].push_back('0');
        }
        v1.push_back(s1);
        v1.push_back(s2);
        v.push_back(v1);
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
    solve();
    while(t--) {
        int n;
        cin>>n;
        int m=(n-1)/2;
        for(int i=0;i<v[m].size();i++) {
            cout<<v[m][i]<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}