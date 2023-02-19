#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==0) {
            return x;
        }
        int sign=x/(abs(x));
        // x=abs(x);
        long long res=0;
        long long limit=1;
        for(int i=0;i<31;i++) {
            limit*=2;
        }
        while(x) {
            res=res*10+x%10;
            x/=10;
        }
        int flag=0;
        if(sign==1 && res<limit) {
            flag=1;
        }
        else if(sign==-1) {
            limit*=sign;
            if(res>=limit) {
                flag=1;
            }
        }
        if(!flag) {
            res=0;
        }
        return (int)res;
    }
};
int main() {
    int n;
    cin>>n;
    Solution s;
    int res=s.reverse(n);
    cout<<res<<endl;
}