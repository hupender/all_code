#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> get_one_factor() {
    map<int,bool> visited;
    unordered_map<int,vector<int>> m;
    int mod=1000000;
    for(int i=2;i<=mod;i++) {
        visited[i]=false;
    }
    map<int,bool> :: iterator it;
    while(visited.size()>0) {
        it=visited.begin();
        int n=it->first;
        int i=n;
        int j=2;
        while(n<=mod) {
            m[n].push_back(i);
            if(visited.find(n)!=visited.end()) {
                visited.erase(n);
            }
            n=i*j;
            j++;
        }
    }
    return m;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    unordered_map<int,vector<int>> m=get_one_factor();
    for(auto i:m) {
        cout<<i.first<<" : ";
        for(auto j:i.second) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}