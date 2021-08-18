/*

Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number for which the second occurrence has the minimal index.
In other words, if there are more than 1 duplicated numbers, return the number for which the second occurrence has a smaller index than the second occurrence of the other number does.
If there are no such elements, return -1.

1. For a = [2, 1, 3, 5, 3, 2], the output should be firstDuplicate(a) = 3.

   There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller index than the second occurrence of 2 does, so the answer is 3.

2. For a = [2, 2], the output should be firstDuplicate(a) = 2;

3. For a = [2, 4, 3, 5, 1], the output should be firstDuplicate(a) = -1.

*/

#include<bits/stdc++.h>
using namespace std;

int firstDuplicate(vector<int> a) {
    unordered_map<int, int>N;
    for(int x: a){
        N[x]++;
        if(N[x]>1){
            return x;
        }
    }
    return -1;
}

int main(){
    int tests=0;
    cin >> tests;
    while(tests--){
        int size=0;
        cin >> size;
        vector<int> arr(size);
        for(int i=0; i<size; i++){
            cin >> arr[i];
        }
        cout << firstDuplicate(arr);
    }
    return 0;
}
