#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string res;
        char c=' ';
        for(int i=0;i<n;i++) {
            string s1;
            while(i<n && s[i]!=c) {
                s1.push_back(s[i]);
                i++;
            }
            reverse(s1.begin(),s1.end());
            for(int j=0;j<s1.size();j++) {
                res.push_back(s1[j]);
            }
            res.push_back(c);
        }
        res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};
int main() {
    string str="the sky is blue";
    Solution s;
    cout<<s.reverseWords(str)<<endl;

}


// eht yks
//sky the