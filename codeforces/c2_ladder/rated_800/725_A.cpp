#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
        int ma=INT_MIN,mi=INT_MAX;
        int min_index,max_index;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            if(k>ma) {
                ma=k;
                max_index=i;
            }
            if(k<mi) {
                mi=k;
                min_index=i;
            }
        }
        int res1=min(max_index,min_index)+abs(max_index-min_index)+1;
        int min_index_r=n-1-min_index;
        int max_index_r=n-1-max_index;
        int res2=min(max_index_r,min_index_r)+abs(max_index_r-min_index_r)+1;
        int res3=min(max_index,min_index)+min(max_index_r,min_index_r)+2;
        cout<<min(res1,min(res2,res3))<<endl;

        // int min_index_r=n-1-min_index;
        // int max_index_r=n-1-max_index;
        // int res=0;
        // if(min_index_r>min_index) {
        //     if(max_index_r>max_index) {
        //         res=min(min_index,max_index)+1+abs(min_index-max_index);
        //     }
        //     else {
        //         int d=abs(max_index-min_index)-1;
        //         res=min_index+max_index_r+d;
        //         res-=max(min_index,max(max_index_r,d));
        //         res+=2;
        //     }
        // }
        // else {
        //     if(max_index<max_index_r) {
        //         int d=abs(max_index-min_index)-1;
        //         res=min_index_r+max_index+d;
        //         res-=max(min_index_r,max(max_index,d));
        //         res+=2;
        //     }
        //     else {
        //         res=min(min_index_r,max_index_r)+1+abs(min_index_r-max_index_r);
        //     }
        // }
        // cout<<res<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}