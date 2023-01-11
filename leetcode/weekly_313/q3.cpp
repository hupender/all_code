#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> get_binary(int n) {
        vector<int> v(32,0);
        int i=0;
        while(n) {
            int r=n%2;
            n=n/2;
            v[i]=r;
            i++;
        }
        return v;
    }
    int get_count(vector<int> v) {
        int count=0;
        for(int i=0;i<v.size();i++) {
            if(v[i]==1) {
                count++;
            }
        }
        return count;
    }
    int get_decimal(vector<int> v) {
        int ans=0;
        for(int i=0;i<32;i++) {
            ans+=pow(2,i)*v[i];
        }
        return ans;
    }

    int minimizeXor(int num1, int num2) {
        vector<int> v1=get_binary(num1);
        vector<int> v2=get_binary(num2);
        int n1=get_count(v1);
        int n2=get_count(v2);
        if(n1==n2) {
            return num1;
        }
        else if(n1>n2) {
            vector<int> v3(32);
            for(int i=31;i>=0;i--) {
                if(v1[i]==1 && n2) {
                    v3[i]=1;
                    n2--;
                }
                else {
                    v3[i]=0;
                }
            }
            int x=get_decimal(v3);
            return x;
        }
        else {
            n2=n2-n1;
            for(int i=0;i<32;i++) {
                if(v1[i]==0 && n2) {
                    v1[i]=1;
                    n2--;
                }
            }
            int x=get_decimal(v1);
            return x;
        }
    }
};
int main() {
    int n1,n2;
    cin>>n1>>n2;
    Solution obj;
    int ans=obj.minimizeXor(n1,n2);
    cout<<ans<<endl;
}