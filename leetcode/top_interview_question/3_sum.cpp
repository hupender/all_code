#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum1(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m1;
        for(int i=0;i<n;i++) {
            m1[nums[i]]++;
        }
        vector<int> v;
        for(auto i:m1) {
            v.push_back(i.first);   
        }
        sort(v.begin(),v.end());
        
        vector<vector<int>> res;
        for(auto &i:m1) {
            if(i.second>1) {
                int rem=-2*(i.first);
                i.second-=2;
                if(m1[rem]>0) {
                    res.push_back({i.first,i.first,rem});
                }
                i.second+=2;
            }
        }
        
        int n1=v.size();
        map<vector<int>,int> m;
        
        for(int i=0;i<n1-2;i++) {
            unordered_map<int,int> m2;
            for(int j=i+1;j<n1;j++) {
                m2[v[j]]++;
            }
            for(int j=i+1;j<n1-1;j++) {
                m2[v[j]]--;
                int rem=-(v[i]+v[j]);
                if(m2[rem]>0) {
                    vector<int> v1;
                    v1.push_back(v[i]);
                    v1.push_back(v[j]);
                    v1.push_back(rem);
                    m[v1]++;
                }
            }
        }
        for(auto i:m) {
            res.push_back(i.first);
        }
        return res;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<vector<int>> v;
        // int n=nums.size();
        // map<vector<int>,int> m;
        // for(int i=0;i<n-2;i++) {
        //     for(int j=i+1;j<n-1;j++) {
        //         for(int k=j+1;k<n;k++) {
        //             if(nums[i]+nums[j]+nums[k]==0) {
        //                 vector<int> v1;
        //                 v1.push_back(nums[i]);
        //                 v1.push_back(nums[j]);
        //                 v1.push_back(nums[k]);
        //                 m[v1]++;
        //             }
        //         }
        //     }
        // }
        // for(auto i:m) {
        //     v.push_back(i.first);
        // }
        // return v;
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        // vector<pair<pair<int,int>,int>> v;
        int n=nums.size();
        // map<vector<int>,int> m;
        for(int i=0;i<n-2;i++) {
            unordered_map<int,int> m1;
            for(int j=i+1;j<n;j++) {
                m1[nums[j]]++;
            }
            for(int j=i+1;j<n-1;j++) {
                m1[nums[j]]--;
                int rem=-(nums[i]+nums[j]);
                if(m1[rem]>0) {
                    vector<int> v1;
                    v1.push_back(nums[i]);
                    v1.push_back(nums[j]);
                    v1.push_back(rem);
                    // m[v1]++;
                    v.push_back(v1);
                    // int a=nums[i];
                    // int b=nums[j];
                    // int c=rem;
                    // v.push_back({{a,b},c});
                }
            }
        }
        // for(auto i:m) {
        //     v.push_back(i.first);
        // }

        vector<vector<int>> res;
        // sort(v.begin(),v.end());
        int size=v.size();
        for(int i=0;i<size-1;i++) {
            // pair<pair<int,int>,int> p1=v[i];
            // pair<pair<int,int>,int> p2=v[i+1];
            int flag=0;
            for(int j=0;j<3;j++) {
                if(v[i][j]!=v[i+1][j]) {
                    flag=1;
                    break;
                }
            }
            // if(p1==p2) {
            //     flag=1;
            // }
            if(flag) {
                vector<int> v1;
                for(int j=0;j<3;j++) {
                    v1.push_back(v[i][j]);
                }
                res.push_back(v1);
                
                // v1.push_back(v[i].first.first);
                // v1.push_back(v[i].first.second);
                // v1.push_back(v[i].second);
                // res.push_back(v1);
            }
        }
        if(size) {
            vector<int> v1;
            for(int j=0;j<3;j++) {
                v1.push_back(v[size-1][j]);
                
            }
            res.push_back(v1);
            // v1.push_back(v[size-1].first.first);
            // v1.push_back(v[size-1].first.second);
            // v1.push_back(v[size-1].second);
            // res.push_back(v1);
        }
        return res;
    }
};
int main() {
    #ifndef hupi
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    vector<vector<int>> res=s.threeSum1(v);
    for(int i=0;i<res.size();i++) {
        for(int j=0;j<3;j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}