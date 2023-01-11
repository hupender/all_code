#include<bits/stdc++.h>
using namespace std;
// conclusion---->>>>>if we use set of vector then it will be sorted by its first element
int main() {
    set<vector<int>> v;
    v.insert({1,3,5});
    v.insert({3,1,7});
    v.insert({8,2,0});
    v.insert({6,3,2});
    v.insert({5,3,8});
    v.insert({9,2,1});
    v.insert({0,6,9,11});
    set<vector<int>>::iterator it;
    for(it=v.begin();it!=v.end();it++) {
        for(int j=0;j<3;j++) {
            cout<<it->at(j)<<" ";
        }
        cout<<endl;

    }
    
}