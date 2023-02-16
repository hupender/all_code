#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
// #define int int
void solve1() {
    int n;
    cin>>n;
    int a[n],b[n];
    unordered_map<int,int> m1,m2;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        m1[a[i]]=i;
    }
    for(int i=0;i<n;i++) {  
        cin>>b[i];
        m2[b[i]]=i;
    }
    ll res=0;
    int ind1=m1[1];
    int ind2=m2[1];
    int min_ind=min(ind1,ind2);
    int max_ind=max(ind1,ind2);

    ll res1=min_ind*(ll)(min_ind+1);
    ll res2=(n-1-max_ind)*(ll)(n-1-max_ind+1);
    ll res3=(max_ind-min_ind)*(ll)(max_ind-min_ind-1);

    res+=res1+res2+res3;
    res/=2;
    // res1  , res2 ,res 3 are the values when ans is 1
    int lower_limit=min_ind;
    int upper_limit=max_ind;
    for(int i=2;i<=n;i++) {
        int pos1=m1[i];
        int pos2=m2[i];
        if(pos1>upper_limit && pos2<lower_limit) {
            ll k1=pos1-upper_limit;
            ll k2=lower_limit-pos2;
            res+=k1*k2;
        }
        else if(pos1<lower_limit && pos2>upper_limit) {
            ll k1=pos2-upper_limit;
            ll k2=lower_limit-pos1;
            res+=k1*k2;
        }
        else if(pos1<lower_limit && pos2<lower_limit) {
            int max_pos=max(pos1,pos2);
            res+=(lower_limit-max_pos)*(ll)(n-upper_limit);
        }
        else if(pos1>upper_limit && pos2>upper_limit) {
            int min_pos=min(pos1,pos2);
            res+=(min_pos-upper_limit)*(ll)(lower_limit+1);
        }
        upper_limit=max({upper_limit,pos1,pos2});
        lower_limit=min({lower_limit,pos1,pos2});
    }
    cout<<res+1<<endl;

}

int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve1();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
    return 0;
}