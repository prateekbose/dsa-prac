/*

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

For
a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
the output should be

rotateImage(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]

*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateImage(vector<vector<int>> a) {
    int s = a.size();
    int A[s][s];
    vector<vector<int>>R(s);
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            A[i][j] = a[s-1-j][i];
        }
        R[i] = vector<int>(A[i], A[i]+s);
    }
    return R;
}

void print_vector(vector<vector<int>> a){
    for(auto x: a){
        cout << "\n";
        for(int y: x){
            cout << y << " ";
        }
    }
}

int main(){
    int tests=0;
    cin >> tests;
    while(tests--){
        int size = 0;
        cin >> size;
        vector<vector<int>>A;
        for(int i=0; i<size; i++){
            vector<int>temp(size);
            for(int j=0; j<size; j++){
                cin >> temp[j];
            }
            A.push_back(temp);
        }
        print_vector(rotateImage(A));
    }
}
