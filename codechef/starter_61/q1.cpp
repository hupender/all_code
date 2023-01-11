#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b,c;
        cin>>a>>b>>c;
        int count_odd=0,count_even=0;
        if(a%2==0) {
            count_even++;
        }
        else {
            count_odd++;
        }
        if(b%2==0) {
            count_even++;
        }
        else {
            count_odd++;
        }
        if(c%2==0) {
            count_even++;
        }
        else {
            count_odd++;
        }
        if(count_even>0 && count_odd>0) {
            cout<<"yes"<<endl;
        }
        else {
            cout<<"no"<<endl;
        }
    }
}