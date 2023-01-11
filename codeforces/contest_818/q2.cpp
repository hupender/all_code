#include<bits/stdc++.h>
using namespace std;
void fill_row(vector<vector<char>>& v,int r,int c,int k) {
    int n=v.size();
    int col=c;
    while(col>=0) {
        if(col<n) {
            v[r][col]='X';
        }
        col-=k;
    }
    while(c<n) {
        if(c>=0) {
            v[r][c]='X';
        }
        c+=k;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,k,r,c;
        cin>>n>>k>>r>>c;
        vector<vector<char>> v(n,vector<char> (n,'.'));
        int row=r-1,col=c-1;
        while(row>0) {
            row-=k;
        }

        while(row<n) {
            if(row>=0) {
                fill_row(v,row,col,k);
            }
            row++;
            col++;
        }


        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<v[i][j];
            }
            cout<<endl;
        }
    }
}