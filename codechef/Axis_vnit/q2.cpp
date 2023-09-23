#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int x;
    cin>>x;
    int a,b,c;
    cin>>a>>b>>c;
    int d,e,f;
    cin>>d>>e>>f;
    int g,h,i;
    cin>>g>>h>>i;
    int m1=min({a,b,c});
    int m2=min({d,e,f});
    int m3=min({g,h,i});
    vector<int> v;
    v.push_back(m1);
    v.push_back(m2);
    v.push_back(m3);
    sort(v.begin(),v.end());
    int count=0;
    for(int i=0;i<3;i++) {
        if(v[i]<=x) {
            count++;
            x-=v[i];
        }
        else {
            break;
        }
    }
    cout<<count<<endl;
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