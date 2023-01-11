#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
const int mod=998244353;
void solve1() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[n];
    for(int i=0;i<n;i++) {
        a[i]=s[i]-'0';
    }
    ll dp[n];  //to store result till that index
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int count_zero=0,count_one=0,count_two=0;
    if(a[0]==0) {
        count_zero++;
    }
    else {
        count_one++;
    }
    for(int i=1;i<n;i++) {
        count_two++;
        if(a[i]==0) {
            count_zero++;
            if(count_zero>=i+1) {
                dp[i]=(dp[i-1]*2)%mod;
            }
            else {
                int d=i+1-count_zero;
                if(d<=count_two) {
                    count_two-=d;
                    count_zero+=d;
                    ll div_factor=1;
                    d--;
                    while(d--) {
                        div_factor*=2;
                        div_factor%=mod;
                    }
                    dp[i]=dp[i-1]/div_factor;
                }
                else {
                    break;
                }
            }
        }
        else {
            count_one++;
            if(count_one>=i+1) {
                dp[i]=(dp[i-1]*2)%mod;
            }
            else {
                int d=i+1-count_one;
                if(d<=count_two) { 
                    count_two-=d;
                    count_one+=d;
                    ll div_factor=1;
                    d--;
                    while(d--) {
                        div_factor*=2;
                        div_factor%=mod;
                    }
                    dp[i]=dp[i-1]/div_factor;
                }
                else {
                    break;
                }
            }
        }
    }
    ll res=0;
    for(int i=0;i<n;i++) {
        res+=dp[i];
        res%=mod;
    }
    cout<<res<<endl;
}

// void solve() {
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     map<int,int> v;
//     for(int i=0;i<n;i++) {
//         v[2*i]=s[i]-'0';
//     }
//     ll res=0;
//     int count=1;
//     int count_one=0,count_zero=0,count_two=0;
//     ll multi_factor=1;
//     int flag=1;
//     ll prev_res=0;
//     for(auto i:v) {
//         if(flag) {
//             // added
//             if(i.second==0) {
//                 count_zero++;
//             }
//             else {
//                 count_one++;
//             }
//             prev_res++;
//             res++;
//             flag=0;
//         }
//         else {
//             if(i.second==0) {
//                 count_zero++;
//                 if(count_zero>=count) {
//                     // multi_factor*=2;
//                     // multi_factor%=mod;
//                     //removed
//                     // res+=(res*multi_factor)%mod;
//                     // added
//                     prev_res=(prev_res*multi_factor)%mod;
//                     res+=prev_res;
//                     res%=mod;
//                 }
//                 else {
//                     int d=count-count_zero;
//                     if(d>count_two) {
//                         break;
//                     }
//                     else {
//                         count_two-=(d);
//                         count_zero+=d;
//                         // prev_res*=2;
//                         d--;
//                         multi_factor/=2;
//                         while(d--) {
//                             multi_factor/=2;
//                             prev_res/=2;
//                         }
//                         // res+=(res*multi_factor)%mod;
//                         prev_res=(prev_res*multi_factor)%mod;
//                         res+=prev_res;
//                         res%=mod;
//                     }
//                 }
//             }
//             else {
//                 count_one++;
//                 if(count_one>=count) {
//                     // multi_factor*=2;
//                     // multi_factor%=mod;
//                     prev_res=(prev_res*multi_factor)%mod;
//                     res+=prev_res;
//                     // res+=(res*multi_factor)%mod;
//                     res%=mod;
//                 }
//                 else {
//                     int d=count-count_one;
//                     if(d>count_two) {
//                         break;
//                     }
//                     else {
//                         count_two-=(d);
//                         d--;
//                         multi_factor/=2;
//                         count_one+=d;
//                         while(d--) {
//                             prev_res/=2;
//                             multi_factor/=2;
//                         }
//                         // res+=(res*multi_factor)%mod;
//                         prev_res=(prev_res*multi_factor)%mod;
//                         res+=prev_res;
//                         res%mod;
//                     }
//                 }
//             }
//         }
//         count_two++;
//         count++;
//         multi_factor*=2;
//         multi_factor%=mod;
//     }
//     cout<<res<<endl;

// }

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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}