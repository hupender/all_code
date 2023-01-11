//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif
	vector<string> v;
  	for(int i=0;i<10;i++) {
      	string s;
		cin>>s;
      	v.push_back(s);
    }
  	int a,b,c,d,flag1=0;
  	for(int i=0;i<10;i++) {
		for(int j=0;j<v[i].size();j++) {
			if(v[i][j]=='#') {
              	a=i+1;
              	c=j+1;
              	flag1 = 1;	
              	break;
              	
            }
        }
      	if(flag1) break;
    }
  	for(int j=0;j<v[a-1].size();j++) {
    	if(v[a-1][j]=='#') {    
			d=j+1;
        }
    }
  	for(int i=0;i<10;i++) {
      	if(v[i][c-1]=='#') {
			b=i+1;
        }
    }
    cout<<a<<" "<<b<<endl;
    cout<<c<<" "<<d<<endl;
}