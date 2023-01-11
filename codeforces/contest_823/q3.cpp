#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        vector<int> v;
        int n=s.size();
        for(int i=0;i<n;i++) {
            v.push_back(s[i]-'0');
        }
        stack<int> st;
        int k=9;
        while(k>=0) {
            int count1=0;
            int p=v.size();
            for(int i=p-1;i>=0;i--) {
                if(v[i]==k) {
                    count1++;
                }
                else {
                    break;
                }
            }
            vector<int> v1;
            int count2=0;
            for(int i=0;i<p;i++) {
                if(v[i]==k) {
                    count2++;
                }
                else {
                    v1.push_back(v[i]);
                }
            }
            v.clear();
            v.insert(v.end(),v1.begin(),v1.end());
            // v1.clear();
            int count3=count2-count1;
            while(count3--) {
                st.push(min(k+1,9));
            }
            while(count1--) {
                st.push(k);
            }
            k--;
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<res.size();i++) {
            cout<<res[i];
        }
        cout<<endl;
    }
}