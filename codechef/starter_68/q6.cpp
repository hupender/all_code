#include<bits/stdc++.h>
using namespace std;
bool is_valid(vector<int>& v) {
    int n=v.size();
    for(int i=1;i<n;i+=2) {
        if(i+1<n) {
            if(v[i]>v[i-1] && v[i]>v[i+1]) {
                continue;
            }
            else {
                return false;
            }
        }
        else {
            if(v[i]>v[i-1]) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    return true;
}
vector<int> get_help(vector<int>& v) {
    vector<int> v1;
    int n=v.size();
    int low=0,mid=(n+1)/2;
    int j=mid;
    while(low<mid || j<n) {
        if(low<mid) {
            v1.push_back(v[low]);
        }
        if(j<n) {
            v1.push_back(v[j]);
        }
        low++;
        j++;
    }
    return v1;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
            m[k]++;
        }
        int flag=1;
        for(auto i:m) {
            if(i.second>(n+1)/2) {
                flag=0;
                break;
            }
        }

        if(flag) {
            int max_freq=0;
            int max_num;
            vector<int> v1;
            for(auto i:m) {
                if(i.second>max_freq) {
                    max_freq=i.second;
                    max_num=i.first;
                }
            }
            for(auto i:m) {
                if(i.first!=max_num) {
                    while(i.second--) {
                        v1.push_back(i.first);
                    }
                }
            }
            sort(v1.begin(),v1.end());
            reverse(v1.begin(),v1.end());
            while(max_freq--) {
                v1.push_back(max_num);
            }
            reverse(v1.begin(),v1.end());
            vector<int> v2=get_help(v1);
            for(int i=0;i<n;i++) {
                cout<<v2[i]<<" ";
            }
            cout<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
}