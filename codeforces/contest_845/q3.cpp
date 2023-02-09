#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<int> get_factor(int n,int m) {
    vector<int> v;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0 && i<=m) {
            v.push_back(i);
        }
    }
    if(v.size()==1 && n<=m) {
        v.push_back(n);
    }
    return v;
}
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    vector<vector<int>> v;
    for(int i=0;i<n;i++) {
        vector<int> v1=get_factor(a[i],m);
        v.push_back(v1);
    }
    map<int,int> map1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<v[i].size();j++) {
            map1[v[i][j]]++;
        }   
    }
    if(map1.size()==m) {
        int flag1=1,flag2=1;
        int st=0,end=n-1;
        int res;
        while(true) {
            // firstly check if we can ignore the first element
            for(int i=0;i<v[st].size();i++) {
                if(map1[v[st][i]]<=1) {
                    flag1=0;
                }
            }

            // second check if we can leave the last
            for(int i=0;i<v[end].size();i++) {
                if(map1[v[end][i]]<=1) {
                    flag2=0;
                }
            }
            // if we can remove both check which one is more benificial
            if(flag1 && flag2) {
                int diff1=a[end-1]-a[st];
                int diff2=a[end]-a[st+1];
                if(diff1<diff2) {
                    end--;
                }
                else {
                    st++;
                }
            }
            else if(flag1) {
                st++;
            }
            else if(flag2) {
                end--;
            }
            else {
                res=a[end]-a[st];
                break;
            }
        }
        cout<<res<<endl;
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