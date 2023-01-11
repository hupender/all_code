#include<bits/stdc++.h>
using namespace std;
#define ll long long 
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int sum=skill[0]+skill[n-1];
        ll chemistry=0;
        for(int i=0;i<n/2;i++) {
            if(skill[i]+skill[n-1-i]==sum) {
                chemistry+=skill[i]*skill[n-1-i];
            }
            else {
                return -1;
            }
        }
        return chemistry;
    }
};