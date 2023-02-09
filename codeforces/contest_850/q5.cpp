#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        v.push_back(s);
    }
    vector<vector<int>> v1;  // count w , count i, count n
    for(int i=0;i<n;i++) {
        int count1=0,count2=0,count3=0;
        for(int j=0;j<3;j++) {
            if(v[i][j]=='w') {
                count1++;
            }
            else if(v[i][j]=='i') {
                count2++;
            }
            else {
                count3++;
            }
        }
        vector<int> v2;
        v2.push_back(count1);
        v2.push_back(count2);
        v2.push_back(count3);
        v1.push_back(v2);
    }
    vector<int> v2;  // get all string with w count=2
    vector<int> v3;  // get all string with w count=0
    for(int i=0;i<n;i++) {
        if(v[i][0]==2) {
            v2.push_back(i);
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