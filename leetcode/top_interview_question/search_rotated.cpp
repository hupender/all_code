#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& v, int t) {
        int n=v.size();
        int low=0,high=n-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(v[mid]>t) {
                if(v[mid]<v[high]) {
                    high=mid-1;
                }
                else {
                    if(v[low]>t) {
                        low=mid+1;
                    }
                    else if(v[low]<t) {
                        high=mid-1;
                    }
                    else {
                        return low;
                    }
                }
            }
            else if(v[mid]<t) {
                if(v[mid]>v[high]) {
                    low=mid+1;
                }
                else {
                    if(v[high]>t) {
                        low=mid+1;
                    }
                    else if(v[high]<t) {
                        high=mid-1;
                    }
                    else {
                        return high;
                    }
                }
            }
            else {
                return mid;
            }
        }
        // if(v[high]==t) {
        //     return high;
        // }
        // else {
        //     return -1;
        // }
        return -1;
    }
};
int main() {
    int n,target;
    cin>>n>>target;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<s.search(v,target)<<endl;
}