#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i=0;i<n-3;i++) {
            int flag=1;
            for(int j=i+1;j<n-2;j++) {
                int sum=nums[i]+nums[j];
                // if(abs(sum)>abs(target)) {
                //     flag=0;
                //     break;
                // }
                // else {
                    int target1=target-sum;
                    int low=j+1,high=n-1;
                    while(low<high) {
                        vector<int> v1;
                        int sum1=nums[low]+nums[high];
                        if(sum1==target1) {
                            v1.push_back(nums[i]);
                            v1.push_back(nums[j]);
                            v1.push_back(nums[low]);
                            v1.push_back(nums[high]);
                            v.push_back(v1);
                            int l=nums[low];
                            while(nums[low]==l) {
                                low++;
                            }
                            int h=nums[high];
                            while(nums[high]==h) {
                                high--;
                            }
                        }

                        else if(sum1<target1) {
                            low++;
                        }
                        else {
                            high--;
                        }
                    }
                // }
            }
            // if(!flag) {
            //     break;
            // }
        }
        return v;
    }
};

int main() {
    #ifndef hupi
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,target;
    cin>>n>>target;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    vector<vector<int>> res=s.fourSum(v,target);
    for(int i=0;i<res.size();i++) {
        for(int j=0;j<4;j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}