#include<bits/stdc++.h>
using namespace std;
int main() {
    int h,w;
    cin>>h>>w;
    vector<vector<char>> s;
    vector<vector<char>> t;

    for(int i=0;i<h;i++) {
        vector<char> s1;
        for(int j=0;j<w;j++) {
            char c;
            cin>>c;
            s1.push_back(c);
        }
        s.push_back(s1);
    }

    for(int i=0;i<h;i++) {
        vector<char> s1;
        for(int j=0;j<w;j++) {
            char c;
            cin>>c;
            s1.push_back(c);
        }
        t.push_back(s1);
    }

    unordered_map<string,int> m1;
    for(int i=0;i<w;i++) {
        string k;
        for(int j=0;j<h;j++) {
            k.push_back(s[j][i]);
        }
        m1[k]++;
    }

    unordered_map<string,int> m2;
    for(int i=0;i<w;i++) {
        string k;
        for(int j=0;j<h;j++) {
            k.push_back(t[j][i]);
        }
        m2[k]++;
    }
    
    if(m1.size()!=m2.size()) {
        cout<<"No"<<endl;
    }
    else {
        int flag=1;
        for(auto i:m1) {
            if(i.second!=m2[i.first]) {
                flag=0;
                break;
            }
        }
        if(flag) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
        
}