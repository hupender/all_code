#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;     
    while(t--) {
        int n,q;
        cin>>n>>q;
        vector<pair<int,int>> rec;
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            rec.push_back({a,b});
        }
        vector<vector<int>> query;
        for(int i=0;i<q;i++) {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            query.push_back({a,b,c,d});
        }
        for(int i=0;i<q;i++) {
            int a=query[i][0];
            int b=query[i][1];
            int c=query[i][2];
            int d=query[i][3];
            long long sum=0;
            for(int j=0;j<n;j++) {
                int x=rec[j].first;
                int y=rec[j].second;
                if(x>a && y>b && x<c && y<d) {
                    sum+=x*y;
                }
                else if(x<a && y<b && x>c && y>d) {
                    sum+=x*y;
                }
            }
            cout<<sum<<endl;
        }
    }
}