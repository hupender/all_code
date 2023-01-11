#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("inputb2_1.txt","r",stdin);
    freopen("outputb2.txt","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        int r,c,count=0;
        cin>>r>>c;
        vector<vector<char>> v;
        //int tree[r][c];
        //memset(tree,0,sizeof(tree));
        
        vector<vector<int>> tree(r, vector<int>(c, 0));
        
        for(int i=0;i<r;i++) {
            vector<char> v1;
            for(int j=0;j<c;j++) {
                char c;
                cin>>c;
                v1.push_back(c);
                if(c=='^') {
                    tree[i][j]=1;
                    count++;
                }
            }
            v.push_back(v1);
            v1.clear();
        }
        if(r==1 || c==1) {
            if(count>0) {
                cout<<"Case #"<<z<<": Impossible"<<endl;
            }
            else {
                cout<<"Case #"<<z<<": Possible"<<endl;
                for(int i=0;i<r;i++) {
                    for(int j=0;j<c;j++) {
                        cout<<v[i][j];
                    }
                    cout<<endl;
                }
            }
        }
        else {
            for(int i=0;i<r;i++) {
                for(int j=0;j<c;j++) {
                    if(v[i][j]!='#') {
                        v[i][j]='^';
                    }
                }
            }
            vector<vector<int>> m(r,vector<int> (c,0));
            for(int i=0;i<r;i++) {
                for(int j=0;j<c;j++) {
                    if(v[i][j]=='^') {
                        if(i-1>=0 && v[i][j]==v[i-1][j]) {
                            m[i][j]++;
                        } 
                        if(i+1<=r-1 && v[i][j]==v[i+1][j]) {
                            m[i][j]++;
                        }
                        if(j-1>=0 && v[i][j]==v[i][j-1]) {
                            m[i][j]++;
                        }
                        if(j+1<=c-1 && v[i][j]==v[i][j+1]) {
                            m[i][j]++;
                        }
                    }
                    if(v[i][j]=='#') {
                        m[i][j]=-1;
                    }
                }
            }
            int x=5;
            while(x--) {
                for(int i=0;i<r;i++) {
                    for(int j=0;j<c;j++) {
                        if(m[i][j]==1) {
                            m[i][j]=0;
                            if(i-1>=0 && m[i-1][j]>0) {
                                m[i-1][j]--;
                            } 
                            if(i+1<=r-1 && m[i+1][j]>0) {
                                m[i+1][j]--;
                            }
                            if(j-1>=0 && m[i][j-1]>0) {
                                m[i][j-1]--;
                            }
                            if(j+1<=c-1 && m[i][j+1]>0) {
                                m[i][j+1]--;
                            }
                        }
                    }
                }
            }
            int flag=0;
            for(int i=0;i<r;i++) {
                for(int j=0;j<c;j++) {
                    if(tree[i][j]==1 && m[i][j]<2) {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1) {
                cout<<"Case #"<<z<<": Impossible"<<endl;
            }
            else {
                cout<<"Case #"<<z<<": Possible"<<endl;
                for(int i=0;i<r;i++) {
                    for(int j=0;j<c;j++) {
                        if(m[i][j]==-1) {
                            cout<<"#";
                        }
                        else if(m[i][j]>=2) {
                            cout<<"^";
                        }
                        else {
                            cout<<".";
                        }
                    }
                    cout<<endl;
                }
            }
        }
    }
}