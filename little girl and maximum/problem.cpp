#include <iostream>
#include <vector>
#include <algorithm>
#include <set>          // binary search tree

// array item that also stores query endpoints
struct QueryItem{
    int value;
    int q_starts;
    int q_ends;

    QueryItem(int value): value(value){
        q_starts = 0;
        q_ends = 0;
    }
};

struct FrequencyItem{
    int value;
    int index;

    FrequencyItem(int value, int index): value(value), index(index){}
};

bool compareQueryItems(QueryItem &q1, QueryItem &q2){
    return q1.value < q2.value;
}

bool compareFrequencyItems(FrequencyItem &f1, FrequencyItem &f2){
    return f1.value < f2.value;
}

std::vector<int> lg_maximum(std::vector<QueryItem> elements){
    int freq = 0, size = elements.size();
    std::vector<FrequencyItem> frequencies;

    std::vector<int> permutation(size, 0);   

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < elements[i].q_starts; j++)
        {
            // increase frequency for every query that starts here
            freq++;     
        }
        
        // assign new frequency here since endpoints are inclusive
        frequencies.push_back(FrequencyItem(freq, i));

        for(int j = 0; j < elements[i].q_ends; j++)
        {
            // decrease frequency for every query that ends here
            freq--;     
        }
    }
    
    // sort input array elements in ascending order.
    std::sort(elements.begin(), elements.end(), compareQueryItems);
    std::sort(frequencies.begin(), frequencies.end(), compareFrequencyItems);

    // iterate set from highest to lowest values
    for(int i = size - 1; i >= 0; i--){
        permutation[frequencies[i].index] = elements[i].value;
    }
    return permutation;
}

int main(){
    int arr_size, query_size;
    std::vector<QueryItem> elements;

    std::cout << "input array size" << std::endl;
    std::cin >> arr_size;
    std::cout << "input number of queries" << std::endl;
    std::cin >> query_size;

    std::cout << "input array elements" << std::endl;
    for(int i=0; i < arr_size; i++){
        int value;
        std::cin >> value;
        elements.push_back(QueryItem(value));
    }

    std::cout << "input queries" << std::endl;
    for(int i=0; i < query_size; i++){
        int left, right;
        std::cin >> left >> right;
        elements[left].q_starts++;
        elements[right].q_ends++;
    }

    std::vector<int> permutation = lg_maximum(elements);
    std::cout << "optimal permutation for the given queries:" << std::endl;
    for(int i = 0; i < permutation.size(); i++){
        std::cout << permutation[i] << "\t" << std::endl;
    }
    std::cout << std::endl;
}