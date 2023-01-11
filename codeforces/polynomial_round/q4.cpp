#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    vector<int> v1;
    int count=0;
    for(int i=0;i<n;i++) {
        int count1=0;
        vector<int> v3;
        for(int j=0;j<m;j++) {
            int k;
            cin>>k;
            v3.push_back(k);
            if(k==1) {
                count++;
                count1++;
            }
        }
        v1.push_back(count1);
        v.push_back(v3);
    }
    if(count%n==0) {
        // first vector // then count of one and then index
        vector<pair<vector<int>,pair<int,int>>> donor;
        vector<pair<vector<int>,pair<int,int>>> receiver;
        int req=count/n;
        for(int i=0;i<n;i++) {
            if(v1[i]>req) {
                donor.push_back({v[i],{v1[i],i}});
            }
            else if(v1[i]<req) {
                receiver.push_back({v[i],{v1[i],i}});
            }
        }
        vector<vector<int>> ans;
        int dsize=donor.size();
        int rsize=receiver.size();
        for(int i=0;i<dsize;i++) {
            vector<int> s1=donor[i].first;
            int c1=donor[i].second.first;
            for(int j=0;j<rsize;j++) {
                int c2=receiver[j].second.first;
                if(c2<req) {
                    vector<int> s2=receiver[j].first;
                    for(int k=0;k<m;k++) {
                        vector<int> ans1;
                        if(s1[k]==1 && s2[k]==0) {
                            donor[i].first[k]=0;
                            receiver[j].first[k]=1; 
                            c1--;
                            c2++;
                            ans1.push_back(donor[i].second.second+1);
                            ans1.push_back(receiver[j].second.second+1);
                            ans1.push_back(k+1);
                        }
                        if(ans1.size()>0) {
                            ans.push_back(ans1);
                        }
                        
                        if(c1==req || c2==req) {
                            break;
                        }
                    }
                    receiver[j].second.first=c2;
                }
                if(c1==req) {
                    break;
                }
            }
        }
        int r1=ans.size();
        cout<<r1<<endl;
        for(int i=0;i<r1;i++) {
            for(int j=0;j<3;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
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