#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        vector<pair<map<int,int>,int>> v;
        int n=nums.size();
        int k1=k;
        map<int,int> m;
        int count=0;
        for(int i=0;i<n;i++) {
            m[k]++;
            if(k>0) {
                k-=(m[k]-1);
                count+=(m[k]-1);
                if(k<0) {
                    v.push_back({m,count});
                }
            }
            else {
                count+=(m[k]-1);
                v.push_back({m,count});
            }
        }
        long long res=v.size();
        for(int i=0;i<n-1;i++) {
            
        }
    }
};