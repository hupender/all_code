#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    set<int> s;
    set<int,greater<int>> s1;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        s.insert(a[i]);
        s1.insert(a[i]);
    }
    int st=0,end=n-1;
    int flag=0;
    while(st+3<=end) {
        int first=a[st];
        int last=a[end];
        int min=*s.begin();
        int max=*s1.begin();
        if(first!=max && first!=min && last!=max && last!=min) {
            flag=1;
            cout<<st+1<<" "<<end+1<<endl;
            break;
        }
        if(first==max || first==min) {
            s.erase(a[st]);
            s1.erase(a[st]);
            st++;
        }
        if(last==max || last==min) {
            s.erase(a[end]);
            s1.erase(a[end]);
            end--;
        }
        
    }
    if(!flag) {
        cout<<"-1"<<endl;
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