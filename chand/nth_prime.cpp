#include<bits/stdc++.h>
using namespace std;
const int n=3*1e6;

void get_all_prime(vector<int> &dp) {
    vector<bool> visited(n,false);
    for(int i=2;i<n;i++) {
        if(!visited[i]) {
            dp.push_back(i);
            for(int j=i;j<n;j+=i) {
                visited[j]=true;
            }
        }
        if(dp.size()==1e5) {
            break;
        }
    }
}
int nthPrime(int input) {
    vector<int> dp;
    get_all_prime(dp);
    return dp[input-1];
}
int main() {
    int n;
    cin>>n;
    cout<<nthPrime(n)<<endl;
    cout<<"hello"<<endl;
}