#include <iostream>
#include<map>
#include <vector>

using namespace std;

int solve(vector<int> weights){
    int n= weights.size();
    map<int, int> freq;
    for(int i : weights){
        freq[i]++;
    }

    int res = 0;

    for(auto i : freq){
        int f = i.second;
        if(f==1){
            res = -1;
            break;
        }

        if(f<=3){
            res++;
        }
        else{
            int q3 = f/3;
            int r3 = f%3;

            if(r3==0){
                res += q3;
            }
            else{
                res += q3;
                res++;
            }

        }
    }

    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> w(n);

    for(int i=0; i<n; i++){
        cin>>w[i];
    }

    


}