#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int n=s.size();
        int flag=0;
        for(int i=0;i<n-2;i++) {
            if(s[i]=='a'|| s[i]=='e' || s[i]=='i'|| s[i]=='o' || s[i]=='u') {
                if(s[i+1]=='a'|| s[i+1]=='e' || s[i+1]=='i'|| s[i+1]=='o' || s[i+1]=='u') {
                    if(s[i+2]=='a'|| s[i+2]=='e' || s[i+2]=='i'|| s[i+2]=='o' || s[i+2]=='u') {
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag) {
            cout<<"happy"<<endl;
        }
        else {
            cout<<"sad"<<endl;
        }
    }
}