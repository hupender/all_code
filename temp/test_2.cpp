#include<bits/stdc++.h>
using namespace std;

long unlockingKey(long key){
    long answer;

    vector<int> dig;
    long cur = key;
    int nzero = 0;
    while(cur!=0){
        int d= cur%10;
        if(d==0){
            nzero++;
        }
        else{
            dig.push_back(d);
        }
        cur /= 10;
    }

    sort(dig.begin(), dig.end());

    vector<int> adig;

    adig.push_back(dig[0]);
    for(int i=0; i<nzero; i++){
        adig.push_back(0);
    }
    for(int i=1; i<dig.size(); i++){
        adig.push_back(dig[i]);
    }

    answer = 0;

    for(int i : adig){
        answer = (answer*10) + i ;
    }

    return answer;

}

int main(){
    long x ;
    x = 765003;

    cout << unlockingKey(x) << endl;

}