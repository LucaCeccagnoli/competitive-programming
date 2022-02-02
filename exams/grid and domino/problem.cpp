#include <vector>
#include <iostream>

#define DIFF(x, y) y - (y-x) 

using namespace std;

int query(int r1, int c1, int r2, int c2, vector<vector<int>> const &S){
    return S[r2][c2] - (
        S[r2][DIFF(c1, c2)] + S[DIFF(r1, r2)][c2] - S[DIFF(r1,r2)][DIFF(c1,c2)]
    );
}

int main(){
    int h, w, q;
    cin >> h >> w;

    vector<vector<char>> grid = vector<vector<char>>(h, vector<char>(w));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
        cin.ignore();
    }

    // contains total number of placements in grid from (0,0) to (i,j)
    vector<vector<int>> S = vector<vector<int>>(h, vector<int>(w, 0));

    // initialize sum matrix
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int val = S[i-1][j-1];
            if(grid[i][j] == '#') val += 0;
            else{
                if(j-1 >= 0 && grid[i][j-1] == '.') val += 1;
                if(i-1 >= 0 && grid[i-1][j] == '.') 
                    val += 1;
            }
            S[i][j] = val;
        }
    }

    cin >> q;
    int r1, c1, r2, c2;
    for(int i = 0; i < q; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        cout << query(r1,c1,r2,c2,S);
        cin.ignore();
    }
}