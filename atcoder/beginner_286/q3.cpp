#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
bool check_palindrome(string s) {
    int n=s.size();
    for(int i=0;i<n/2;i++) {
        if(s[i]!=s[n-1-i]) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int count=0;
    char c=s[0];
    for(int i=0;i<n;i++) {
        if(c==s[i]) {
            count++;
        }
        else {
            break;
        }
    }
    count/=2;
    string s1=s;
    if(check_palindrome(s)) {
        cout<<"0"<<endl;
    }
    else {
        ll c=0;
        int flag=0;
        while(count--) {
            int temp=s[0];
            for(int i=0;i<n-1;i++) {
                s[i]=s[i+1];
            }
            s[n-1]=temp;
            c++;
            if(check_palindrome(s)) {
                flag=1;
                cout<<c*a<<endl;
            }
        }
        if(!flag) {
            ll c1=0;
            for(int i=0;i<n/2;i++) {
                if(s[i]!=s[n-1-i]) {
                    c1++;
                }
            }
            ll c2=0;
            for(int i=0;i<n/2;i++) {
                if(s1[i]!=s1[n-1-i]) {
                    c2++;
                }
            }

            cout<<min(c*a+c1*b,c2*b)<<endl;
        }
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
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}