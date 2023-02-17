#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
unordered_map<int,vector<int>> map2;

void get_all_factor() {
    int n=1e5;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            map2[j].push_back(i);
        }
    }
}

vector<int> get_factor(int n,int m) {
    vector<int> v;
    vector<int> v1=map2[n];
    for(int i=0;i<v1.size();i++) {
        if(v1[i]<=m) {
            v.push_back(v1[i]);
        }
    }
    return v;
}

void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    vector<vector<int>> v;
    for(int i=0;i<n;i++) {
        vector<int> v1=get_factor(a[i],m);
        v.push_back(v1);
    }
    map<int,int> map1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<v[i].size();j++) {
            map1[v[i][j]]++;
        }   
    }
    if(map1.size()==m) {
        int st=0,end=n-1;
        int res=a[end]-a[st];
        map<int,int> map2,map3;
        map2=map1;
        map3=map1;
        // firstly remove as many elements as possible from begining and then from last and vice-versa
        while(true) {
            // firstly check if we can ignore the first element
            int flag1=1;
            for(int i=0;i<v[st].size();i++) {
                if(map2[v[st][i]]<=1) {
                    flag1=0;
                }
            }
            if(flag1) {
                for(int i=0;i<v[st].size();i++) {
                    map2[v[st][i]]--;
                }
                st++;
            }
            else {
                break;
            }
        }
        st--;
        res=min(res,(a[end]-a[st+1]));

        // now after removing as many number from starting as we can now start removing from end until we can't further
        while(st>=0 && end>=st) {
            // check if we can remove last element
            int flag1=1;
            for(int i=0;i<v[end].size();i++) {
                if(map2[v[end][i]]<=1) {
                    flag1=0;
                }
            }
            if(flag1) {
                // we can remove last element so remove it
                for(int i=0;i<v[end].size();i++) {
                    map2[v[end][i]]--;
                }
                end--;
                res=min(res,(a[end]-a[st+1]));
            }
            else {
                // we can't remove so add a starting element and then try again
                for(int i=0;i<v[st].size();i++) {
                    map2[v[st][i]]++;
                }
                st--;
                res=min(res,(a[end]-a[st+1]));
            }
        }
        // this time start from end
        st=0,end=n-1;

        while(true) {
            // firstly check if we can ignore the last element
            int flag1=1;
            for(int i=0;i<v[end].size();i++) {
                if(map3[v[end][i]]<=1) {
                    flag1=0;
                }
            }
            if(flag1) {
                for(int i=0;i<v[end].size();i++) {
                    map3[v[end][i]]--;
                }
                end--;
            }
            else {
                break;
            }
        }
        end++;
        res=min(res,(a[end-1]-a[st]));

        // now after removing as many number from ending as we can , now start removing from start until we can't further
        while(end<n && st<=end) {
            // check if we can remove first element
            int flag1=1;
            for(int i=0;i<v[st].size();i++) {
                if(map3[v[st][i]]<=1) {
                    flag1=0;
                }
            }
            if(flag1) {
                // we can remove first element so remove it
                for(int i=0;i<v[st].size();i++) {
                    map3[v[st][i]]--;
                }
                st++;
                res=min(res,(a[end-1]-a[st]));
            }
            else {
                // we can't remove so add a ending element and then try again
                for(int i=0;i<v[end].size();i++) {
                    map3[v[end][i]]++;
                }
                end++;
                res=min(res,(a[end-1]-a[st]));
            }
        }
        cout<<res<<endl;
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
    get_all_factor();
    while(t--) {
        solve();
    }
    // for(int i=1;i<=t;i++) {
    //     if(t==1000) {
    //         int n,m;
    //         cin>>n>>m;
    //         int a[n];
    //         for(int i=0;i<n;i++) {
    //             cin>>a[i];
    //         }
    //         if(i==36) {
    //             cout<<n<<" "<<m<<endl;
    //             for(int i=0;i<n;i++) {
    //                 cout<<a[i]<<" ";
    //             }
    //             cout<<endl;
    //         }
    //     }
    //     else {
    //         solve();
    //     }
    //     // solve();
    // }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}