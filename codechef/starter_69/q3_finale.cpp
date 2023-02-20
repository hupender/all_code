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

void solve1(vector<vector<int>> &v,unordered_map<int,int> &m) {
    // v store the binary of all number in vector of size 30
    // m store the count of one at all indexses
    int n=v.size();
    unordered_map<int,int> m1,m2;
    int n1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<30;j++) {
            if(v[i][j]==1) {
                m1[j]++;
            }
        }
        int flag1=1;
        for(auto i:m) {
            if(m1[i.first]==0) {
                flag1=0;
                break;
            }
        }
        if(flag1) {
            n1=i+1;
            break;
        }
    }
    int flag=1;
    for(auto i:m) {
        m2[i.first]=i.second-m1[i.first];
        if(m2[i.first]==0) {
            flag=0;
        }
    }
    int res=-1;
    if(flag) {
        res=max(n1,n-n1);
    }
    int ind=n1-1;
    int end=n-1;
    while(ind>=0) {
        // remove the last element from m1 and add to m2
        for(int i=0;i<30;i++) {
            m1[i]=m1[i]-v[ind][i];
            m2[i]=m2[i]+v[ind][i];
        }
        ind--;
        int flag2=0;
        for(auto i:m) {
            if(m1[i.first]==0) {
                flag2=1;
            }
        } 
        if(flag2) {
            // as we have removed a necessary element from m1 we need to compensate it by adding element fromlast
            while(end>ind) {
                for(int i=0;i<30;i++) {
                    m1[i]+=v[end][i];
                    m2[i]-=v[end][i];
                }
                end--;
                int flag1=1;
                for(auto i:m) {
                    if(m1[i.first]==0) {
                        flag1=0;
                        break;
                    }
                }
                if(flag1) {
                    break;
                }
            }
        }
        int flag3=1;
        for(auto i:m) {
            if(m1[i.first]==0 || m2[i.first]==0) {
                flag3=0;
                break;
            }
        }
        if(flag3) {
            flag=1;
            res=max(res,end-ind);
        }
    }
    cout<<res<<endl;
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        vector<int> p=decimal_to_binary(k);
        v.push_back(p);
    }
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<30;j++) {
            if(v[i][j]==1) {
                m[j]++;
            }
        }
    }
    int flag=1;
    for(auto i:m) {
        if(i.second==1) {
            flag=0;
        }
    }
    if(flag) {
        solve1(v,m);
    }
    else {
        cout<<"-1"<<endl;
    }
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
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}