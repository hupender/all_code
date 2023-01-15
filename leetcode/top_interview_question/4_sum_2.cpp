#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int search(vector<int>& v,int k) {
    //     int low=0;
    //     int n=v.size();
    //     int high=n-1;
    //     while(low<=high) {
    //         int mid=(low+high)/2;
    //         if(v[mid]==k) {
    //             int count=1;
    //             int ind=mid+1;
    //             while(ind<n && v[ind]==k) {
    //                 count++;
    //                 ind++;
    //             }
    //             int ind1=mid-1;
    //             while(ind1>=0 && v[ind1]==k) {
    //                 count++;
    //                 ind1--;
    //             }
    //             return count;
    //         }
    //         else if(v[mid]<k) {
    //             low=mid+1;
    //         }
    //         else {
    //             high=mid-1;
    //         }

    //     }
    //     return -1;
    // }
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        // int n=nums1.size();
        // int count=0;
        // sort(nums3.begin(),nums3.end());
        // sort(nums4.begin(),nums4.end());
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         int sum=-(nums1[i]+nums2[j]);
        //         int l=0,h=n-1;
        //         while(l<n && h>=int n=nums1.size();
        // int count=0;
        // sort(nums3.begin(),nums3.end());
        // sort(nums4.begin(),nums4.end());
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         for(int k=0;k<n;k++) {
        //             int sum=-(nums1[i]+nums2[j]+nums3[k]);
        //             int res=search(nums4,sum);
        //             if(res>0) {
        //                 count+=res;
        //             }
        //         }
        //     }
        // }
        // return count;0) {
        //             if(nums3[l]+nums4[h]==sum) {
        //                 count++;
        //                 h--;
        //             }
        //             else if(nums3[l]+nums4[h]>sum) {
        //                 h--;
        //             }
        //             else {
        //                 l++;
        //             }
        //         }
        //     }
        // }
        // return count;

        // int n=nums1.size();
        // int count=0;
        // map<int,int> m;
        // for(int i=0;i<n;i++) {
        //     m[nums4[i]]++;
        // }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         for(int k=0;k<n;k++) {
        //             int sum=-(nums1[i]+nums2[j]+nums3[k]);
        //             count+=m[sum];
        //             // if(m[sum]>0) {
        //             //     count++;
        //             // }
        //         }
        //     }
        // }
        // return count;

        // int n=nums1.size();
        // int count=0;
        // sort(nums3.begin(),nums3.end());
        // sort(nums4.begin(),nums4.end());
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         for(int k=0;k<n;k++) {
        //             int sum=-(nums1[i]+nums2[j]+nums3[k]);
        //             int res=search(nums4,sum);
        //             if(res>0) {
        //                 count+=res;
        //             }
        //         }
        //     }
        // }
        // return count;

        int n=nums1.size();
        vector<int> v;
        int count=0;
        // sort(nums3.begin(),nums3.end());
        // sort(nums4.begin(),nums4.end());
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    int sum=-(nums1[i]+nums2[j]+nums3[k]);
                    v.push_back(sum);
                }
            }
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            m[nums4[i]]++;
        }
        for(int i=0;i<v.size();i++) {
            count+=m[v[i]];
        }
        return count;
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
    vector<int> v1;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v1.push_back(k);
    }
    vector<int> v2;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v2.push_back(k);
    }
    vector<int> v3;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v3.push_back(k);
    }
    vector<int> v4;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v4.push_back(k);
    }
    Solution s;
    int res=s.fourSumCount(v1,v2,v3,v4);
    cout<<res<<endl;
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}