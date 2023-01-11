#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    float x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    unordered_map<int,int> m;
    m[abs(y2-y1)]++;
    m[abs(y2-y3)]++;
    m[abs(y1-y3)]++;
    m[abs(x1-x2)]++;
    m[abs(x1-x3)]++;
    m[abs(x2-x3)]++;
    if(m[0]>1) {
        cout<<"No"<<endl;
    }
    else {
        cout<<"Yes"<<endl;
    }
    // float m1=1.0*(y2-y1)/(x2-x1);
    // float m2=1.0*(y3-y2)/(x3-x2);
    // float m3=1.0*(y3-y1)/(x3-x1);
    // if(m1==0) {
    //     if(m2==1 || m3==1) {
    //         cout<<"No"<<endl;
    //     }
    //     else {
    //         cout<<"Yes"<<endl;
    //     }
    // }
    // else if(m2==0) {
    //     if(m1==1 || m3==1) {
    //         cout<<"No"<<endl;
    //     }
    //     else {
    //         cout<<"Yes"<<endl;
    //     }
    // }
    // else if(m3==0) {
    //     if(m1==1 || m2==1) {
    //         cout<<"No"<<endl;
    //     }
    //     else {
    //         cout<<"Yes"<<endl;
    //     }
    // }
    // else {
    //     cout<<"Yes"<<endl;
    // }
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