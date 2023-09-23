#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    map<char,int> map;
    for(int i=0;i<n;i++) {
        map[s[i]]++;
    }
    string res;
    for(int i=0;i<n;i++) {
        res.push_back('.');
    }
    int count=0;
    int st=0,end=n-1;
    char low_ele,high_ele;
    int flag1=0,flag2=0;
    auto it=map.begin();
    string res2=s;
    for(;it!=map.end();it++) {
        char c=it->first;
        int val=it->second;
        int r=val%2;
        if(r!=0) {
            if(flag1==0) {
                low_ele=c;
                flag1=1;
            }
            else if(flag2==0) {
                high_ele=c;
                flag2=1;
            }
        }
        val-=r;
        val/=2;
        while(val--) {
            res[st]=c;
            res[end]=c;
            st++;
            end--;
        }
        if(flag1 && flag2) {
            res[st]=high_ele;
            res[end]=low_ele;
            st++;
            break;
        }
    }
    if(flag1 && flag2) {
        it++;
        for(;it!=map.end();it++) {
            int val=it->second;
            char c=it->first;
            while(val--) {
                res[st]=c;
                st++;
            }
        }
    }
    else if(flag1) {
        res[st]=low_ele;
        string s1=res;
        sort(s1.begin(),s1.end());
        char c=s1[0];
        for(int i=0;i<n-1;i++) {
            s1[i]=s1[i+1];
        }
        s1[n-1]=c;
        string s2=s1;
        reverse(s2.begin(),s2.end());
        s1=max(s1,s2);
        res=min(res,s1);
    }
    sort(res2.begin(),res2.end());
    char c=res2[0];
    for(int i=0;i<n-1;i++) {
        res2[i]=res2[i+1];
    }
    res2[n-1]=c;
    string res3=res2;
    reverse(res3.begin(),res3.end());
    res2=max(res2,res3);
    cout<<min(res,res2)<<endl;
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