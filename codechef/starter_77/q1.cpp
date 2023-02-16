#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void check_valid(int n,int m,unordered_map<char,ll> &map1,unordered_map<char,ll> &map2) {
    int flag=1;
    for(auto i:map2) {
        if(i.second>map1[i.first]) {
            flag=0;
            break;
        }
        else {
            map1[i.first]-=i.second;
        }
    }
    if(flag) {
        n-=m;
        if(n%2==0) {
            for(auto i:map1) {
                if(i.second%2!=0) {
                    flag=0;
                }
            }
            if(flag) {
                cout<<"YES"<<endl;
            }
            else 
            {
                cout<<"NO"<<endl;
            }
        }
        else {
            int count=0;
            for(auto i:map1) {
                if(i.second%2!=0) {
                    count++;
                }
            }
            if(count==1) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
    }
    else {
        cout<<"NO"<<endl;
    }
}
void solve() {
    ll n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    unordered_map<char,ll> map1,map2;
    for(int i=0;i<n;i++) {
        map1[s1[i]]++;
    }
    for(int i=0;i<m;i++) {
        map2[s2[i]]++;
    }
    if(n==m) {
        int flag=1;
        for(auto i:map1) {
            if(i.second!=map2[i.first]) {
                flag=0;
                break;
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    else if(n>m) {
        check_valid(n,m,map1,map2);
    }
    else {
        check_valid(m,n,map2,map1);
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