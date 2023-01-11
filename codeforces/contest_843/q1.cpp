#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve1() {
    string s;
    cin>>s;
    int n=s.size();
    string a;
    int flag=0;
    for(int i=0;i<n-2;i++) {
        a.push_back(s[i]);
        string b;
        for(int j=i+1;j<n-1;j++) {
            b.push_back(s[j]);
            string c;
            for(int k=j+1;k<n;k++) {
                c.push_back(s[k]);
            }
            if((a<=b && c<=b) || (b<=a && b<=c)) {
                cout<<a<<" "<<b<<" "<<c<<endl;
                flag=1;
                break;
            }
        }
        if(flag) {
            break;
        }
    }
}
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    string a,b,c;
    // a+=s[0];
    int flag=0;
    for(int i=0;flag==0 && i<n-2;i++) {
        a.push_back(s[i]);
        for(int j=i+1;j<n-1;j++) {
            b.push_back(s[j]);
            for(int k=j+1;k<n;k++) {
                c.push_back(s[k]);
            }
            if((a<=b && c<=b) || (b<=a && b<=c)) {
                flag=1;
                cout<<a<<" "<<b<<" "<<c<<endl;
                break;
            }
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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}