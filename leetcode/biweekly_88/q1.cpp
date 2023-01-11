#include<bits/stdc++.h>
using namespace std;

bool equalFrequency(string word) {
    if(word.size()==3) {
        return true;
    }
    unordered_map<char,int> m;
    for(int i=0;i<word.size();i++) {
        m[word[i]]++;
    }
    int flag1;
    for(auto i:m) {
        if(i.second==1) {
            flag1=1;
        }
        else {
            flag1=0;
            break;
        }
    }
    if(flag1) {
        return true;
    }
    int flag=1;
    unordered_map<int,int> u;
    for(auto i:m) {
        u[i.second]++;
    }
    if(u.size()!=2) {
        flag=0;
    }
    else {
        int k1=u.begin()->second;
        int k2=u.begin()->first;
        int p1,p2;
        for(auto i:u) {
            p1=i.second;
            p2=i.first;
        }
        if(k1>=p1 && p1==1 && abs(k2-p2)==1 || k1<p1 && k1==1 && abs(k2-p2)==1) {
            flag=1;
        }
        else {
            flag=0;
        }
    }
    if(flag) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    string s;
    cin>>s;
    bool ans=equalFrequency(s);
    cout<<ans;
}