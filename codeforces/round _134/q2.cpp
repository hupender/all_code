#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> get_laser_area(int n,int m,int a,int b,int d) {
    vector<vector<int>> v(n,vector<int> (m,1));
    int l=b-d-1;
    int r=b+d-1;
    int top=a-1;
    int bot=a-1;
    while(l<=r) {
        int st=l,end=r;
        if(l<0) {
            st=0;
        }
        if(r>=m) {
            end=m-1;
        }
        if(top>=0) {
            for(int i=st;i<=end;i++) {
                v[top][i]=0;
            }
        }
        if(bot<n) {
            for(int i=st;i<=end;i++) {
                v[bot][i]=0;
            }
        }
        l++;
        r--;
        top--;
        bot++;
    }
    return v;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,m,a,b,d;
        cin>>n>>m>>a>>b>>d;
        vector<vector<int>> v=get_laser_area(n,m,a,b,d);
        queue<pair<int,int>> q;
        map<pair<int,int>,bool> visited;
        if(v[0][0]==1) {
            q.push({0,0});
            visited[{0,0}]=true;
        }
        
        int flag=0;
        int count=0;
        while(!q.empty()) {
            int size=q.size();
            count++;
            while(size--) {
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x==n-1 && y==m-1) {
                    flag=1;
                    break;
                }
                if(x-1>=0 && !visited[{x-1,y}] && v[x-1][y]==1) {
                    q.push({x-1,y});
                    visited[{x-1,y}]=true;
                }
                if(x+1<n && !visited[{x+1,y}] && v[x+1][y]==1) {
                    q.push({x+1,y});
                    visited[{x+1,y}]=true;
                }
                if(y-1>=0 && !visited[{x,y-1}] && v[x][y-1]==1) {
                    q.push({x,y-1});
                    visited[{x,y-1}]=true;
                }
                if(y+1<m && !visited[{x,y+1}] && v[x][y+1]==1) {
                    q.push({x,y+1});
                    visited[{x,y+1}]=true;
                }
            }
            if(flag) {
                break;
            }
        }
        if(flag) {
            // cout<<"yes"<<endl;
            cout<<count-1<<endl;
        }
        else {
            // cout<<"no"<<endl;
            cout<<"-1"<<endl;
        }

        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
}