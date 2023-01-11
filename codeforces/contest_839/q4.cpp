#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
bool is_sorted(vector<int> v) {
    int n=v.size();
    for(int i=0;i<n-1;i++) {
        if(v[i]>v[i+1]) {
            return false;
        }
    }
    return true;
}
void solve1() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    int less_than=INT_MAX;
    int greater_than=INT_MIN;
    for(int i=0;i<n-1;i++) {
        if(v[i]<v[i+1]) {
            less_than=min(less_than,(v[i]+v[i+1])/2);
        }
        else if(v[i]>v[i+1]) {
            greater_than=max(greater_than,(v[i]+v[i+1]+1)/2);
        }
    }
    if(n==1) {
        cout<<"0"<<endl;
    }
    else if(less_than==INT_MAX ) {
        cout<<greater_than<<endl;
    }
    else if(greater_than==INT_MIN) {
        cout<<less_than<<endl;
    }
    else if(greater_than==INT_MIN && less_than==INT_MAX) {
        cout<<"0"<<endl;
    }
    else if(greater_than<=less_than) {
        cout<<less_than<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }
}
void solve() {
    int n;
    cin>>n;
    vector<int> v;
    int ma=INT_MIN;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        ma=max(ma,k);
        v.push_back(k);
    }
    if(is_sorted(v)) {
        cout<<"0"<<endl;
    }
    else {
        int avg=ma;
        for(int i=0;i<n-1;i++) {
            if(v[i]<v[i+1]) {
                avg=(v[i]+v[i+1])/2;
                break;
            }
        }
        vector<int> v1=v;
        for(int i=0;i<n;i++) {
            v1[i]=abs(v1[i]-avg);
        }
        if(is_sorted(v1)) {
            cout<<avg<<endl;
        }
        else {
            int ma=INT_MIN;
            for(int i=0;i<n-1;i++) {
                if(v[i]>v[i+1]) {
                    avg=(v[i]+v[i+1]+1)/2;
                    ma=max(ma,avg);
                }
            }
            for(int i=0;i<n;i++) {
                v[i]=abs(v[i]-avg);
            }
            if(is_sorted(v)) {
                cout<<avg<<endl;
            }
            else {
                cout<<"-1"<<endl;
            }
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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}