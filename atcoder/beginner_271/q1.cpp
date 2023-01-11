#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int q=n/16;
    int r=n%16;
    if(q>9) {
        char c='A'+q-10;
        cout<<c;
    }
    else {
        cout<<q;
    }
    if(r>9) {
        char c='A'+r-10;
        cout<<c;
    }
    else {
        cout<<r;
    }
}