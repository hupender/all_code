#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <cassert>
using namespace std;

// return the first index i such that 
// p comes in t at index t
int kmp(string t, string p)
{
    // implement KMP algorithm
    // calculate prefix function for needle

    int n = t.size();
    int m = p.size();

    // take base cases
    if (m == 0)
    {
        return 0;
    }
    else if (m > n)
    {
        return -1;
    }

    // calculate prefix function lps[]

    // lps[i] stores the length of longest proper prefix of p[0...i-1]
    // (prefix of length i)
    // which is also a suffix.
    vector<int> lps(m + 1);

    lps[0] = 0;
    lps[1] = 0;

    for (int i = 2; i <= m; i++)
    {
        // find lps[i] with help of lps[0....i-1]
        int q = lps[i - 1];
        // p[0....q-1] is a suffix of
        // p[0.....i-2]
        // ans q < i-1  (its proper prefix)

        // trace2(q, i-1);

        if (p[q] == p[i - 1])
        {
            // p[0....q] is also suffix of
            // p[0....i-1]

            // Mistake : put p instead lps.
            lps[i] = q + 1;
        }
        else
        {
            // manipulate q till it becomes lps[i]
            // till q sized prefix becomes suffix of
            // p[0....i-1]
            // q could well become 0

            while (q > 0 && p[q] != p[i - 1])
            {
                q = lps[q];

                // since p[0..q-1] is a suffix of p[0...i-2]
                // any suffic of p[0...q-1] will be suffix of
                // p[0...i-2]
            }

            // now p[0...q-1] is a suffix of p[0....i-2]

            if (p[q] == p[i - 1])
                q++;

            // mistake : did p[i] = q
            lps[i] = q;
        }

        // trace2(i,lps[i]);
    }

    // iterate through t, and return on first occurence

    int q = 0;
    int i = 0;
    // q is the current state
    // the length of longest prefix of p that is a suffix of t processed so far
    // p[0....q-1] is a suffix of
    // t[0.....i]

    int ans = -1;
    while (i < n)
    {
        // scan ith char, and determine state of t[0...i]
        // q is state of t[0...i-1]

        assert(q < m);

        if (t[i] == p[q])
        {
            q++;
        }
        else
        {
            // t[0...i-1] has suffix p[0...q-1]
            // but t[i] does not matched with p[q]

            // decrease q till it does
            while (q > 0 && p[q] != t[i])
            {
                q = lps[q];
            }

            // p[0....q-1] mathces with t[0...i-1]
            // q may be zero
            // and if p[q] == t[i]
            // then current state will be now q+1
            if (p[q] == t[i])
                q++;
        }

        // trace2(i,q);

        if (q == m)
        {
            // p as whole is a suffix of
            // t[0....i]
            // t[i-m+1....i] matches with p
            ans = i - m + 1;
            break;
        }

        i++;
    }

    return ans;
}

int main()
{

    string t = "abcefgabbc";
    string s = "abbc";

    cout << "KMP for t = " << t << " and s = " << s << " is = " << kmp(t,s) << endl;
}