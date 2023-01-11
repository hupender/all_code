#include<bits/stdc++.h>
using namespace std;
int main() {
    // set will be sorted by first element
    set<pair<pair<int,int>,int>> s;
    s.insert(make_pair(make_pair(7,8),0));
    s.insert(make_pair(make_pair(4,2),9));
    s.insert(make_pair(make_pair(6,1),8));
    s.insert(make_pair(make_pair(3,3),1));
    s.insert(make_pair(make_pair(2,5),2));
    s.insert(make_pair(make_pair(1,4),3));
    s.insert(make_pair(make_pair(9,6),4));
    set<pair<pair<int,int>,int>>::iterator it;
    for(it=s.begin() ; it!=s.end() ; it++) {
        cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
    }
    // for(auto i:s) {
    //     cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    // }
}