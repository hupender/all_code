#include<bits/stdc++.h>
using namespace std;
const int mod=10000000;
bool visited[mod+1];
vector<int> v[mod+1];

int gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}

void get_one_factor() {
    for(int i=2;i<=mod;i++) {
        if(!visited[i]) {
            int n=i;
            int j=2;
            while(n<=mod) {
                if(!visited[n]) {
                    v[n].push_back(i);
                    visited[n]=true;
                }
                n=i*j;
                j++;    
            }
        }
    }
    for(int i=2;i<=mod;i++) {
        int k=i/v[i][0];
        if(k!=1) {
            for(int j=0;j<v[k].size();j++) {
                if(v[i][0]!=v[k][j]) {
                    v[i].push_back(v[k][j]);
                }
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
    
    memset(visited,false,sizeof(visited));
    get_one_factor();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"\n";
    #endif
    int t;
    cin>>t;
        while(t--) {
        int x,y;
        cin>>x>>y;
        int d=abs(x-y);
        if(d==1) {
            cout<<"-1\n";
        }
        else {
            if(gcd(x,y)>1) {
                cout<<"0\n";
            }
            else {
                int sma=INT_MAX;
                for(auto i:v[d]) {
                    int r=x%i;
                    int a=i-r;
                    sma=min(sma,a);
                }
                cout<<sma<<"\n";
            }
        }
    }
    
    // for(int i=2;i<n;i++) {
    //     int k=v[i].size();
    //     cout<<i<<" : ";
    //     for(int j=0;j<k;j++) {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // #ifndef ONLINE_JUDGE
    //     clock_t clock_end = clock();
    //     cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms";
    // #endif
}