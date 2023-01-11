#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

void solve1(ll n) {
    if(n<=6) {
        cout<<"15"<<endl;
    }
    else {
        ll r=(n+1)/2;
        r*=5;
        cout<<r<<endl;
    }
}

void solve(ll n) {
    ll p1=(n/6)*15;
    ll r1=n%6;
    ll p2=p1;
    if(r1!=0) {
        p1+=15;
        if(r1==1 || r1==2) {
            if(p2>0) {
                p2-=15;
                p2+=20;
            }  
        }
        else if(r1==3 || r1==4) {
            if(p2==1) {
                p2+=25-15;
            }
            else if(p2>1) {
                p2-=15*2;
                p2+=20*2;
            }
        }
        else {
            if(p2>2) {
                p2-=15*3;
                p2+=20*3;
            }
        }
    }
    ll p3=(n/8)*20;
    ll r3=n%8;
    ll p4=p3;
    if(r3!=0) {
        p3+=20;
        if(r3==1 || r3==2) {
            if(p4>0) {
                p4-=20;
                p4+=25;
            }
        }
        else if(r3==3 || r3==4) {
            if(p4>1) {
                p4-=20*2;
                p4+=25*2;
            }
        }
        else if(r3==5 || r3==6) {
            if(p4>2) {
                p4-=20*3;
                p4+=25*3;
            }
        }
        if(r3==7) {
            if(p4>3) {
                p4-=20*4;
                p4+=25*4;
            }
        }
    }
    ll p5=(n/10)*25;
    ll r5=n%10;
    ll p6=p5;
    if(r5!=0) {
        p5+=25;
        if(r5<=6) {
            p6+=15;
        }
        else if(r5<=8) {
            p6+=20;
        }
        else {
            p6+=25;
        }
    }
    vector<ll> v;
    if(p1) {
        v.push_back(p1);
    }
    if(p2) {
        v.push_back(p2);
    }
    if(p3) {
        v.push_back(p3);
    }
    if(p4) {
        v.push_back(p4);
    }
    if(p5) {
        v.push_back(p5);
    }
    if(p6) {
        v.push_back(p6);
    }
    sort(v.begin(),v.end());
    ll r=v[0];
    // r=min(p1,min(p2,min(p3,min(p4,min(p5,p6)))));
    cout<<r<<endl;
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
        ll n;
        cin>>n;
        solve1(n);
        // if(n%6==0) {
        //     cout<<15*(n/6)<<endl;
        // }
        // else if(n%8==0) {
        //     cout<<20*(n/8)<<endl;
        // }
        // else {
        //     ll q=n/10;
        //     ll r=q*25;
        //     ll rem=n%10;
        //     ll r1=(n/6)*15+15;
        //     ll r2=(n/8)*20;
        //     if(n%8<=6) {
        //         r2+=15;
        //     }
        //     else {
        //         r2+=20;
        //     }
        //     ll r3=min(r1,r2);
        //     if(rem==0) {
        //         cout<<r<<endl;
        //     }
        //     else if(rem<=6) {
        //         r+=15;
        //         cout<<min(r,r3)<<endl;
        //     }
        //     else if(rem<=8) {
        //         r+=20;
        //         cout<<min(r,r3)<<endl;
        //     }
        //     else {
        //         r+=25;
        //         cout<<min(r,r3)<<endl;
        //     }
        // }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}