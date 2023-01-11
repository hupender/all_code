#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    unordered_map<int,vector<int>> m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        m[a[i]].push_back(i);
    }
    int ma=INT_MIN;
    for(auto i:m) {
        int n1=i.second.size();
        ma=max(ma,n1);
    }
    if(ma>2) {
        cout<<"NO"<<endl;
    }
    else {
        int p[n];
        int q[n];
        memset(p,0,sizeof(p));
        memset(q,0,sizeof(q));
        for(auto i:m) {
            p[i.second[0]]=i.first;
            if(i.second.size()>1) {
                q[i.second[1]]=i.first;
            }
        }
        // making of p
        unordered_map<int,int> m1;
        for(int i=0;i<n;i++) {
            if(p[i]!=0) {
                m1[p[i]]++;
            }
        }
        vector<int> p_insertion;
        for(int i=1;i<=n;i++) {
            if(m1[i]==0) {
                p_insertion.push_back(i);
            }
        }
        sort(p_insertion.begin(),p_insertion.end());
        // q elements give the position where we need to insert elemets in p
        vector<pair<int,int>> q_ele;
        for(int i=0;i<n;i++) {
            if(q[i]!=0) {
                q_ele.push_back({q[i],i});
            }
        }
        // finding p element which are needed in making of q
        vector<pair<int,int>> p_ele;
        for(int i=0;i<n;i++) {
            if(p[i]!=0) {
                p_ele.push_back({p[i],i});
            }
        }

        sort(q_ele.begin(),q_ele.end());
        for(int i=0;i<q_ele.size();i++) {
            p[q_ele[i].second]=p_insertion[i];
        }
        // making of q
        unordered_map<int,int> m2;
        for(int i=0;i<n;i++) {
            if(q[i]!=0) {
                m2[q[i]]++;
            }
        }
        vector<int> q_insertion;
        for(int i=1;i<=n;i++) {
            if(m2[i]==0) {
                q_insertion.push_back(i);
            }
        }
        sort(q_insertion.begin(),q_insertion.end());
        sort(p_ele.begin(),p_ele.end());
        for(int i=0;i<p_ele.size();i++) {
            q[p_ele[i].second]=q_insertion[i];
        }
        int flag=1;
        for(int i=0;i<n;i++) {
            if(max(p[i],q[i])!=a[i]) {
                flag=0;
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++) {
                cout<<p[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<n;i++) {
                cout<<q[i]<<" ";
            }
            cout<<endl;
        }
        else {
            cout<<"NO"<<endl;
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