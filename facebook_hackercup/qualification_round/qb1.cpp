#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("inputb1.txt","r",stdin);
    freopen("outputb1.txt","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        int r,c;
        cin>>r>>c;
        // vector<string> s;
        int count=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                char c;
                cin>>c;
                if(c=='^') {
                    count++;
                }
            }
        }
        if(r==1 || c==1) {
            if(count>0) {
                cout<<"Case #"<<z<<": Impossible"<<endl;
            }
            if(count==0) {
                cout<<"Case #"<<z<<": Possible"<<endl;
                for(int i=0;i<r;i++) {
                    for(int j=0;j<c;j++) {
                        cout<<".";
                    }
                    cout<<endl;
                }
            }
        }
        else {
            cout<<"Case #"<<z<<": Possible"<<endl;
            for(int i=0;i<r;i++) {
                for(int j=0;j<c;j++) {
                    cout<<"^";
                }
                cout<<endl;
            }
        }

    }
}