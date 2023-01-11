#include<bits/stdc++.h>
using namespace std;
int main() {
    string s="ab*cde";
    int i=2;
    s.erase(s.begin()+i-1,s.begin()+i+1);
    cout<<"size of string "<<s.size()<<endl;
    cout<<"index "<<i<<endl;
    for(int j=0;j<s.size();j++) {
        cout<<s[j]<<" "<<endl;
    }
    cout<<"check "<<s[i]<<endl;
}