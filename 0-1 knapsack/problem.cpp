#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void knapsack(vector<int> weights, vector<int> values, int capacity){
    struct ItemSelection{
        int value;  // item value
        int item;   // item index
        ItemSelection *previous;
    };

    // matrix with max value for row=item prefix, colum = capacity
    vector<vector<ItemSelection>> M = vector<vector<ItemSelection>>(
        values.size()+1, 
        vector<ItemSelection>(
            capacity+1, {0, 0, nullptr}
        )
    );

    int new_value, old_value;
    for(int item = 1; item <= values.size(); item++){
        for(int cap = 1; cap <= capacity; cap++){
            ItemSelection *current = &M[item][cap];
            current->item = item;

            // select item if better than the best selection with current capacity - weight
            if( values[item-1] + M[item-2][cap-weights[item-1]].value > M[item-2][cap].value){
                current->value = values[item-1] + M[item-2][cap-weights[item-1]].value;
                current->previous = &M[item-2][cap-weights[item-1]];
            }
            else{
                current->value = M[item-2][cap].value;
                current->previous = &M[item-2][cap];
            }
        }
    }

    ItemSelection* current = &M[values.size()][capacity];

    cout << "optimal items to insert in the knapsack: ";
    while (current->previous != nullptr)
    {
        cout << current->item << " ";
        current = current->previous;
    }
    cout << endl;
    
}

int main(){
    int items, weight, value, capacity;

    cout << "input number of items" << endl;
    cin >> items;

    vector<int> weights(items), values(items);

    cout << "input items weight and value";

    cin.ignore();
    for(int i = 0; i < items ; i++){
        string in;
        getline(cin, in);
        stringstream ss(in);

        ss >> weight;  
        weights[i] = weight;

        ss >> value;
        values[i] = value;
    }

    cout << "input knapsack capacity" << endl;
    cin >> items;
}