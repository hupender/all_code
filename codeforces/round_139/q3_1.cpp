#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int is_true(int n,string &s1,string &s2,int string) {
    int i=0;
    int flag=1;
    int count=0;
    while(i<n) {
        if(string==1) {
            if(s1[i]!='B') {
                flag=0;
                break;
            }
            else {
                count++;
            }
            if(s2[i]=='B') {
                string=2;
                count++;
            }
            else {
                string=1;
            }
        }
        else {
            if(s2[i]!='B') {
                flag=0;
                break;
            }
            else {
                count++;
            }
            if(s1[i]=='B') {
                string=1;
                count++;
            }
            else {
                string=2;
            }
        }
        i++;
    }
    if(flag) {
        return count;
    }
    else {
        return -1;
    }
}
void solve() {
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int count=0;
    for(int i=0;i<n;i++) {
        if(s1[i]=='B') {
            count++;
        }
        if(s2[i]=='B') {
            count++;
        }
    }
    // start from string 1
    int a=is_true(n,s1,s2,1);
    // start from string 2
    int b=is_true(n,s1,s2,2);
    if(a==count || b==count) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    
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