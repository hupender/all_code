#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n=s.length();
    int count=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='w') {
            count++;
        }
    }
    cout<<n+count<<endl;
}