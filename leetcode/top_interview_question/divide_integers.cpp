#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        long upper=1;
        int t=31;
        while(t--) {
            upper*=2;
        }
        long lower=-1*upper;
        upper--;
        long d1=dividend;
        long d2=divisor;
        long q=d1/d2;
        if(q>upper) {
            return (int)upper;
        }
        else if(q<lower) {
            return (int)lower;
        }
        else {
            return (int)q;
        }
    }
    // int divide(int dividend, int divisor) {
    //     long upper1=1;
    //     int t=31;
    //     while(t--) {
    //         upper1*=2;
    //     }
    //     int lower=(-1)*upper1;
    //     int upper=upper1-1;
    //     int s1;
    //     if(dividend==0) {
    //         s1=1;
    //     }
    //     else {
    //         s1=dividend/abs(dividend);
    //     }
        
    //     int s2=divisor/abs(divisor);
    //     s1*=s2;
    //     long divid=abs((long)dividend);
    //     long divis=abs((long)divisor);

    //     long q=divid/divis;
    //     q*=s1;
    //     if(q>upper) {
    //         return upper;
    //     }
    //     else if(q<lower) {
    //         return lower;
    //     }
    //     else {
    //         return (int)q;
    //     }
    // }
};
int main() {
    int n,m;
    cin>>n>>m;
    Solution s;
    cout<<s.divide(n,m)<<endl;
}