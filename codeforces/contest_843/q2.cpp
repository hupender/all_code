#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]=='a') {
        int ind=-1;
        for(int i=0;i<n-1;i++) {
            if(s[i]=='b') {
                ind=i;
                break;
            }
        }
        if(ind!=-1) {
            string a,b,c;
            for(int i=0;i<ind;i++) {
                a.push_back(s[i]);
            }
            for(int i=ind;i<n-1;i++) {
                b.push_back(s[i]);
            }
            c.push_back(s[n-1]);
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else {
            string a,b,c;
            a.push_back(s[0]);
            b.push_back(s[1]);
            for(int i=2;i<n;i++) {
                c.push_back(s[i]);
            }
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }
    else {
        int ind=-1;
        for(int i=0;i<n-1;i++) {
            if(s[i]=='a') {
                ind=i;
                break;
            }
        }
        if(ind!=-1) {
            string a,b,c;
            for(int i=0;i<ind;i++) {
                a.push_back(s[i]);
            }
            b.push_back(s[ind]);
            for(int i=ind+1;i<n;i++) {
                c.push_back(s[i]);
            }
            // c.push_back(s[n-1]);
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else {
            string a,b,c;
            a.push_back(s[0]);
            b.push_back(s[1]);
            for(int i=2;i<n;i++) {
                c.push_back(s[i]);
            }
            cout<<a<<" "<<b<<" "<<c<<endl;
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