#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

vector<int> decimal_to_binary(int n) {
    vector<int> v(30,0);
    int i=29;
    while(n>0) {
        v[i]=n%2;
        n/=2;
        i--;
    }
    return v;
}

int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {    
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        vector<vector<int>> v2;
        for(int i=0;i<n;i++) {
            vector<int> p=decimal_to_binary(v[i]);
            v2.push_back(p);
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            for(int j=0;j<30;j++) {
                if(v2[i][j]==1) {
                    m[j]++;
                }
            }
        }
        unordered_map<int,int> m1;
        int count=0,k=0,i=0;
        int res=-1;
        int flag1=1;
        while(i<n || flag1) {
            int flag=1;
            for(auto j:m) {
                if(j.second>0 && m1[j.first]==0) {
                    flag=0;
                    flag1=0;
                    break;
                }
            }
            if(flag) {
                // both the or's are equal
                // try if we can remove first element
                flag1=1;
                for(auto j:m) {
                    if(j.second==m1[j.first]) {
                        flag1=0;
                        break;
                    }
                }
                if(!flag1) {
                    for(int j=0;j<30;j++) {
                        if(v2[k][j]==1) {
                            m1[j]--;
                        }
                    }
                    count--;
                    k++;
                }
                else {
                    res=max(res,count);
                    if(k==0) {
                        res=max(res,n-i);
                    }
                    m1.clear();
                    count=0;
                }
            }
            else {
                // or's not equal add one more number
                if(i<n) {
                    for(int j=0;j<30;j++) {
                        if(v2[i][j]==1) {
                            m1[j]++;
                        }
                    }
                    count++;
                    i++;
                }
            }
        }
        cout<<res<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}