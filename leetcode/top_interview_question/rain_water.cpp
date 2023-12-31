#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 0,1,0,2,1,0,1,3,2,1,2,1
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> previous_just_larger(n,0);
        int max_index=0;
        int max_height=height[0];
        for(int i=1;i<n;i++) {
            int j=i-1;
            while(j>0) {
                if(height[j]>=height[i]) {
                    previous_just_larger[i]=j;
                    break;
                }
                else {
                    j=previous_just_larger[j];
                }
            }
            if(j==0) {
                previous_just_larger[i]=max_index;
            }
            if(height[i]>=max_height){
                max_index=i;
                max_height=height[i];
            }
        }
        vector<int> prefix_sum;
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=height[i];
            prefix_sum.push_back(sum);
        }
        int ans=0;
        vector<int> result(n,0);
        for(int i=2;i<n;i++) {
            int ind=previous_just_larger[i];
            int val=result[ind]+(i-ind-1)*min(height[ind],height[i])-(prefix_sum[i-1]-prefix_sum[ind]);
            if(val<0) {
                val=0;
            }
            result[i]=val;
            ans=max(ans,result[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> h={4,2,0,3,2,5};
    Solution s;
    cout<<s.trap(h)<<endl;
}