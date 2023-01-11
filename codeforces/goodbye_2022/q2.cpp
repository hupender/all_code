#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve4() {
    int n,k;
    cin>>n>>k;
    int st=1,end=n;
    vector<int> v;
    int l=n-k+1;
    for(int i=0;i<n/2;i++) {
        v.push_back(end);
        v.push_back(st);
        end--;
        st++;
    }
    if(n%2!=0) {
        v.push_back(end);
    }
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl; 
}
void solve3() {
    int n,k;
    cin>>n>>k;
    int st=1,end=n;
    vector<int> v;
    int l=n-k+1;
    while(st<=end) {
        int l1=l-1;
        while(l1--) {
            v.push_back(end);
            end--;
        }
        v.push_back(st);
        st++;
    }
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void solve2() {
    int n,k;
    cin>>n>>k;
    int st=1,end=n;
    vector<int> v;
    int l=n-k+1;
    if(l==1) {
        for(int i=1;i<=n;i++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else {
        l--;
        while(st<=end) {
            int l1=l;
            while(l1-- && st<=end) {
                v.push_back(end);
                end--;
            }
            l1=l;
            while(l1-- && st<=end) {
                v.push_back(st);
                st++;
            }
        }
        for(int i=0;i<n;i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}
void solve1() {
    int n,k;
    cin>>n>>k;
    int st=1,end=n;
    vector<int> v;
    int l=n-k+1;
    int i;
    for(i=0;i<l-1;i++) {
        v.push_back(end);
        end--;
    }
    for(int i=l-1;i<n;i++) {
        v.push_back(st);
        st++;
    }
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void solve() {
    int n,k;
    cin>>n>>k;
    int pmin=1,pmax=n;
    vector<int> v;
    int l=n-k+1;
    l--;
    while(l--) {
        v.push_back(pmax);
        pmax--;
    }
    while(pmin<=pmax) {
        v.push_back(pmin);
        pmin++;
    }
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
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
        solve2();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}