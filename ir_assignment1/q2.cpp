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
                
                // transposition distance
                int dist5 = INF;
                
                // s1[0....i-1] to be converted to s2[0...j-1]
                // we convert s1[0...i-3] to s2[0.....k] where k < j-1 and k < i-1
                // then we have s1[i-2,i-1] and s2[k+1....j-1]
                
                // if s1[i-1] == s2[k+1] and s1[i-2] == s2[j-1]
                // ->we will swap s1[i-2] with s1[i-1]
                // -> and we will insert characters s2[k+2....j-2] 
                
                for(int k=0; k<j-1 && k<i-1; k++){
                    if(s1[i-1] == s2[k+1] && s1[i-2] == s2[j-1] ){
                        int cur_dist5 = dist[i-2][k+1] + 1 + (j-2 - (k+2) + 1);
                        dist5 = min(dist5, cur_dist5);
                    }
                }
                
                if(s1[i-1] == s2[j-1]){
                    dist4 = dist[i-1][j-1] ;
                }

                
                dist4 = min(dist4, dist5);
                                

                dist[i][j] = min( min(dist1, dist4), min(dist2, dist3));
                
                //printf("i = %d, j = %d, dist[i][j] = %d\n", i, j, dist[i][j]);
                
            }
        }
    }


    return dist[n1][n2];
}

int main(){

    string s1 = "a cat";
    //           01234
    string s2 = "an abct";
    //           0123456                            
    
    getline(cin, s1);
    getline(cin, s2);
    
    
    
    cout << "Dameru distance of " << s1 << " and " << s2 << " is \n";
    cout << string_edit_distance(s1, s2) << endl;

}
