#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        vector<int> v2;
        vector<int> v3;
        vector<int> v5;
        vector<int> v7;
        vector<int> v11;
        vector<int> v13;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
            if(k%2==0) {
                v2.push_back(k);
            }
            if(k%3==0) {
                v3.push_back(k);
            }
            if(k%5==0) {
                v5.push_back(k);
            }
            if(k%7==0) {
                v7.push_back(k);
            }
            if(k%11==0) {
                v11.push_back(k);
            }
            if(k%13==0) {
                v13.push_back(k);
            }
        }
        vector<vector<int>> v1;
        v1.push_back(v2);
        v1.push_back(v3);
        v1.push_back(v5);
        v1.push_back(v7);
        v1.push_back(v11);
        v1.push_back(v13);
        int flag=1;
        for(auto i:v1) {
            if(i.size()==n) {
                flag=0;
                cout<<"0"<<endl;
                break;
            }
            // if(i.size()<n-1) {
            //     flag=2;
            // }
        }
        // if(flag==2) {
        //     cout<<"-1"<<endl;
        // }
        if(flag==1) {
            unordered_map<int,int> m;
            for(auto i:v1) {
                if(i.size()==n-1) {
                    flag=1;
                    for(auto j:i) {
                        m[j]++;
                    }
                    break;
                }
                if(i.size()<n-1) {
                    flag=2;
                }
            }
            if(flag==2) {
                cout<<"-1"<<endl;
            }
            else {
                int x;
                int indx;
                for(int i=0;i<n;i++) {
                    if(m[v[i]]==0) {
                        indx=i;
                        x=v[i];
                    }
                }
                int ind;
                for(int i=0;i<n;i++) {
                    if(__gcd(x,v[i])==1) {
                        ind=i;
                        break;
                    }
                }
                if(ind==0 || ind==n-1 && indx==0 || indx==n-1) {
                    cout<<"0"<<endl;
                }
                else {
                    if(ind==0) {
                        cout<<"1"<<endl;
                        cout<<indx+1<<" "<<n<<endl;
                    }
                    if(ind==n-1) {
                        cout<<"1"<<endl;
                        cout<<"1 "<<indx+1<<endl;
                    }
                    if(indx==0) {
                        cout<<"1"<<endl;
                        cout<<ind+1<<" "<<n<<endl;
                    }
                    if(indx==n-1) {
                        cout<<"1"<<endl;
                        cout<<"1 "<<ind+1<<endl;
                    }
                    else {
                        cout<<"2"<<endl;
                        cout<<"1 "<<ind+1<<endl;
                        cout<<indx+1<<" "<<n<<endl;
                    }
                }
            }
        }
    }
}