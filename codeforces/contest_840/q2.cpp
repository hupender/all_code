#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int solve_quadratic(int a,int b,int c,int k) {
    float d=(b*b-4*a*c);
    if(d<0) {
        return -1;
    }
    float x=sqrt(d);
    float x1=(-b)+x;
    x1/=(2*a);
    float x2=-(b+x);
    x2/=(2*a);
    if(x1>=0 && x2>=0) {
        return ceil(min(x1,x2));
    }
    else {
        return ceil(max(x1,x2));
    }
}
void solve2() {
    int n,k;
    cin>>n>>k;
    int health[n];
    for(int i=0;i<n;i++) {
        cin>>health[i];
    }
    int power[n];
    for(int i=0;i<n;i++) {
        cin>>power[i];
    }
    pair<int,int> a[n];
    for(int i=0;i<n;i++) {
        a[i]={power[i],health[i]};
    }
    sort(a,a+n);
    ll count=0;
    ll total_attack_power=0;
    int flag=1;
    for(int i=0;i<n;i++) {
        // number of attacs to kill ith monster
        // intial attack k
        // attck will form ap with difference power[i];
        // solve quardatic equation n^2*p+n(2*k-p)-2*h>=0
        if(a[i].second>total_attack_power) {
            // then only further attack is needed
            int a1=a[i].first;
            int a2=a[i].second-total_attack_power-k;
            int n=solve_quadratic(-a1,(2*k+a1),(-2*a2),k);
            if(n<0) {
                flag=0;
                break;
            }
            total_attack_power+=(n*(2*k-(n-1)*a1))/2;
            if(n>0) {
                k=k-(n-1)*a1;
            }
        }
    }
    if(flag) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}
void solve1() {
    int n,k;
    cin>>n>>k;
    vector<int> health;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        health.push_back(k);
    }
    vector<int> power;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        power.push_back(k);
    }
    int flag=1;
    while(k>0) {
        for(int i=0;i<n;i++) {
            if(health[i]>=k) {
                health[i]-=k;
            }
            else {
                health[i]=0;
            }
        }
        int flag=1;
        int mi=INT_MAX;
        for(int i=0;i<n;i++) {
            if(health[i]>0) {
                mi=min(mi,power[i]);
                flag=0;
            }
        }
        k-=mi;
        if(flag) {
            break;
        }
    }
    int flag1=1;
    for(int i=0;i<n;i++) {
        if(health[i]>0) {
            flag1=0;
            break;
        }
    }
    if(flag1) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
} 
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> health;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        health.push_back(k);
    }
    vector<int> power;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        power.push_back(k);
    }
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) {
        v.push_back({health[i],power[i]});
    }
    sort(v.begin(),v.end());
    int flag;
    while(k>0) {
        for(int i=0;i<n;i++) {
            if(v[i].first>=k) {
                v[i].first-=k;
            } 
            else {
                v[i].first=0;
            }
        }
        flag=1;
        int least_power=INT_MAX;
        for(int i=0;i<n;i++) {
            if(v[i].first>0) {
                least_power=min(least_power,v[i].second);
                flag=0;
                break;
            }
        }
        k-=least_power;
        if(flag) {
            break;
        }
    }
    // int flag=1;
    // for(int i=0;i<n;i++) {
    //     if(v[i].first>0) {
    //         flag=0;
    //         break;
    //     }
    // }
    if(flag) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
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
    for(int i=1;i<=t;i++) {
        if(i==24) {
            int n,k;
            cin>>n>>k;
            int health[n];
            for(int i=0;i<n;i++) {
                cin>>health[i];
            }
            int power[n];
            for(int i=0;i<n;i++) {
                cin>>power[i];
            }
            cout<<n<<" "<<k<<endl;
            for(int i=0;i<n;i++) {
                cout<<health[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<n;i++) {
                cout<<power[i]<<" ";
            }
            cout<<endl;
            

        }
        else {
            solve2();
        }
        
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}