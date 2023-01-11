#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream inp("input.txt");
    ofstream out("output.txt");

    int m, n;

    inp >> m >> n ;

    vector<vector<int>> v(m, vector<int>(n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            inp>>v[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            out << v[i][j] << " ";
        }
        out << "\n";
    }
    

}

