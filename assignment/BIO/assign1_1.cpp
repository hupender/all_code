#include <bits/stdc++.h>

using namespace std;

string longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    // fill the dp table
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in both the strings are same, then current character is part of LCS
        if (text1[i - 1] == text2[j - 1])
        {
            ans.push_back(text1[i - 1]);
            i--;
            j--;
        }
        // If current character in X and Y are different & we are moving upwards
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        // If current character in X and Y are different & we are moving leftwards
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    // cout<<ans
    return ans;
}

string helper(vector<string> &strings, double threshold)
{
    int n = strings.size();
    int minLen = strings[0].size();
    for (int i = 1; i < n; i++)
    {
        if (strings[i].size() < minLen)
        {
            minLen = strings[i].size();
        }
    }
    float targetLen = (float)minLen * threshold;
    unordered_map<string, int> mp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                string subs = longestCommonSubsequence(strings[i], strings[j]);
                int sub_len = subs.size();
                if ((float)sub_len >= targetLen)
                {
                    mp[subs]++;
                }
            }
        }
        float min_freq = (float)n * 0.8;
        for (auto it : mp)
        {
            cout << it.first << " " << it.second <<  endl;
            if ((float)it.second >= min_freq)
            {
                return it.first;
            }
        }
    }
    return "";
}

int main()
{
    vector<string> strings = {"TACTGGGGGAGAGGGGAGGAGTAAAGGGTACCTTTACCTTA",
                              "TTSSACTGGGAGGGGAAAGGAGGAGTTACCTTTACCTTAT",
                              "TACTGGGGAAGAAGGGGGGGAGGAGTTACCTTTACCTTACC",
                              "TTAATTACTTTTGTTTTAGGGGAGGTTAAAGTTACCTAATTACAAC",
                              "AAATTCTGGGAGGGGGGGGGTTAGGAGTTACCTTTTTTACCAA",
                              "AAATTTACTGGTTTGAGGTTTGGAGGAACCAGTTACCCCTTTACCCC",
                              "AAAAATTTCTGGGAAAGGGGGGGAGGAGGGGGTTACCCCCTTTACCCCC",
                              "ACCCCCTTTGGGTTAGGGGAGGAGTTAAGGTTGGACCTTTTTTACCGGG",
                              "TACTGTTTTTTGGGGAGGGGAGGAGTTACCTTTACCTTT",
                              "TTTAAACTGTTTGGAGGGGGGAGGAAAGTTAGGCCTATTATCCG",
                              "TTTAAACGGTGGGGGGGTTGGAGGAGGGTTAAACCTTTTAACC",
                              "TTTCTGGGGTTTCCGGGGCCCTTGGAAGGGGTTCCC"};
    // vector<string> strings = {"abcd", "abcdaa", "abbcddba", "abbbccccdddda"};


    double threshold = 0.8;
    string gene = helper(strings, threshold);
    cout << "gene: " << gene << endl;
    return 0;
}