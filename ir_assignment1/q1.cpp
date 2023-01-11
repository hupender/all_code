#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <cmath> 

using namespace std;

int string_edit_distance(string s1, string s2){

    int n1 = s1.size();
    int n2 = s2.size();

    int INF = n1+n2;

    vector<vector<int>> dist(n1+1, vector<int>(n2+1));

    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            if(i==0){
                dist[i][j] = j;
                continue;
            }
            if(j==0){
                dist[i][j] = i;
                continue;
            }

            else{
                int dist1 = dist[i-1][j] + 1;
                int dist2 = dist[i][j-1] + 1;
                int dist3 = dist[i-1][j-1] +1;

                int dist4 = INF;
                int dist5 = INF;
                if(i>=2 && j>=2){
                    //consider swaps also
                    if(s1[i-2]==s2[j-1] && s1[i-1] == s2[j-2]){
                        dist4 = 1 + dist[i-2][j-2];
                    }
                }
                
                if(s1[i-1] == s2[j-1]){
                    dist5 = dist[i-1][j-1] ;
                }

                dist4 = min(dist4, dist5);
                                

                dist[i][j] = min( min(dist1, dist4), min(dist2, dist3));
            }
        }
    }


    return dist[n1][n2];
}

int main(){

    string s1 = "execution";
    string s2 = "intention";

    cout << "Restricted Edit distance of " << s1 << " and " << s2 << " is \n";
    cout << string_edit_distance(s1, s2) << endl;

}
