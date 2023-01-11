    #include<bits/stdc++.h>
    using namespace std;
    int unequalTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            m[nums[i]]++;
        }
        int distinct=m.size();
        int count=0;
        for(int i=0;i<n-2;i++) {
            m[nums[i]]--;
            int res=1;
            for(auto j:m) {
                if(j.first!=nums[i] && j.second!=0) {
                    res*=j.second;
                }
            }
            if(distinct>2) {
                count+=res*((distinct-1)*(distinct-2))/2;
            }
            if(m[nums[i]]==0) {
                distinct--;
            }
        }
        return count;
    }
    int main() {
        vector<int> v={1,2,3,3,4};
        int ans=unequalTriplets(v);
        cout<<ans<<endl;
    }