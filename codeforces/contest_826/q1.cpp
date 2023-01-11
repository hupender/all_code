#include<bits/stdc++.h>
using namespace std;
int get_size(string s1) {
    int f1;
    for(int i=0;i<s1.size();i++) {
        if(s1[i]=='M') {
            f1=2;
        }
        else if(s1[i]=='S') {
            f1=1;
        }
        else {
            f1=3;
        }
    }
    return f1;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        string s1,s2;
        cin>>s1>>s2;
        int f1,f2;
        f1=get_size(s1);
        f2=get_size(s2);
        if(f1>f2) {
            cout<<">"<<endl;
        }
        else if(f1<f2) {
            cout<<"<"<<endl;
        }
        else {
            int n1=s1.size();
            int n2=s2.size();
            if(f1==1) {
                if(n1>n2) {
                    cout<<"<"<<endl;
                }
                else if(n1<n2) {
                    cout<<">"<<endl;
                }
                else {
                    cout<<"="<<endl;
                }
            }
            if(f1==3) {
                if(n1>n2) {
                    cout<<">"<<endl;
                }
                else if(n1<n2) {
                    cout<<"<"<<endl;
                }
                else {
                    cout<<"="<<endl;
                }
            }
            if(f1==2) {
                cout<<"="<<endl;
            }
        }
    }
}