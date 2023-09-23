#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int count=1,j=1,n=a.size();
        for(int i=1;i<n;i++) {
            if(count<2) {
                a[j]=a[i];
                j++;
                if(a[i]==a[i-1]) {
                    // a[j]=a[i];
                    // j++;
                    count++;
                }
                else {
                    // a[j]=a[i];
                    // j++;
                    count=1;
                }    
            }
            else {
                if(a[i]!=a[i-1]) {
                    a[j]=a[i];
                    j++;
                    count=1;
                }
            }
        }
        return j;
    }
};
int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<s.removeDuplicates(v)<<endl;
}