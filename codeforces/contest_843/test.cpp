#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int price=15;
    // 3 k badle ek
    int count=n/15;
    int n1=count;
    while(true) {
        int rem=n1%3;
        n1/=3;
        count+=n1;
        n1+=rem;
        if(n1<3) {
            break;
        }
    }
    cout<<count<<" "<<n1<<endl;
}