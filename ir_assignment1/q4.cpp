#include<iostream>
#include<vector>
#include<string> 
#include <fstream>
#include <cmath>

using namespace std;

vector<string> read_file(ifstream& file){
    vector<string> file_lines;
    
    string curline = "";
    
    while(getline(file, curline)){
        file_lines.push_back(curline);
    }
    return file_lines;
}

int string_edit_distance(string s1, string s2){

    

    int n1 = s1.size();
    int n2 = s2.size();

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

            if(s1[i-1] == s2[j-1]){
                dist[i][j] = dist[i-1][j-1] ;
            }
            else{
                int dist1 = dist[i-1][j] + 1;
                int dist2 = dist[i][j-1] + 1;
                int dist3 = dist[i-1][j-1] +1;
                dist[i][j] = min( dist1, min(dist2, dist3));
            }
        }
    }


    return dist[n1][n2];
}


int file_edit_distance(const vector<string>& file1_lines, const vector<string>& file2_lines){
    int n1 = file1_lines.size();
    int n2 = file2_lines.size();

    vector<vector<int>> dist(n1+1, vector<int>(n2+1, -1));
    // dist[i][j] is the distance between file1 and file2
    // considering only file1_lines[0..i-1] and file2_lines[0...j-1]


    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            // base cases
            if(i==0 && j==0){
                dist[i][j] = 0;
                continue;
            }
            if(i==0){
                dist[i][j] = dist[i][j-1] + file2_lines[j-1].size();
                continue;
            }
            if(j==0){
                dist[i][j] = dist[i-1][j] + file1_lines[i-1].size();
                continue;
            }

            // main recurrence
            if(file1_lines[i-1] == file2_lines[j-1]){
                dist[i][j] = dist[i-1][j-1];
            }
            else{
                // delete
                int dist1 = dist[i-1][j] + 1;
                if(file1_lines[i-1]==""){
                    dist1 ++;
                }
                else{
                    dist1 += file1_lines[i-1].size();
                }
                // insert
                int dist2 = dist[i][j-1] + 1;
                if(file2_lines[j-1]==""){
                    dist2 ++;
                }
                else{
                    dist2 += file2_lines[j-1].size();
                }
                
                // replace
                int dist3 = dist[i-1][j-1] + string_edit_distance(file1_lines[i-1], file2_lines[j-1]);
            
                dist[i][j] = min( dist1, min(dist2, dist3));

            }
        }
    }



    return dist[n1][n2];

}

int main(){

    // string_edit_distance("four", "foor");

    string file1_name = "file1.txt";
    string file2_name = "file2.txt";

    ifstream file1(file1_name);
    ifstream file2(file2_name);

    // read all lines as strings
    vector<string> file1_lines = read_file(file1);
    vector<string> file2_lines = read_file(file2);

    file1.close();
    file2.close();

    cout << "edit distance of files = " << file_edit_distance(file1_lines, file2_lines) << endl;

}
