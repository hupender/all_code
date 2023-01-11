#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
long long binary_to_decimal(vector<int> v) {
    long long ans=0;
    int n=v.size();
    int j=0;
    for(int i=n-1;i>=0;i--) {
        ans+=v[i]*pow(2,j);
        ans%=mod;
        j++;
    }
    return ans;
}

// get xor of string from index l and r both of size n
long long get_xor(string s,int l,int r,int n) {
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


// get first occurence
int get_first_occurence(string s,int a) {
    for(int i=0;i<s.size();i++) {
        if(s[i]==a) {
            return i;
        }
    }
    return -1;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;

        char c1='1';
        char c2='0';
        int first_one=get_first_occurence(s,c1);
        int first_zero=get_first_occurence(s,c2);
        

        if(first_one==-1 || first_zero==-1) {
            cout<<"0"<<endl;
        }
        else {
            int lar=max(first_one,first_zero);    //maximum of two positions
            int size=n-lar;
            int sma=min(first_one,first_zero);

            long long ans=0;
            for(int i=sma;i<lar;i++) {
                long long res=get_xor(s,i,lar,size);
                ans=max(ans,res);
            }
            cout<<ans<<endl;
        }
    }
}