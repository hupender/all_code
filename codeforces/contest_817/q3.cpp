#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
        unordered_map<string,int> m;
        for(int i=0;i<n;i++) {
            string s;
            cin>>s;
            v1.push_back(s);
            m[s]++;
        }
        for(int i=0;i<n;i++) {
            string s;
            cin>>s;
            v2.push_back(s);
            m[s]++;
        }
        for(int i=0;i<n;i++) {
            string s;
            cin>>s;
            v3.push_back(s);
            m[s]++;
        }
        int count1=0,count2=0,count3=0;
        for(int i=0;i<n;i++) {

            //1st

            if(m[v1[i]]==1) {
                count1+=3;
            }
            if(m[v1[i]]==2) {
                count1+=1;
            }
            if(m[v1[i]]==3) {
                count1+=0;
            }

            //2nd 

            if(m[v2[i]]==1) {
                count2+=3;
            }
            if(m[v2[i]]==2) {
                count2+=1;
            }
            if(m[v2[i]]==3) {
                count2+=0;
            }

            //3rd

            if(m[v3[i]]==1) {
                count3+=3;
            }
            if(m[v3[i]]==2) {
                count3+=1;
            }
            if(m[v3[i]]==3) {
                count3+=0;
            }
        }
        cout<<count1<<" "<<count2<<" "<<count3<<" "<<endl;
    }
}