#include<bits/stdc++.h>
using namespace std;
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    for(int x=1;x<=t;x++) {
        string s;
        cin>>s;
        int l=s.length(),count_v=0,count_c=0;
        int count[26]={0};
        for(int i=0;i<l;i++) {
            count[s[i]-'A']++;
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') {
                count_v++;
            }
            else {
                count_c++;
            }
        }

        int max_occurence_cont=0,max_occurence_vowel=0,ind_const,ind_vowel;
        for(int i=0;i<26;i++) {
            if(i==0 || i== 4 || i==8 || i==14 || i==20) {
                max_occurence_vowel=max(max_occurence_vowel,count[i]);
                // ind_const=i;
            }
            else {
                max_occurence_cont=max(max_occurence_cont,count[i]);
                // ind_vowel=i;
            }
        }
        // if(count_c==0) {
        //     int ans=
            
        // }
        int ans1=count_c+2*(count_v-max_occurence_vowel);
        int ans2=2*(count_c-max_occurence_cont)+count_v;
        if(ans1==0 || ans2==0) {
            cout<<"Case #"<<x<<": "<<"0"<<endl;
        }
        else {
            int ans=min(ans1,ans2);
            cout<<"Case #"<<x<<": "<<ans<<endl;
        }
        
    }
}