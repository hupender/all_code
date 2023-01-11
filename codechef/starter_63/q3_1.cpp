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
        vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(s[i]-'0');
        }
        stack<int> st;
        int count=0;
        for(int i=0;i<n;i++) {
            if(st.size()>=2) {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(a==b) {
                    st.push(0);
                    count++;
                }
                else {
                    st.push(b);
                    st.push(a);
                }
            }
            st.push(v[i]);
        }
        while(!st.empty()) {
            if(st.size()==1) {
                if(count==n-1) {
                    cout<<"yes"<<endl;
                }
                else {
                    cout<<"no"<<endl;
                }
                break;
            }
            else {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(a==b) {
                    st.push(0);
                    count++;
                }
                else {
                    cout<<"no"<<endl;
                    break;
                }
            }
        }
    }
}