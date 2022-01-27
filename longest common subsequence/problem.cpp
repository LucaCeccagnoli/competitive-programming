#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// return length of the longest common subsequence between two strings
int lcs(string const &s1, string const &s2){
    // matrix storing lcs
    vector<vector<int>> M = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            int size = s2.size();
            char c1 = s1[i];
            char c2 = s2[j];

            if(s1[i] == s2[j]){
                // add new element to the subsequence
                M[i+1][j+1] = 1 + M[i][j];
            }
            else{
                M[i+1][j+1] = max(M[i][j+1], M[i+1][j]);
            }
        }
    }

    return M[s1.size()][s2.size()];
}

int main(){
    string str1, str2;
    int length1, length2;

    //cin.ignore();
    cout << "input the first string" << endl;
    getline(cin, str1);

    cout << "input the second string" << endl;
    getline(cin, str2);
    cout << str2 << endl;

    cout << "length of the longest common subsequence: " << lcs(str1, str2) << endl;
}