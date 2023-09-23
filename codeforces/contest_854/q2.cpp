#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    int min_ele=INT_MAX,ind;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]<min_ele) {
            min_ele=a[i];
            ind=i;
        }
    }
    if(n==1) {
        cout<<"0"<<endl;
    }
    else if(min_ele==1) {   
        int flag1=1;
        for(int i=0;i<n;i++) {
            if(a[i]!=1) {
                flag1=0;
                break;
            }
        }
        if(flag1) {
            cout<<"0"<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
    else {
        int count=0;
        vector<pair<int,int>> res;
        int flag=1,final_flag=0;
        while(true) {
            int new_min=min_ele,ind1=ind;
            for(int i=0;i<n;i++) {
                if(a[i]!=min_ele) {
                    count++;
                    res.push_back({i+1,ind+1});
                    int r=a[i]%min_ele;
                    a[i]=a[i]/min_ele;
                    if(r!=0) {
                        a[i]++;
                    }
                    if(a[i]<new_min) {
                        new_min=a[i];
                        ind1=i;
                    }
                }
            }
            int flag1=1;
            for(int i=1;i<n;i++) {
                if(a[i]!=a[0]) {
                    flag1=0;
                }
            }
            if(flag1) {
                final_flag=1;
                break;
            }
            if(new_min==1) {
                flag=0;
                break;
            }
            else if(new_min==2) {
                ind=ind1;
                break;
            }
            else {
                min_ele=new_min;
                ind=ind1;
            }
        }
        if(final_flag) {
            cout<<count<<endl;
            for(int i=0;i<count;i++) {
                cout<<res[i].first<<" "<<res[i].second<<endl;
            }
        }
        else if(flag) {
            int val=2;
            for(int i=0;i<n;i++) {
                if(a[i]!=2) {
                    while(a[i]!=2) {
                        count++;
                        res.push_back({i+1,ind+1});
                        int rem=a[i]%2;
                        a[i]/=2;
                        if(rem) {
                            a[i]++;
                        }
                    }
                }
            }
            cout<<count<<endl;
            for(int i=0;i<count;i++) {
                cout<<res[i].first<<" "<<res[i].second<<endl;
            }
        }
        else {
            cout<<"-1"<<endl;
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