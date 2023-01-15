#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int search(vector<pair<int,int>> &v,int a,int b) {
    //     int n=v.size();
    //     int low=0,high=n-1;
    //     while(low<high) {
    //         int mid=(low+high)/2;
    //         if()
    //     }
    // }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v(n,vector<int>(n,0));
        int q=queries.size();
        vector<pair<int,int>> lower;
        vector<pair<int,int>> upper;
        for(int i=0;i<q;i++) {
            lower.push_back({queries[i][0],queries[i][1]});
            upper.push_back({queries[i][2],queries[i][3]});
        }

    }
};