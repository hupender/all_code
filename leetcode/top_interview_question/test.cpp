#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) {
            return s;
        }
        int final_res=0,lower,upper;
        
        for(int i=1;i<n-1;i++) {
            int low=i-1;
            int high=i+1;
            int res=1;
            int lower_bound=i,higher_bound=i;
            while(low>=0 && high<n) {
                if(s[low]==s[high]) {
                    lower_bound=low;
                    higher_bound=high;
                    res+=2;
                    low--;
                    high++;
                }
                else {
                    break;
                }
            }
            int res2=0;
            low=i-1;
            if(s[low]==s[i]) {
                int lower_bound2=low,higher_bound2=i;
                int ind=i;
                while(low>=0 && ind<n) {
                    if(s[low]==s[ind]) {
                        lower_bound2=low;
                        higher_bound=ind;
                        res2+=2;
                        low--;
                        ind++;
                    }
                    else {
                        break;
                    }
                }

                if(res2>res) {
                    res=res2;
                    lower_bound=lower_bound2;
                    higher_bound=higher_bound2;
                }

            }
            int res3=0;
            if(s[i+1]==s[i]) {
                int lower_bound3=i,higher_bound3=i+1;
                int ind=i;
                int h=i+1;
                while(h<n && ind>=0) {
                    if(s[h]==s[ind]) {
                        lower_bound3=ind;
                        higher_bound3=h;
                        res3+=2;
                        h++;
                        ind--;
                    }
                    else {
                        break;
                    }
                }
                if(res<res3) {
                    res=res3;
                    lower_bound=lower_bound3;
                    higher_bound=higher_bound3;
                }
            }
            if(final_res<res) {
                final_res=res;
                lower=lower_bound;
                upper=higher_bound;
            }
            
        }
        string result;
        for(int i=lower;i<=upper;i++) {
            result.push_back(s[i]);
        }
        return result;
    }
};
int main() {
    string s;
    cin>>s;
    Solution a;
    string res=a.longestPalindrome(s);
    cout<<res<<endl;
}