// Basic implementation of flood fill
#include <iostream>
#include <vector>
#include <string>
#include <stack>

std::vector<std::vector<std::pair<int, int>>> floodfill( const std::vector<std::vector<int>> &m){
    const int columns = m.size();
    const int rows = m[0].size();

    // used to visit adjacent cells
    const int ROW_CHANGE[]{0, 1, 0, -1};         
    const int COLUMN_CHANGE[]{1, 0, -1, 0};
    
    int visited[columns][rows] = {};    // store the fill result in this matrix
    
    std::vector<std::vector<std::pair<int, int>>> components;    // vector of connected components
    
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if(!visited[i][j]){     // conditions for when to skip filling from the current cell

                std::stack<std::pair<int, int>> frontier;   // stack of cells to visit

                frontier.push({i, j});
                std::vector<std::pair<int, int>> new_component{};
                int color = m[i][j];    // color for the next component

                while(!frontier.empty()) 
                {
                    // process a connected component
                    
                    int column = frontier.top().first;
                    int row = frontier.top().second;
                    frontier.pop();
                    
                    // check that the cell's color is equal to that of the component
                    // plus other problem-specific conditions
                    if (m[column][row] != color) 
                    {
                        continue;
                    }
                    
                    visited[column][row] = true;
                    new_component.push_back({column, row});

                    for( int k = 0; k < 4; k++)
                    {
                        int next_row = row + ROW_CHANGE[k];
                        int next_column = column + COLUMN_CHANGE[k];

                        // don't push cells outside the original matrix or already visited
                        if(next_row < 0 || next_row >= rows || next_column < 0 || next_column >= columns || visited[next_column][next_row])
                        {
                            continue;
                        }
                        frontier.push({next_column, next_row});
                    }
                        
                }
                // add new component to the 
                components.push_back(new_component);
                int a = 2;
            }

        }
    }
    return components;
}

int run_default(){
    std::vector<std::vector<int>> mat{
        {1, 1, 1, 3},
        {1, 2, 3, 3},
        {1, 2, 1, 1}
    };
    std::vector<std::vector<std::pair<int, int>>> components = floodfill(mat);

    for (int i = 0; i < components.size(); i++)
    {
        std::cout << "component " << i << ", value " << mat[components[i][0].first][components[i][0].second] << " : ";

        for (int j = 0; j < components[i].size(); j++)
        {
            std::cout << "[" << components[i][j].first << ", " << components[i][j].second << "] ";
        }

        std::cout << std::endl;
    }
    

    return 0; 
}

int run_input(){
    int n, m;
    std::vector<std::vector<int>> mat;
    
    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> mat[i][j];
        }
    }
    std::vector<std::vector<std::pair<int, int>>> components = floodfill(mat);
    return 0; 
}

int main(){
    run_default();
    return 0;
}