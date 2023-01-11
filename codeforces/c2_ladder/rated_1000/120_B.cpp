#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    string s;
    cin>>s;
    int count_one=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            count_one++;
        }
    }
    int max1=n;
    int min1=n-count_one;
    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;
    for(int i=0;i<n;i++) {
        if(arr[i]>min1) {
            if(s[i]!='1') {
                v1.push_back({arr[i],i});
            }
        }
        else {
            if(s[i]=='1') {
                v2.push_back({arr[i],i});
            }
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int n1=v1.size();
    for(int i=0;i<n1;i++) {
        arr[v2[i].second]=v1[i].first;
        arr[v1[i].second]=v2[i].first;
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
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