#include<bits/stdc++.h>
using namespace std;
int longestContinuousSubstring(string s) {
    int l=s.size();
    vector<int> v;
    for(int i=0;i<l;i++) {
        v.push_back(s[i]-'a');
    }
    
    int ans=0;
    for(int i=0;i<l;i++) {
        int c=v[i];
        int count=1;
        for(int j=i+1;j<l;j++) {
            if(v[j]==c+1) {
                count++;
                c=v[j];
            }
            else {
                ans=max(ans,count);
                break;
            }
        }
    }
    return ans;
}
int main() {
    string s;
    cin>>s;
    int ans=longestContinuousSubstring(s);
    cout<<ans;
}