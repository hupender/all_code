#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(s[i]-48);
        }
        vector<int> v1;


        // for(int i=1;i<n-1;i++) {
        //     if(v[i]==0 && v[i+1]==0) {
        //         int p=(v[i-1]*10+v[i]);
        //         i++;
        //         v1.push_back(p);
        //     }
        //     // else if(v[i]==0 && v[i+1]!=0){
        //     //     int p=v[i-1]*10+v[i];
        //     //     v.push_back(p);
        //     // }
        //     else if(v[i]!=0 && v[i+1]==0) {
        //         int p=v[i-1]*10+v[i];
        //         v1.push_back(p);
        //         i+=2;
        //         v1.push_back(v[i]);
        //     }
        //     else {
        //         int p=v[i-1];
        //         v1.push_back(p);
        //     }
        // }
        // if(v[n-1]!=0) {
        //     v1.push_back(v[n-1]);
        // }
        int j=0;
        for(int i=0;i<n-1;i++) {
            if(v[i]==0 && v[i+1]!=0) {
                while(j<i-2) {
                    v1.push_back(v[j]);
                    j++;
                }
                v1.push_back(v[i-2]*10+v[i-1]);
                // i++;
                j=i+1;
            }
            else if(v[i]==0 && v[i+1]==0) {
                while(j<i-1) {
                    v1.push_back(v[j]);
                    j++;
                }
                v1.push_back(10*v[i-1]);
                i++;
                j=i+1;
            }
        }
        if(v[n-2]!=0) {
            if(v[n-1]==0) {
                while(j<n-3) {
                    v1.push_back(v[j]);
                    j++;
                }
                v1.push_back(v[n-3]*10+v[n-2]);
            }
            else {
                while(j<n) {
                    v1.push_back(v[j]);
                    j++;
                }
            } 
        }
        else if(v[n-2]==0 && v[n-1]!=0){
            v1.push_back(v[n-1]);
        }




        string ans;
        for(int i=0;i<v1.size();i++) {
            char c=v1[i]-1+'a';
            ans+=c;
        }
        cout<<ans;
        // for(int i=0;i<v1.size();i++) {
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;



        cout<<endl;
    }
}