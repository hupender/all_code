#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n==1) {
            cout<<"yes"<<endl;
        }
        else {
            int count1=0,count2=0;
            int flag1=1;
            for(int i=0;i<n;i++) {
                if(s[i]=='1') {
                    if(flag1) {
                        count1++;
                    }
                    count2++;
                }
                if(s[i]=='0') {
                    flag1=0;
                }
            }
            if(count1!=count2 || count1%2!=0) {
                cout<<"no"<<endl;
            }
            else {
                int num_operation;
                int count=n-count1;   // count is count of zero's
                num_operation=count1/2;
                count+=count1/2;
                while(count!=1) {
                    num_operation+=count/2;
                    count=(count+1)/2;
                }
                if(num_operation==n-1) {
                    cout<<"yes"<<endl;
                }
                else {
                    cout<<"no"<<endl;
                }
            }
        }
    }
}