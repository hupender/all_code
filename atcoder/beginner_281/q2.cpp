#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    string s;
    cin>>s;
    bool first_char=false,integer=false,last_char=false;
    int n=s.size();
    for(int i=0;i<n;i++) {
        if( !first_char && s[i]>='A' && s[i]<='Z') {
            first_char=true;
        }
        else if(first_char) {
            if(!integer) {
                if(s[i]>='1' && s[i]<='9') {
                    int count=1;
                    i++;
                    while(s[i]>='0' && s[i]<='9') {
                        count++;
                        i++;
                    }
                    i--;
                    if(count>=6) {
                        integer=true;
                    }
                }
            }
            else {
                if(s[i]>='A' && s[i]<='Z') {
                    last_char=true;
                }
            }
        }
    }
    if(first_char && integer && last_char) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}