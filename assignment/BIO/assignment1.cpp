#include <bits/stdc++.h>
#define int long long int

int longestCommonSubsequence(std::string s1, std::string s2) {
    int n = s1.size(), m = s2.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

void solve(){
    std::string s = "";
    std::cin >> s;

    int n = s.size();

    int q;
    std::cin >> q;

    for(int i = 0; i < q; i++) {
        std::string t = "";
        std::cin >> t;
        std::cout << ((double)longestCommonSubsequence(s, t) / n) * 100 << "\n";
    }    
}
     
signed main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int t = 1;
    //std::cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}