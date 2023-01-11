#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y) {
    if(y==0) {
        return x;
    }
    return gcd(y,x%y);
}

// vector<int> primeFactors(int n) {
//     vector<int> v;
//     if(n%2==0) {
//         v.push_back(2);
//     }
//     while (n % 2 == 0) {
//         n/=2;
//     }
//     for (int i = 3; i <= sqrt(n); i = i + 2) {
//         if(n%i==0) {
//             v.push_back(i);
//             while (n % i == 0) {
//                 n = n/i;
//             }
//         } 
//     }
//     v.push_back(n);
//     return v;
// }

vector<int> get_fact(int n) {
    vector<int> v;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            v.push_back(i);
            while(n%i==0) {
                n/=i;
            }
        }
    }
    v.push_back(n);
    return v;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    unordered_map<int,vector<int>> m;
    while(t--) {
        int x,y;
        cin>>x>>y;
        if(abs(x-y)==1) {
            cout<<"-1"<<endl;
        }
        else {
            if(gcd(x,y)>1) {
                cout<<"0"<<endl;
            }
            else {
                int diff=abs(x-y);
                vector<int> fact=get_fact(diff);
                int n=fact.size();
                vector<int> rem;
                for(int i=0;i<n;i++) {
                    rem.push_back(x%fact[i]);
                }
                vector<int> v;
                for(int i=0;i<n;i++) {
                    v.push_back(fact[i]-rem[i]);
                }
                int mi=INT_MAX;
                for(int i=0;i<n;i++) {
                    mi=min(mi,v[i]);
                }
                cout<<mi<<endl;
            }
        }
    }
}