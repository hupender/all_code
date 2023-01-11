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
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
            m[k]++;
        }
        int max_count=0;
        int num;
        for(auto i:m) {
            if(i.second>max_count) {
                max_count=i.second;
                num=i.first;
            }
        }
        if(max_count>(n+1)/2) {
            cout<<"-1"<<endl;
        }
        else {
            int half=(n+1)/2;
            sort(v.begin(),v.end());
            vector<int> v1;
            vector<int> v2;
            for(int i=0;i<n;i++) {
                if(v[i]==num) {
                    int index=i;
                    int size=v1.size();
                    while(i<n && size<half) {
                        v1.push_back(v[i]);
                        size++;
                        i++;
                    }
                    if(size==half) {
                        while(i<n) {
                            v2.push_back(v[i]);
                            i++;
                        }
                        int ind=0;
                        while(v[ind]!=num) {
                            v2.push_back(v[ind]);
                            ind++;
                        }
                    }
                    else if(size<half) {
                        while(size<half) {
                            v1.push_back(v[index]);
                            size++;
                            index--;
                        }
                        while(index>=0) {
                            v2.push_back(v[index]);
                            index--;
                        }
                    }
                }
            }
            int n1=v1.size();
            int n2=v2.size();
            int i=0,j=0;
            vector<int> v3;
            while(i<n1 || j<n2) {
                if(i<n1) {
                    v3.push_back(v1[i]);
                }
                if(j<n2) {
                    v3.push_back(v2[j]);
                }
                i++;
                j++;
            }
            for(int i=0;i<n;i++) {
                cout<<v3[i]<<" ";
            }
            cout<<endl;
        }
    }
}