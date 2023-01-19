#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 
void solve1() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int count_0=0;
    int ind=0;
    for(int i=0;i<n;i++) {
        if(a[i]==0) {
            count_0++;
        }
        else {
            ind=i;
            break;
        }
    }
    int count_going=count_0;
    int count_needed=0;
    int res=0;
    int flag=0;
    if(count_0==0) {
        res++;
        flag=1;
    }
    else {
        if(a[ind]>count_going) {
            res++;
            flag=1;
        }
    }
    int last_ind;
    
    for(int i=ind;i<n;i++) {
        if(count_needed>count_going) {
            // this person has to go otherwise the combination will fail 
            count_going++;
            count_needed=a[i]+1;
            if(count_needed==count_going) {
                // adding this person is ensuring that the last combinatoin has worked
                if(a[i+1]<=count_going) {
                    continue;;
                }
                else {
                    last_ind=i;
                    res++;
                }
            }
        }
        else {
            if(a[i]>count_going) {
                // here the number of people going is less and count needed is ok
                // so he can stay 
                // res++;
                if(flag==0) {
                    res++;
                    flag=1;
                }
                count_needed=a[i]+1;
                count_going++;
            }
            else {
                // this person has to go otherwise he will be sad
                count_needed=a[i]+1;
                count_going++;
            }
        }
    }
    if(count_going>=count_needed && last_ind!=n-1) {
        res++;
    }
    cout<<res<<endl;
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int count_0=0;
    int ind=0;
    for(int i=0;i<n;i++) {
        if(a[i]==0) {
            count_0++;
        }
        else {
            ind=i;
            break;
        }
    }
    int count=1;
    int count_going=count_0;
    int need=0;
    for(int i=ind;i<n;i++) {
        if(a[i]>count_going) {
            count++;
            int diff=a[i]-count_going;
            count_going+=diff;
            i+=diff;
            int val=a[i];
            i++;
            while(i<n && a[i]==val) {
                i++;
                count_going++;
            }
            i--;
            if(count_going<val) {
                need=val-count_going;
            }
            count_going++;
        }
        else {
            count_going++;
        }
    }
    cout<<count<<endl;
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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}