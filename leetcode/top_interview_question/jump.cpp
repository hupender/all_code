#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();
        int dp[n];
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--) {
            int min_val=1e5;
            for(int j=1;j<=a[i] && i+j<n;j++) {
                min_val=min(min_val,dp[i+j]);
            }
            dp[i]=1+min_val;
        }
        return dp[0];
    }
};
int main()  {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    Solution s;
    cout<<s.jump(v)<<endl;
}