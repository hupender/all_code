#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            vector<int> x;
            for(int i=0;i<k;i++) {
                int p;
                cin>>p;
                x.push_back(p);
            }
            v.push_back(x);
            x.clear();
        }
        int flag=1;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                unordered_map<int,int> question_frequency;
                for(auto k:v[i]) {
                    question_frequency[k]++;
                }
                for(auto k:v[j]) {
                    question_frequency[k]++;
                }
                if(question_frequency.size()==5) {
                    flag=0;
                    cout<<"YES"<<endl;
                    break;
                }
            }
            if(flag==0) {
                break;
            }
        }
        if(flag==1) {
            cout<<"NO"<<endl;
        }
    }
}