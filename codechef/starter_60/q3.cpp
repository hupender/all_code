#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n%2!=0) {
            cout<<"yes"<<endl;
        }
        else {
            int l=0,h=n-1,count=0;
            while(l<=h) {
                if(s[l]!=s[h]) {
                    count++;
                }
                l++;
                h--;
            }
            if(count%2==0) {
                cout<<"yes"<<endl;
            }
            else {
                cout<<"no"<<endl;
            }
        }
    }
}