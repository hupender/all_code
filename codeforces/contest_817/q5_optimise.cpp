#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,q;
        cin>>n>>q;
        vector<pair<int,int>> v;
        ll total_area=0;
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            total_area+=a*b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        vector<vector<ll>> p;
        int k=0,count=0;
        ll area=0;
        for(int i=0;i<1001;i++) {
            vector<ll> x;
            k=0;
            area=0;
            for(int j=0;j<1001;j++) {
                if(k<n && i>v[k].first && j>v[k].second) {
                    while(k<n && i>v[k].first && j>v[k].second) {
                        area+=v[k].first*v[k].second;
                        k++;
                    }
                    x.push_back(area);
                }
                else {
                    x.push_back(area);
                }
            }
            p.push_back(x);
        }
        // while(k<n) {
        //     if(v[k].first<1000 && v[k].second<1000) {
        //         p[1000][1000]+=v[k].first*v[k].second;
        //         cout<<p[1000][1000]<<endl;
        //     }
        //     k++;
        // }
        vector<vector<ll>> r(1001 , vector<ll> (1001,0));
        k=n-1,area=0;
        for(int i=100;i>=0;i--) {
            for(int j=100;j>=0;j--) {
                if(k>=0 && i<v[k].first && j<v[k].second) {
                    area+=v[k].first*v[k].second;
                    k--;
                }
                r[i][j]=area;
            }
        }

        // for(int i=0;i<1001;i++) {
        //     for(int j=0;j<1001;j++) {
        //         // if(p[i][j]!=0) {
        //             cout<<i<<" "<<j<<" "<<p[i][j]<<endl;
        //         // }
        //     }
        // }

        while(q--) {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a>c && b>d) {
                ll area1=p[a][b];
                ll fuck_area=total_area-r[c][d];
                ll result=area1-fuck_area;
                if(result<0) {
                    cout<<"0"<<endl;
                }
                else {
                    cout<<result<<endl;
                }
            }
            else if(c>a && d>b) {
                ll area1=p[c][d];
                int area2=r[a][b];
                ll fuck_area=total_area-area2;
                ll result=area1-fuck_area;
                if(result<0) {
                    cout<<"0"<<endl;
                }
                else {
                    cout<<result<<endl;
                }
            }
            else {
                cout<<"0"<<endl;
            }
        }
    }
}