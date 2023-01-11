#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
const int mod=1e9+7;
long long binary_to_decimal(vector<int> v) {
    long long ans=0;
    int n=v.size();
    int j=0;
    ll p=1;
    for(int i=n-1;i>=0;i--) {
        ans+=(v[i]*p);
        ans%=mod;
        p=(p*2)%mod;
    }
    return ans;
}

// get xor of string from index l and r both of size n
long long get_xor(vector<int>& s,int l,int r,int n) {
    vector<int> v;
    while(n--) {
        if(s[l]==s[r]) {
            v.push_back(0);
        }
        else {
            v.push_back(1);
        }
        l++;
        r++;
    }
    long long ans=binary_to_decimal(v);
    return ans;
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
        int n;
        cin>>n;
        string s1;
        cin>>s1;
        vector<int> s;
        for(int i=0;i<n;i++) {
            s.push_back(s1[i]-'0');
        }
        int ind=-1;
        for(int i=1;i<n;i++) {
            if(s[i]!=s[0]) {
                ind=i;
                break;
            }
        }
        if(ind==-1) {
            cout<<"0"<<endl;
        }
        else {
            int size=n-ind;
            int st=ind-1;
            int e=ind+1;
            while(st>0 && e<n && s[e]==s[ind]) {
                e++;
                st--;
            }
            ll ans=get_xor(s,st,ind,size);
            cout<<ans<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}