/*

A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence between letters and digits,
such that the given arithmetic equation consisting of letters holds true when the letters are converted to digits.

You have an array of strings crypt, the cryptarithm, and an an array containing the mapping of letters and digits,
solution. The array crypt will contain three non-empty strings that follow the structure: [word1, word2, word3],
which should be interpreted as the word1 + word2 = word3 cryptarithm.

If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the mapping in solution,
becomes a valid arithmetic equation containing no numbers with leading zeroes, the answer is true.
If it does not become a valid arithmetic solution, the answer is false.

Note that number 0 doesn't contain leading zeroes (while for example 00 or 0123 do).

For crypt = ["SEND", "MORE", "MONEY"] and

solution = [['O', '0'],
            ['M', '1'],
            ['Y', '2'],
            ['E', '5'],
            ['N', '6'],
            ['D', '7'],
            ['R', '8'],
            ['S', '9']]
the output should be
isCryptSolution(crypt, solution) = true.

When you decrypt "SEND", "MORE", and "MONEY" using the mapping given in crypt, you get 9567 + 1085 = 10652 which is correct and a valid arithmetic equation.

For crypt = ["TEN", "TWO", "ONE"] and

solution = [['O', '1'],
            ['T', '0'],
            ['W', '9'],
            ['E', '5'],
            ['N', '4']]
the output should be
isCryptSolution(crypt, solution) = false.

Even though 054 + 091 = 145, 054 and 091 both contain leading zeroes, meaning that this is not a valid solution.

*/
#include<bits/stdc++.h>
using namespace std;

bool isCryptSolution(vector<string> crypt, vector<vector<char>> solution) {
    map<char, int> A;
    vector<int> N;
    for(int i=0;i<solution.size();i++){
        A[solution[i][0]] = solution[i][1] - 48;
        cout << solution[i][0] << " " << A[solution[i][0]] << "\n";
    }
    for(string x: crypt){
        int temp = 0, j=x.size()-1;
        for(char i: x){
            if(A[i] == 0 && j==x.size()-1 && x.size() != 1){
                return false;
            }
            temp+=(A[i])*(int)pow(10, j);
            j--;
        }
        N.push_back(temp);
    }
    cout << (N[0]+N[1]) << " " << N[2];
    return ((N[0]+N[1]) == N[2]);
}

int main(){
    int tests=0;
    cin >> tests;
    while(tests--){
        vector<string> S(3);
        for(int i=0;i<3;i++){
            cin >> S[i];
        }
        int chars = 0;
        cin >> chars;
        vector<vector<char>> X;
        for(int i=0;i<chars;i++){
            vector<int> temp(2);
            cin >> temp[0] >> temp[1];
            X.push_back(temp);
        }
        cout << isCryptSolution(S, X);
    }
}