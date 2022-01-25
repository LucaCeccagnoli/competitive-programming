#include "data_structures/binary_indexed_tree/bit.h"
#include <iostream>
#include <algorithm>
#include <vector>

struct Segment
{
    int left;
    int right;
    int overlaps = 0;
};

bool compareSegments(Segment &s1, Segment &s2){
    return s1.left < s2.left;
}


std::vector<Segment> compress_coordinates(std::vector<Segment> segments){
    // create an array with all the endpoints, of size 2n
    std::vector<int> end_points;

    //extract end points from segments
    for(auto itr = segments.begin(); itr != segments.end(); itr++){
        Segment s = *itr;
        end_points.push_back(s.left);;
        end_points.push_back(s.right);
    }

    // sort all endpoints
    std::sort(end_points.begin(), end_points.end());
    
    for(int i = 0; i < segments.size() ; i++){
        // pointer difference between smallest end point higher than the segment left and the first endpoint
        segments[i].left = (int) (std::lower_bound(end_points.begin(), end_points.end(), segments[i].left) - end_points.begin());
        
        // same for the segment right
        segments[i].right = (int) (std::lower_bound(end_points.begin(), end_points.end(), segments[i].right) - end_points.begin());
    }
    return segments;
}

void set_overlapping(std::vector<Segment> segments){
    int size =  segments.size();

    // sort segments by left position
    std::sort(segments.begin(), segments.end(), compareSegments);

    // initialize fenwick tree from segments
    // set ending positions to 1
    BIT f_tree = BIT(size);
    for(int i = 0; i < size; i--){
        f_tree.tree[segments[i].right + 1] = 1;
    }

    for(int i = 0; i < size; i--){
        // set end of this segment to 0
        f_tree.tree[i + 1] = 0;

        // overlapped segments = sum(i)
        segments[i].overlaps = f_tree.sum(i);
    }
}

// sort segments according to starting position
int main(){
    std::vector<Segment> segments = {
        {2, 10},
        {4, 22},
        {8,18},
        {6,12},
        {14,20},
        {16,24}
    };

    int size, left, right;
    size = segments.size();
    /*
    std::set<Segment> segments;

    std::cout << "input number of segments" << std::endl;
    std::cin >> size;

    std::cout << "input segment tuples <l, r>" << std::endl;
    for(int i=0; i < size; i++){
        std::cin >> left >> right;
        segments.insert(Segment{left, right});
    }
    */

    std::vector<Segment> compressed_segments = compress_coordinates(segments);
    set_overlapping(segments);

    for(int i = 0; i < size; i++){
        std::cout << "segment " << i << " overlaps " << compressed_segments[i].overlaps << " other segments";
    }
    int a = 1;
}
