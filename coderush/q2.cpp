#include <bits/stdc++.h>
using namespace std;

int main() {
    

  int n;
  cin>>n;
  vector<vector<int>> v;
  for(int j=0;j<5;j++) {
      vector<int> v1;
      for(int i=0;i<n;i++) {
          int k;
          cin>>k;
          v1.push_back(k);
      }
      v.push_back(v1);
  }
  vector<vector<int>> res;
  int a,b;
  for(int k=0;k<4;k++) {
      for(int j=k+1;j<5;j++) {
          vector<int> v1=v[k];
          vector<int> v2=v[j];
          int val1,val2;
          for(int i=0;i<n;i++) {
              if(v1[i]!=v2[i]) {
                  val1=v1[i];
                  val2=v2[i];
                  break;
              }
          }
          vector<int> v3;
          for(int i=0;i<n;i++) {
              if(v1[i]==val1 || v1[i]==val2) {
                  continue;
              }
              else {
                v3.push_back(v1[i]);
              }
          }
          if(k==0 && j==1) {
              a=val1;
              b=val2;
          }
          res.push_back(v3);
      }
  }
  vector<int> v1=res[0];
  vector<int> final;
  int before_a=-1,before_b=-1,after_a=-1,after_b=-1;
  for(int i=0;i<10;i++) {
      for(int j=0;j<n-2;j++) {
          if(res[i][j]==a) {
              if(j-1>=0) {
                  before_a=res[i][j-1];
              }
              if(j+1<n-2) {
                  after_a=res[i][j+1];
              }
          }
          if(res[i][j]==b) {
              if(j-1>=0) {
                  before_b=res[i][j-1];
              }
              if(j+1<n) {
                  after_b=res[i][j+1];
              }
          }
      }
  }
  if(n==1 || n==2) {
    for(int i=0;i<n;i++) {
        cout<<v[0][i]<<endl;
    }
  }
  else {
    if(before_b==-1) {
        final.push_back(b);
        if(b=before_a) {
            final.push_back(a);
        }
        for(int i=0;i<n-2;i++) {
            if(v1[i]==before_a) {
                final.push_back(v1[i]);
                final.push_back(a);
            }
            else {
                final.push_back(v1[i]);
            }
        }
    }
    else if(before_a==-1) {
        final.push_back(a);
        if(a==before_b) {
            final.push_back(b);
        }
        for(int i=0;i<n-2;i++) {
            if(v1[i]==before_b) {
                final.push_back(v1[i]);
                final.push_back(b);
            }
            else {
                final.push_back(v1[i]);
            }
        }
    }
    else {
        for(int i=0;i<n-2;i++) {
            if(v1[i]==before_b) {
                final.push_back(v1[i]);
                final.push_back(b);
                if(b=before_a) {
                    final.push_back(a);
                }
            }
            if(v1[i]==before_a) {
                final.push_back(v1[i]);
                final.push_back(a);
                if(a=before_b) {
                    final.push_back(b);
                }
            }
            else {
                final.push_back(v1[i]);
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<final[i]<<endl;
    }
  }
    
  
  
  
  return 0;

}