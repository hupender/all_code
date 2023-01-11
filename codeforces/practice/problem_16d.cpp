#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>> n;
    vector<string> v;
    vector<vector<int>> vt;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++) {
        int hour=v[i][1]*10+v[i][2];
        int min=v[i][4]*10+v[i][5];
        int period;
        if(v[i][7]=='a') {
            period=0;
        }
        else {
            period=1;
        }
        vt.push_back({hour,min,period});
    }
}