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
        int l=0,h=n-1;
        int k=0;
        list<int> li;
        while(l<=h) {
            if(k%2==0) {
                //alice
                if(s[l]=='0') {
                    li.push_front(0);
                }
                else {
                    li.push_back(1);
                }
                l++;
            }
            else {
                //bob
                if(s[h]=='0') {
                    li.push_back(0);
                }
                else {
                    li.push_front(1);
                }
                h--;
            }
            k++;
        }
        for(auto i:li) {
            cout<<i;
        }
        cout<<endl;
    }
}