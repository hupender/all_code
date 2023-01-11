#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int to_integer_type(string s) {
        int res;
        int n=s.size();
        for(int i=0;i<n;i++) {
            res=10*res+int(s[i])-48;
        }
        return res;
    }
    int maximumValue(vector<string>& strs) {
        int res=0;
        int n=strs.size();
        for(int i=0;i<n;i++) {
            int flag=1;
            int k=strs[i].size();
            for(int j=0;j<k;j++) {
                if(strs[i][j]<'0' || strs[i][j]>'9') {
                    flag=0;
                    break;
                }
            }
            if(!flag) {
                res=max(res,k);
            }
            else {
                int p=to_integer_type(strs[i]);
                res=max(res,p);
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<string> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        v.push_back(s);
    }
    int ans=s.maximumValue(v);
    cout<<ans<<endl;
}

/*
5
alic3
bob
3
4
00000
*/