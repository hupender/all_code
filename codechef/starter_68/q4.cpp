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
        unordered_map<int,int> m1;
        for(int i=0;i<n;i++) {
            m1[s[i]]++;
        }
        int flag=0;
        for(auto i:m1) {
            if(i.second>1) {
                flag=1;
                break;
            }
        }
        if(!flag) {
            cout<<"0"<<endl;
        }
        else {
            unordered_map<char,int> m;
            unordered_map<char,vector<int>> m2;
            for(int i=0;i<n-1;i++) {
                if(s[i]==s[i+1]) {
                    int count=1;
                    int ind=i;
                    while(i<n-1 && s[i]==s[i+1]) {
                        i++;
                        count++;
                    }
                    if(m[s[ind]]<count) {
                        m[s[ind]]=count;
                    }
                    // else if(m[s[ind]]==count) {
                    //     m[s[ind]]=count+1;
                    // }
                    else if(m[s[ind]]==count) {
                        m2[s[ind]].push_back(count);
                    }
                }
            }
            int lar=0;
            for(auto i:m) {
                lar=max(lar,i.second);
            }
            lar--;
            for(auto i:m2) {
                for(auto j:i.second) {
                    lar=max(lar,j);
                }
            }
            cout<<max(1,lar)<<endl;
        }
    }
}