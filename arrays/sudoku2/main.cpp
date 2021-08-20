/*

Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above. Note that the puzzle represented by grid does not have to be solvable.

1.  For

    grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
            ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
            ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
            ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
            ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
            ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
            ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
    the output should be
    sudoku2(grid) = true;

2.  For

    grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
            ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
            ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
            ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
            ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
            ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
            ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
            ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
    the output should be
    sudoku2(grid) = false.

The given grid is not correct because there are two 1s in the second column. Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.

*/

#include<bits/stdc++.h>
using namespace std;

bool sudoku2(vector<vector<char>> grid) {
    vector<char> S1;
    vector<char> S2;
    vector<char> S3;
    for(int i=0;i<9;i++){
        vector<char> R;
        vector<char> C;
        for(int j=0;j<9;j++){
            if(grid[i][j]!='.')
                R.push_back(grid[i][j]);
            if(grid[j][i]!='.'){
                C.push_back(grid[j][i]);
                if(j<3){
                    S1.push_back(grid[j][i]);
                } else if(j<6){
                    S2.push_back(grid[j][i]);
                } else {
                    S3.push_back(grid[j][i]);
                }
            }
        }
        set<char>RC(R.begin(), R.end());        
        set<char>CC(C.begin(), C.end());        
        if(RC.size() != R.size() || CC.size() != C.size()){
            //cout << "Row/Col " << i;
            return false;
        }
        if((i+1)%3 == 0){
            set<char>S1C(S1.begin(), S1.end());
            set<char>S2C(S2.begin(), S2.end());
            set<char>S3C(S3.begin(), S3.end());
            if(S1C.size() != S1.size() || S2C.size() != S2.size() || S3C.size() != S3.size()){
                //cout << "Diag " << i;
                return false;
            }
            S1.clear();
            S2.clear();
            S3.clear();
        }
    }
    return true;
}

int main(){
    int tests=0;
    cin >> tests;
    while(tests--){
        vector<vector<int>>A;
        for(int i=0;i<9;i++){
            vector<int> temp(N);
            for(int j=0;j<9;j++){
                cin >> temp[j];
            }
            A.push_back(temp);
        }
        cout << sudoku2(A);
    }
}