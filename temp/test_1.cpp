#include<bits/stdc++.h>
using namespace std;

int countCustomers(vector<int> bill){

    int answer=0;

    for(int i : bill){
        int rt = sqrt(bill[i]);
        if(rt*rt == bill[i]){
            answer++;
        }
    }


    return answer;
}