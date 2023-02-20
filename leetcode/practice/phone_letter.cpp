#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        int n=digits.size();
        if(n==0) {
            return v;
        }
        if(digits[0]=='2') {
            string s1,s2,s3;
            s1.push_back('a');
            s2.push_back('b');
            s3.push_back('c');
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
        }
        else if(digits[0]=='3') {
            string s1,s2,s3;
            s1.push_back('d');
            s2.push_back('e');
            s3.push_back('f');
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
        }
        else if(digits[0]=='4') {
            string s1,s2,s3;
            s1.push_back('g');
            s2.push_back('h');
            s3.push_back('i');
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
        }
        else if(digits[0]=='5') {
            string s1,s2,s3;
            s1.push_back('j');
            s2.push_back('k');
            s3.push_back('l');
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
        }
        else if(digits[0]=='6') {
            string s1,s2,s3;
            s1.push_back('m');
            s2.push_back('n');
            s3.push_back('o');
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
        }
        else if(digits[0]=='7') {
            string s1,s2,s3,s4;
            s1.push_back('p');
            s2.push_back('q');
            s3.push_back('r');
            s4.push_back('s');
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
            v.push_back(s4);
        }
        else if(digits[0]=='8') {
            string s1,s2,s3;
            s1.push_back('t');
            s2.push_back('u');
            s3.push_back('v');
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
        }
        else if(digits[0]=='9') {
            string s1,s2,s3,s4;
            s1.push_back('w');
            s2.push_back('x');
            s3.push_back('y');
            s4.push_back('z');
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
            v.push_back(s4);
        }
        for(int i=1;i<n;i++) {
            vector<string> v1;
            if(digits[i]=='2') {
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('a');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('b');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('c');
                    v1.push_back(s);
                }
            }
            else if(digits[i]=='3') {
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('d');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('e');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('f');
                    v1.push_back(s);
                }
            }
            else if(digits[i]=='4') {
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('g');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('h');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('i');
                    v1.push_back(s);
                }
            }
            else if(digits[i]=='5') {
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('j');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('k');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('l');
                    v1.push_back(s);
                }
            }
            else if(digits[i]=='6') {
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('m');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('n');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('o');
                    v1.push_back(s);
                }
            }
            else if(digits[i]=='7') {
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('p');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('q');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('r');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('s');
                    v1.push_back(s);
                }
            }
            else if(digits[i]=='8') {
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('t');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('u');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('v');
                    v1.push_back(s);
                }
            }
            else if(digits[i]=='9') {
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('w');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                        s.push_back('x');
                        v1.push_back(s);
                    }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('y');
                    v1.push_back(s);
                }
                for(int i=0;i<v.size();i++) {
                    string s=v[i];
                    s.push_back('z');
                    v1.push_back(s);
                }
            }
            v=v1;
        }
        return v;
    }
};
int main() {
    string a="23";
    Solution b;
    vector<string> v=b.letterCombinations(a);
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<endl;
    }
}