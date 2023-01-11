#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteString(string s) {
        int n=s.length();
        int count=0;
        int l=0;
        char c=s[0];
        char c=s[0];
        int flag1=1;
        for(int i=0;i<n;i++) {
            if(s[i]==s[l] && i!=l) {
                int low=l,high=i,flag=1;
                while(low<i) {
                    if(s[low]!=s[high]) {
                        flag=0;
                        break;
                    }
                    low++;
                    high++;
                }
                if(flag) {
                    count++;
                    l=high;
                    i=high;
                }
                else {
                    flag1=0;
                }
            }
            else {
                flag1=0;
            }
        }
        if(flag1) {
            return count;
        }
        else {
            return count+1;
        }
    }
};