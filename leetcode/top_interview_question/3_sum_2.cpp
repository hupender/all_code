#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
class Solution {
public:
    int binary_search(vector<int>& v,int low,int high,int target) {
        int zero=low;
        if(low==high) {
            return v[low];
        }
        while(low<high) {
            int mid=(low+high)/2;
            if(v[mid]==target) {
                return target;
            }
            else if(v[mid]<target) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        int val1=v[low];
        if(low-1>=zero) {
            int val2=v[low-1];
            int diff1=abs(val1-target);
            int diff2=abs(val2-target);
            if(diff1<diff2) {
                return val1;
            }
            else {
                return val2;
            }
        }
        else {
            return val1;
        }
        
    }

    int threeSumClosest(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<int> v1;
        for(int i=0;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                int rem=target-v[i]-v[j];
                int val=binary_search(v,j+1,n-1,rem);
                int val1=val+v[i]+v[j];
                v1.push_back(val1);
            }
        }
        int res;
        int max_diff=INT_MAX;
        for(int i=0;i<v1.size();i++) {
            // int diff;
            // if(v[i]>target) {
            //     diff=v[i]-target;
            // }
            // else {
            //     diff=target-v[i];
            // }
            int diff=abs(v[i]-target);
            if(diff<max_diff) {
                max_diff=diff;
                res=v1[i];
            }
        }
        return res;
    }
};
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    int n,target;
    cin>>n>>target;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    int res=s.threeSumClosest(v,target);
    cout<<res<<endl;
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}