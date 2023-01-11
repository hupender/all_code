#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++) {
            int sum=nums[0];
            int count=1;
            while(sum<=queries[i] && count<nums.size()) {
                sum+=nums[count];
                count++;
            }
            // cout<<"count is "<<count;
            if(sum<=queries[i] && count==nums.size()) {
                ans.push_back(count);
            }
            else {
                ans.push_back(count-1);
            }

            // ans.push_back(count-1);
        }
        return ans;
    }
};
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    vector<int> queries(m);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    for(int i=0;i<m;i++) {
        cin>>queries[i];
    }
    Solution s;
    vector<int> ans=s.answerQueries(nums,queries);
    cout<<"fianl answer"<<endl;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}