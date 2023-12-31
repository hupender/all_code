#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string> v;
        for(int i=0;i<n;i++) {
            int width=0;
            int width_no_space=0;
            int st=i;
            int count=0;
            while(i<n && width<=maxWidth) {
                width+=words[i].size();
                if(width<=maxWidth) {
                    width_no_space+=words[i].size();
                    count++;
                    width++;
                    i++;
                }
            }
            i--;
            string res;
            if(i==n-1) {
                for(int j=st;j<=i;j++) {
                    res.append(words[j]);
                    res.push_back(' ');
                    width_no_space++;
                }
                width_no_space--;
                res.pop_back();
                int remaining=maxWidth-width_no_space;
                while(remaining--) {
                    res.push_back(' ');
                }
            }
            else if(count==1) {
                res.append(words[st]);
                int r=maxWidth-words[st].size();
                while(r--) {
                    res.push_back(' ');
                }
            }
            else if(count>1) {
                int q_space=(maxWidth-width_no_space)/(count-1);
                int rem_space=(maxWidth-width_no_space)%(count-1);
                for(int j=st;j<=i;j++) {
                    res.append(words[j]);
                    int q=q_space;
                    if(j!=i) {
                        while(q--) {
                            res.push_back(' ');
                        }
                    }
                    if(rem_space) {
                        res.push_back(' ');
                        rem_space--;
                    }
                }
            }
            v.push_back(res);
        }
        return v;
    }
};

int main() {
    vector<string> v={"What","must","be","acknowledgment","shall","be"};
    int w=16;
    Solution s;
    s.fullJustify(v,w);
}