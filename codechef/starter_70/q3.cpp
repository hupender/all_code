#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    int a[n];
    bool visited[n];
    memset(visited,false,sizeof(visited));
    int val=1;
    int flag=1;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            a[i]=val;
            visited[i]=true;
            int freq=b[i]-1;
            for(int j=i+1;freq>0 && j<n;j++) {
                if(!visited[j]) {
                    if(b[j]==b[i]) {
                        freq--;
                        a[j]=val;
                        visited[j]=true;
                    }
                }
            }
            if(freq>0) {
                flag=0;
                break;
            }
            val++;
        } 
    }
    if(flag) {
        for(int i=0;i<n;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else {
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