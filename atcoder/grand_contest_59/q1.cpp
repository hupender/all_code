#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> get_distinct_range(string s,char c) {
    int n=s.size();
    vector<pair<int,int>> v;
    int ind=0;
    if(s[ind]==c) {
        while(s[ind]==c && ind<n) {
            ind++;
        }
    }
    int prev=ind,curr=ind;
    for(int i=ind;i<n;i++) {
        if(s[i]==c) {
            curr=i-1;
            v.push_back({prev,curr});
            while(s[i]==c && i<n) {
                i++;
            }
            prev=i;
        }
        else {
            curr=0;
        }
    }
    if(curr=0) {
        v.push_back({prev,n-1});
    }
    return v;
}

pair<int,int> search(vector<pair<int,int>> v,int k) {
    int low=0,high=v.size()-1;
    int flag=0;
    while(low<=high) {
        int mid=(low+high)/2;
        if(k<v[mid].first) {
            high=mid-1;
        }
        else if(k>v[mid].second) {
            low=mid+1;
        }
        else{
            flag=1;
            return {flag,mid};
        }
    }
    return {flag,low};
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> counta;
    vector<int> countb;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='A') {
            count1++;
        }
        if(s[i]=='B') {
            count2++;
        }
        counta.push_back(count1);
        countb.push_back(count2);
        
    }
    vector<pair<int,int>> va=get_distinct_range(s,'A');
    vector<pair<int,int>> vb=get_distinct_range(s,'B');
    vector<pair<int,int>> vc=get_distinct_range(s,'C');
    while(q--) {
        int a,b;
        cin>>a>>b;
        int cunt_a,cunt_b;
        if(a-2<0) {
            cunt_a=0;
            cunt_b=0;
        }
        else {
            cunt_a=counta[a-2];
            cunt_b=countb[a-2];
        }
        int final_a=counta[b-1]-cunt_a;
        int final_b=countb[b-1]-cunt_b;
        int final_c=b-a+1-(final_a+final_b);
        unordered_map<int,int> m;
        if(final_a>0) {
            m[1]++;
        }
        if(final_b>0) {
            m[2]++;
        }
        if(final_c>0) {
            m[3]++;
        }
        if(m.size()==1) {
            cout<<"0"<<endl;
        }
        else if(m.size()==2) {
            cout<<"1"<<endl;
        }
        else {
            int r1=search(va,b-1).second+search(va,b-1).first-search(va,a-1).second;
            int r2=search(vb,b-1).second+search(vb,b-1).first-search(vb,a-1).second;
            int r3=search(vc,b-1).second+search(vc,b-1).first-search(vc,a-1).second;
            int res=1+min(r1,min(r2,r3));
            cout<<res<<endl;
        }
    }
} 