#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int count_1=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            count_1++;
        }
    }
    if(count_1==0) {
        cout<<s<<endl;
    }
    else if(count_1==n) {
        for(int i=0;i<n;i++) {
            s[i]='0';
        }
        cout<<s<<endl;
    }
    else {
        vector<int> prefix_dist(n,INT_MAX);
        int i=0;
        while(s[i]=='0') {
            i++;
        }
        for(;i<n;i++) {
            if(s[i]=='0') {
                int dis=1;
                while(s[i]=='0') {
                    prefix_dist[i]=dis;
                    dis++;
                    i++;
                }
                i--;
            }
        }
        vector<int> suffix_dist(n,INT_MAX);
        i=n-1;
        while(s[i]=='0') {
            i--;
        }
        for(;i>=0;i--) {
            if(s[i]=='0') {
                int dis=1;
                while(s[i]=='0') {
                    suffix_dist[i]=dis;
                    dis++;
                    i--;
                }
                i++;
            }
        }
        vector<int> final_dis;
        for(i=0;i<n;i++) {
            final_dis.push_back(min(prefix_dist[i],suffix_dist[i]));
        }
        string s1=s;
        // now we will do the process one time on string s1;
        for(i=0;i<n;i++) {
            if(s[i]=='1') {
                s1[i]='0';
                if(i-1>=0 && s[i-1]=='0') {
                    s1[i-1]='1';
                }
                if(i+1<n && s[i+1]=='0') {
                    s1[i+1]='1';
                }
            }
        }
        // repeat the above process on s1;
        vector<int> prefix_dist1(n,INT_MAX);
        i=0;
        while(s1[i]=='0') {
            i++;
        }
        for(;i<n;i++) {
            if(s1[i]=='0') {
                int dis=1;
                while(s1[i]=='0') {
                    prefix_dist1[i]=dis;
                    dis++;
                    i++;
                }
                i--;
            }
        }
        vector<int> suffix_dist1(n,INT_MAX);
        i=n-1;
        while(s1[i]=='0') {
            i--;
        }
        for(;i>=0;i--) {
            if(s1[i]=='0') {
                int dis=1;
                while(s1[i]=='0') {
                    suffix_dist1[i]=dis;
                    dis++;
                    i--;
                }
                i++;
            }
        }
        for(i=0;i<n;i++) {
            if(final_dis[i]==INT_MAX) {
                final_dis[i]=min(prefix_dist1[i],suffix_dist1[i]);
            }
            else {
                final_dis[i]--;
            }
        }
        k--;
        string res;
        for(i=0;i<n;i++) {
            if(final_dis[i]>k) {
                res.push_back(s1[i]);
            }
            else {
                int diff=k-final_dis[i];
                if(diff%2==0) {
                    res.push_back('1');
                }
                else {
                    res.push_back('0');
                }
            }
        }
        cout<<res<<endl;
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