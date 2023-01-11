#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,q;
    cin>>n>>q;
    char a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    int count_first_row=0;
    int ind;
    for(int i=0;i<n;i++) {
        if(a[i][0]=='O') {
            count_first_row++;
            ind=i;
        }
    }
    vector<vector<pair<int,int>>> all_path;
    vector<int> v;
    if(count_first_row>2) {
        
        for(int k=0;k<n;k++) {
            if(a[0][k]=='O') {
                queue<pair<int,int>> q;
                q.push({0,k});
                vector<vector<bool>> visited(n,vector<bool>(n,false));

                visited[0][k]=true;
                int side=1;   // 1 for vertical and 2 for horizontal
                int dis=1;
                vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>> (n));
                vector<pair<pair<int,int>,int>> end;
                pair<int,int> p1={-1,-1};
                parent[0][k]=p1;
                while(!q.empty()) {
                    int size=q.size();
                    for(int i=0;i<size;i++) {
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        if(side==1) {
                            // vertical
                            for(int j=0;j<n;j++) {
                                if(!visited[j][y] && a[j][y]=='O') {
                                    if(j==0) {
                                        end.push_back({{j,y},dis});
                                    }
                                    parent[j][y]={x,y};
                                    q.push({j,y});
                                    visited[j][y]=true;
                                }
                            }
                            side=2;
                            dis++;
                        }
                        else {
                            // horizontal
                            for(int j=0;j<n;j++) {
                                if(!visited[x][j] && a[x][j]=='O') {
                                    q.push({x,j});
                                    visited[x][j]=true;
                                    parent[x][j]={x,y};
                                }
                            }
                            side=1;
                            dis++;
                        }
                    }
                    // check if end khali hai kya
                }
                for(int i=0;i<end.size();i++) {
                    int a=end[i].first.first;
                    int b=end[i].first.second;
                    // map<<pair<int,int>,int>> path;
                    vector<pair<int,int>> path;
                    pair<int,int> p={-1,-1};
                    path.push_back({a,b});
                    while(parent[a][b]!=p) {
                        a=parent[a][b].first;
                        b=parent[a][b].second;
                        path.push_back(parent[a][b]);
                    }
                    all_path.push_back(path);
                    v.push_back(end[i].second);
                }
            }
        }
    }
    while(q--) {
        int x,y;
        cin>>x>>y;
        a[x-1][y-1]='X';
        int mi=INT_MAX;
        pair<int,int> p={x-1,y-1};
        for(int i=0;i<all_path.size();i++) {
            int flag=1;
            for(int j=0;j<all_path[i].size();j++) {
                if(all_path[i][j]==p) {
                    flag=0;
                }
            }
            if(flag) {
                mi=min(mi,v[i]);
            }
        }
        cout<<mi<<endl;
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
    // int t;
    // cin>>t;
    // while(t--) {
    solve();
    // }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}