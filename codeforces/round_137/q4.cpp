#include<bits/stdc++.h>
using namespace std;
string get_or(string s,int st1,int st2,int st0) {
    string ans;
    int n=s.size();
    for(int i=st1;i<n;i++) {
        if(i<st0) {
            ans.push_back('1');
        }
        else {
            if(s[st0]=='1' || s[st2]=='1') {
                ans.push_back('1');
            }
            else {
                ans.push_back('0');
            }
            st0++;
            st2++;
        }
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ind=-1;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            ind=i;
            break;
        }
    }
    if(ind==-1) {
        cout<<"0"<<endl;
    }
    else {
        int ind_zero=-1;
        for(int i=ind;i<n;i++) {
            if(s[i]=='0') {
                ind_zero=i;
                break;
            }
        }
        if(ind_zero==-1) {
            for(int i=ind;i<n;i++) {
                cout<<s[i];
            }
            cout<<endl;
        }
        else {
            int size=n-ind_zero;
            vector<int> v;
            unordered_map<int,bool> valid;
            for(int i=ind;i<ind_zero;i++) {
                if(s[i]=='1') {
                    v.push_back(i);
                    valid[i]=true;
                }
            }
            for(int i=ind_zero+1;i<n;i++) {
                if(s[i]=='0') {
                    int d=i-ind_zero;
                    int flag=0;
                    for(int j=0;j<v.size();j++) {
                        if(valid[v[j]] && s[v[j]+d]=='1') {
                            flag=1;
                            break;
                        }
                    }
                    if(flag) {
                        for(int j=0;j<v.size();j++) {
                            if(s[v[j]+d]!='1') {
                                valid[v[j]]=false;
                            }
                        }
                    }
                }
            }
            int ind1=-1;
            for(int i=0;i<v.size();i++) {
                if(valid[v[i]]) {
                    ind1=v[i];
                }
            }
            string res=get_or(s,ind,ind1,ind_zero);
            cout<<res<<endl;
            // for(int i=0;i<res.size();i++) {
            //     cout<<res[i];
            // }
            // cout<<endl;
        }
    }

}
/*
5
11010
*/