#include<bits/stdc++.h>
using namespace std;
void modify_variable_name(char *input) {
    int i=0;
    while(input[i]!='\0') {
        i++;
    }
    cout<<"size of array is : "<<i<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        char c[n];
        for(int i=0;i<n;i++) {
            scanf("%c",c[i]);
        }
        modify_variable_name(c);
    }
}