#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
string get_common_subsequence(string s1,string s2) {
    int n=s1.size();
    int m=s2.size();
    string dp[n+1][m+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0 || j==0) {
                string s;
                dp[i][j]=s;
            }
            else if(s1[i-1]==s2[j-1]) {
                string s=dp[i-1][j-1];
                s.push_back(s1[i-1]);
                dp[i][j]=s;
            }
            else {
                string s=dp[i-1][j];
                string t=dp[i][j-1];
                if(s.size()>t.size()) {
                    dp[i][j]=s;
                }
                else {
                    dp[i][j]=t;
                }
            }
        }
    }
    return dp[n][m];
}
string get_gene(vector<string> v,float threshold) {
    int min_len=INT_MAX;
    int n=v.size();
    for(int i=0;i<n;i++) {
        int l=v[i].size();
        min_len=min(min_len,l);
    }
    int required_length=threshold*min_len;
    unordered_map<string,int> map;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            string common_string=get_common_subsequence(v[i],v[j]);
            if(common_string.size()>=required_length) {
                map[common_string]++;
            }
        }
    }
    // now we need to find the string which is present in 80% of input
    int req_frequency=(n-1)*0.8;
    for(auto it:map) {
        if(it.second>=req_frequency) {
            return it.first;
        }
    }
    return "";
}
void solve() {
    float threshold=0.8;
    // string gene="ACTGGGAGGGGAGGAGTTACCTTTACC";
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    string gene=get_gene(v,threshold);
    cout<<gene<<endl;

    
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}