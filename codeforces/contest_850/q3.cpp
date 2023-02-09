#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve1() {
    int n,w,h;
    cin>>n>>w>>h;
    int cake[n];
    for(int i=0;i<n;i++) {
        cin>>cake[i];
    }
    int dispenser[n];
    for(int i=0;i<n;i++) {
        cin>>dispenser[i];
    }
    vector<pair<ll,ll>> cak;
    for(int i=0;i<n;i++) {
        cak.push_back({cake[i]-w,cake[i]+w});
    }
    vector<pair<ll,ll>> dispense;
    for(int i=0;i<n;i++) {
        dispense.push_back({dispenser[i]-h,dispenser[i]+h});
    }

    if(dispense[0].first<0) {
        int shift=abs(dispense[0].first);
        for(int i=0;i<n;i++) {
            dispense[i].first+=shift;
            dispense[i].second+=shift;
        }
    }
    int shift_0=dispense[0].first-cak[0].first;
    for(int i=0;i<n;i++) {
        cak[i].first+=shift_0;
        cak[i].second+=shift_0;
    }
    int max_diff=2*(w-h);
    if(max_diff<0) {
        cout<<"NO"<<endl;
    }
    else {
        int max_needed_shift=0;
        int flag=1;
        for(int i=1;i<n;i++) {
            if(cak[i].second-max_needed_shift<dispense[i].second) {
                flag=0;
                break;
            }
            else {
                int shift=cak[i].first-dispense[i].first;
                if(shift>max_diff) {
                    flag=0;
                    break;
                }
                max_needed_shift=max(max_needed_shift,shift);
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}
void solve() {
    int n,w,h;
    cin>>n>>w>>h;
    int cake[n];
    for(int i=0;i<n;i++) {
        cin>>cake[i];
    }
    int dispenser[n];
    for(int i=0;i<n;i++) {
        cin>>dispenser[i];
    }
    vector<pair<int,int>> cak;
    for(int i=0;i<n;i++) {
        cak.push_back({cake[i]-w,cake[i]+w});
    }
    int low=dispenser[0]-h , high=dispenser[0]+h; // lower and upper bound for first 
    int shift=low-cak[0].first;
    for(int i=0;i<n;i++) {
        cak[i].first+=shift;
        cak[i].second+=shift;
    }
    if(cak[0].second>=dispenser[0]+h) {
        int abs_shift=cak[0].second-dispenser[0]-h;
        int flag=1;
        for(int i=1;i<n;i++) {
            if(cak[i].second<dispenser[i]+h) {
                flag=0;
                break;
            }
            else {
                int diff=cak[i].first-(dispenser[i]-h);
                if(diff>abs_shift) {
                    flag=0;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;   
        }
    }
    else {
        cout<<"NO"<<endl;
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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}