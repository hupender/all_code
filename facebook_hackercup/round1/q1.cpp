#include<iostream>
#include<vector>
using namespace std;
int main() {

    freopen("input1_final2.txt","r",stdin);
    freopen("output1.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int x=1;x<=t;x++) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        if(n==1) {
            cout<<"Case #"<<x<<": "<<"YES"<<endl;
        }
        else if(k==0) {
            int flag=1;
            for(int i=0;i<n;i++) {
                if(a[i]!=b[i]) {
                    flag=0;
                }
            }
            if(flag) {
                cout<<"Case #"<<x<<": "<<"YES"<<endl;
            }
            else {
                cout<<"Case #"<<x<<": "<<"NO"<<endl;
            }
        }
        else {
            int p=a[0],ind=-1;
            for(int i=0;i<n;i++) {
                if(b[i]==p) {
                    ind=i;
                }
            }
            
            if(ind==-1) {
                cout<<"Case #"<<x<<": "<<"NO"<<endl;
            }
            else if(n==2) {
                int flag1=0,flag2=0;
                if(ind==0 && k%2==0) {
                    if(a[1]==b[1]) {
                        flag2=1;
                    }
                }
                if(ind==1 && k%2!=0) {
                    if(a[1]==b[0]) {
                        flag1=1;
                    }
                }
                if(flag1 || flag2) {
                    cout<<"Case #"<<x<<": "<<"YES"<<endl;
                }
                else {
                    cout<<"Case #"<<x<<": "<<"NO"<<endl;
                }
            }
            else if(ind==0 && k==1) {
                cout<<"Case #"<<x<<": "<<"NO"<<endl;
            }
            else {
                int i=0,j=ind;
                int flag=1;
                while(j<n) {
                    if(a[i]!=b[j]) {
                        flag=0;
                        break;
                    }
                    i++;
                    j++;
                }
                if(!flag) {
                    cout<<"Case #"<<x<<": "<<"NO"<<endl;
                }
                else {
                    int j=0;
                    while(i<n) {
                        if(a[i]!=b[j]) {
                            flag=0;
                            break;
                        }
                        i++;
                        j++;
                    }
                    if(flag) {
                        cout<<"Case #"<<x<<": "<<"YES"<<endl;
                    }
                    else {
                        cout<<"Case #"<<x<<": "<<"NO"<<endl;
                    }
                }
            }
        }
    }
}