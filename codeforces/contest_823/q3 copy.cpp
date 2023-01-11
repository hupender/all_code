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
        int n=s.size();
        vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(s[i]-'0');
        }
        int k=8;
        stack<int> st;
        int count=0;
        for(int i=0;i<n;i++) {
            if(v[i]==9) {
                // st.push(9);
                v[i]=-1;
                count++;
            }
        }
        for(int i=0;i<n;i++) {
            if(v[i]==-1) {
                count++;
            }
            else {
                v[i]=v[i];


                
            }
        }
        int ind=n-1-count;
        while(k>=0) {
            int count1=0;
            // int ind=n-1-count;
            while(v[ind]==k) {
                // count++;
                count1++;
                ind--;
            }
            for(int i=0;i<ind;i++) {
                if(v[i]==k) {
                    st.push(min(k+1,9));
                    // count++;
                    ind--;
                }
            }
            while(count1--) {
                
            }
            k--;
        }
        while(!st.empty()) {
            cout<<st.top();
            st.pop();
        }
        cout<<endl;

    }
}