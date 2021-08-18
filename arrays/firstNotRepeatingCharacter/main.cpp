/*

Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.

1. For s = "abacabad", the output should be
   firstNotRepeatingCharacter(s) = 'c'.

   There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

2. For s = "abacabaabacaba", the output should be
   firstNotRepeatingCharacter(s) = '_'.

   There are no characters in this string that do not repeat.

*/

#include<bits/stdc++.h>
using namespace std;

char firstNotRepeatingCharacter(string s) {
    unordered_map<char, int>N;
    unordered_map<char, vector<int>>M;
    int i=0;
    for(char x: s){
        N[x]++;
        M[x].push_back(i++);        
    }
    for(auto x: N){
        if(x.second == 1){
            i = min(i, M[x.first][0]);
        }
    }
    if(i == s.size()){
        return '_';
    } else {
        return s[i];
    }
}

int main(){
    int tests=0;
    cin >> tests;
    while(tests--){
        string s = "";
        cin >> s;
        cout << firstNotRepeatingCharacter(s);
    }
    return 0;
}
