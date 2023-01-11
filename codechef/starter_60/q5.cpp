#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> v;
        int ma=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int p;
            cin>>p;
            m[p]++;
            ma=max(ma,p);
            v.push_back(p);
        }
        // vector<int> v1;
        // for(int i=1;i<ma;i++) {
        //     if(m[i]==0) {
        //         v1.push_back(i);
        //     }
        // }
        int i=0;
        int num=1;
        int res=0;
        int k1=(k/2)*2;
        while(i<k1) {
            
            if(m[num]>0) {
                while(m[num]>0) {
                    num++;
                }
            }
            int n1=num;

            int score1=ma-num;
            num++;
            if(m[num]>0) {
                while(m[num]>0) {
                    num++;
                }
            }
            int score2=ma-num;
            int total_score=score1+score2;

            int another_score=2*(n+1)-n1;

            if(total_score>=another_score) {
                m[n1]++;
                m[num]++;
                n+=2;
                res+=total_score;
            }
            else {
                m[n1]++;
                n+=2;
                m[2*n]++;
                res+=another_score;
            }
            i+=2;
        }
        if(i<k) {
            if(m[num]>0) {
                while(m[num]>0) {
                    num++;
                }
            }
            int score1=ma-num;
            res+=score1;
        }
        cout<<res<<endl;
    }
}