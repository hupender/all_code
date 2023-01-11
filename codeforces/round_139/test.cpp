#include<bits/stdc++.h>
using namespace std;
int main() {
    int n=10000000;
    double sum=0;
    for(float i=2;i<=n;i++) {
        sum+=1.0*(1/i);
    }
    cout<<sum<<endl;
}