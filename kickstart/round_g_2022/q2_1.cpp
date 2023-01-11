#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
float get_distance(float x,float y) {
    return sqrt(x*x+y*y);
}
void solve(int t) {
    float rs,rh;
    cin>>rs>>rh;
    float d=rs+rh;
    int n;
    cin>>n;
    vector<float> red;
    for(int i=0;i<n;i++) {
        float x,y;
        cin>>x>>y;
        red.push_back(get_distance(x,y));
    }
    sort(red.begin(),red.end());
    int m;
    cin>>m;
    vector<float> yellow;
    for(int i=0;i<m;i++) {
        float x,y;
        cin>>x>>y;
        yellow.push_back(get_distance(x,y));
    }
    sort(yellow.begin(),yellow.end());
    if(n==0 && m==0) {
        cout<<"Case #"<<t<<": "<<"0 "<<"0"<<endl;
    }
    else if(n==0) {
        int count=0;
        for(int i=0;i<m;i++) {
            if(yellow[i]<=d) {
                count++;
            }
        }
        cout<<"Case #"<<t<<": "<<"0 "<<count<<endl;
    } 
    else if(m==0) {
        int count=0;
        for(int i=0;i<n;i++) {
            if(red[i]<=d) {
                count++;
            }
        }
        cout<<"Case #"<<t<<": "<<count<<" 0"<<endl;
    }
    else {
        if(red[0]<yellow[0]) {
            int count=0;
            for(int i=0;i<n;i++) {
                if(red[i]<yellow[0] && red[i]<=d) {
                    count++;
                }
            }
            cout<<"Case #"<<t<<": "<<count<<" 0"<<endl;
        }
        else {
            int count=0;
            for(int i=0;i<m;i++) {
                if(yellow[i]<red[0] && yellow[i]<=d) {
                    count++;
                }
            }
            cout<<"Case #"<<t<<": "<<"0 "<<count<<endl;
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
    for(int i=1;i<=t;i++) {
        solve(i);
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}