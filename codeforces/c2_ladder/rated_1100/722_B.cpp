#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int count_zero=0,count_negative=0;
    vector<int> negative;
    for(int i=0;i<n;i++) {
        if(a[i]==0) {
            count_zero++;
            negative.push_back(a[i]);
        }
        else if(a[i]<0) {
            count_negative++;
            negative.push_back(a[i]);
        }
    }
    int count_positive=n-count_zero-count_negative;
    if(count_zero>1) {
        cout<<count_negative+count_zero<<endl;
    }
    else {
        if(count_positive>0) {
            sort(negative.begin(),negative.end());
            int n1=negative.size();
            int mi=INT_MAX;
            for(int i=0;i<n1-1;i++) {
                mi=min(mi,abs(negative[i]-negative[i+1]));
            }
            if(mi==INT_MAX) {
                cout<<count_negative+count_zero+1<<endl;
            }
            else {
                int flag=0;
                for(int i=0;i<n;i++) {
                    if(a[i]>0 && a[i]<=mi) {
                        flag=1;
                        break;
                    }
                }
                if(flag) {
                    cout<<count_negative+count_zero+1<<endl;
                }
                else {
                    cout<<count_negative+count_zero<<endl;
                }
            }
            
        }
        else {
            cout<<n<<endl;
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