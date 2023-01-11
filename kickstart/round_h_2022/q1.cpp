#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    for(int x=1;x<=t;x++) {
        int l,n;
        cin>>l>>n;
        char dir=0;
        int count=0;
        int dis;
        for(int i=0;i<n;i++) {
            int k;
            char d;
            cin>>k>>d;
            if(dir==0) {
                dir=d;
                count+=k/l;
                dis=k%l;
            }
            else {
                if(dir==d) {
                    dis+=k;
                    count+=dis/l;
                    dis=dis%l;
                }
                else {
                    dir=d;
                    dis-=k;
                    if(dis<0) {
                        dis+=l;
                    }
                }
            }
        }
        cout<<"Case #"<<x<<": "<<count<<endl;
    }
}