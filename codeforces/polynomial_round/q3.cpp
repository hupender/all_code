#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count_zero=0,count_one=0;
    vector<int> v(n);
    for(int i=n-1;i>=0;i--) {
        int j=i-1;
        while(s[j]==s[i]) {
            j--;
        }
        j++;
        int k=j;
        int count=1;
        while(k<=i) {
            v[k]=count;
            count++;
            k++;
        }
        i=j;
    }
    for(int i=0;i<n-1;i++) {
        int x=i+2;
        x-=v[i];
        cout<<x<<" ";
    }
    cout<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}