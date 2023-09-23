#include <bits/stdc++.h>
#define int long long int
using namespace std;
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

void solve(){
    string s = "";
    cin >> s;

    int n = s.size();

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        string t = "";
        cin >> t;
        cout << ((double)longestCommonSubsequence(s, t) / n) * 100 << "\n";
    }    
}
     
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("outp.txt", "w", stdout);
    #endif

    solve();
}