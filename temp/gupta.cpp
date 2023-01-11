#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fun(vector<vector<int>> after) {
    vector<vector<int>> before;

    int n = after.size();
    int m = after[0].size();
    vector<vector<int>> sum(n, vector<int>(m, 0) );
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0 || j)
            if(i==0) {
                before[i][j]=after[i][j]-sum[i][j-1];
                // sum[i][j]+=before[i][j];
            }
            if(j==0) {
                // sum[i][j]+=
                before[i][j]=after[i][j]-sum[i-1][j];
            }
            before[i][j]=
        }
    }
}