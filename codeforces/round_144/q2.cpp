#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    string a,b;
    cin>>a>>b;
    int n1=a.size();
    int n2=b.size();
    string res;
    if(n1==1 && n2==1 && a[0]==b[0]) {
        cout<<"YES"<<endl;
        cout<<a<<endl;
    }
    else if(n1==1 || n2==1) {
        if(a[0]==b[0]) {
            res.push_back(a[0]);
            res.push_back('*');
            cout<<"YES"<<endl;
            cout<<res<<endl;
        }
        else if(a[n1-1]==b[n2-1]) {
            res.push_back('*');
            res.push_back(a[n1-1]);
            cout<<"YES"<<endl;
            cout<<res<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    else if(a[0]==b[0]) {
        res.push_back(a[0]);
        res.push_back('*');
        cout<<"YES"<<endl;
        cout<<res<<endl;
    }
    else if(a[n1-1]==b[n2-1]) {
        res.push_back('*');
        res.push_back(a[n1-1]);
        cout<<"YES"<<endl;
        cout<<res<<endl;
    }
    else {
        unordered_map<string,int> map1;
        for(int i=0;i<n1-1;i++) {
            string s1;
            s1.push_back(a[i]);
            s1.push_back(a[i+1]);
            map1[s1]++;
        }
        int flag=0;
        string res;
        for(int i=0;i<n2-1;i++) {
            string s1;
            s1.push_back(b[i]);
            s1.push_back(b[i+1]);
            if(map1[s1]>0) {
                flag=1;
                res.push_back('*');
                res.push_back(b[i]);
                res.push_back(b[i+1]);
                res.push_back('*');
                break;
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
            cout<<res<<endl;
        }
        else {
            cout<<"NO"<<endl;
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