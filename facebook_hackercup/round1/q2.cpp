#include<bits/stdc++.h>
using namespace std;
int main() {

    freopen("input2_validation.txt","r",stdin);
    freopen("output2.txt","w",stdout);

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

        unordered_map<int,int> frequency;
        for(int i=0;i<n;i++) {
            frequency[a[i]]++;
        }
        int p,mi=INT_MIN;
        for(auto i:frequency) {
            if(mi>i.second) {
                mi=min(mi,i.second);
                p=i.first;
            }   
        }
        cout<<"p is "<<p<<endl;

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
            int ind=-1;
            int ans=0;
            for(int i=0;i<n;i++) {
                if(b[i]==p) {
                    ind=i;
                }
            // }
            
                // if(ind==-1) {
                //     ans=0;
                //     cout<<"Case #"<<x<<": "<<"NO"<<endl;
                // }
                if(n==2) {
                    int flag1=0,flag2=0;
                    if(a[0]==a[1] && b[0]==b[1]) {
                        // cout<<"Case #"<<x<<": "<<"YES"<<endl;
                        ans=1;
                        break;
                    }
                    else {
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
                            // cout<<"Case #"<<x<<": "<<"YES"<<endl;
                            ans=1;
                            break;
                        }
                        // else {
                        //     cout<<"Case #"<<x<<": "<<"NO"<<endl;
                        //     ans=0;
                        // }
                    }
                }
                // else if(ind==0 && k==1) {
                //     // cout<<"Case #"<<x<<": "<<"NO"<<endl;
                //     ans=0;
                // }
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
                    // if(!flag) {
                    //     // cout<<"Case #"<<x<<": "<<"NO"<<endl;
                    //     ans=0;
                    // }
                    // else {
                    if(flag==1) {
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
                            // cout<<"Case #"<<x<<": "<<"YES"<<endl;
                            ans=1;
                        }
                        // else {
                        //     cout<<"Case #"<<x<<": "<<"NO"<<endl;
                        //     ans=0;
                        // }
                    }
                }
            }
            if(ans==0) {
                cout<<"Case #"<<x<<": "<<"NO"<<endl;
            }
            else {
                cout<<"Case #"<<x<<": "<<"YES"<<endl;
            }
        }
    }
}