#include <iostream>
#include <set>

// input vector must not contain duplicates
void traffic_lights(std::set<int> &N, int x) {

    std::set<int> A;
    std::multiset<int> D;
	A.insert(0); A.insert(x);

	A.insert(x);

    auto it = N.begin();
	while (it != N.end()){
        int cur = *it;

        // two iterators to the first element > i and first element < 1 
		auto it_right = A.upper_bound(cur), it_left = it_right; --it_left;
        
        // erase the distance between the elements at it1 and it2, if it exists
        // should always exist after the first iteration
        auto it_distance_to_delete = D.find(*it_right-*it_left);
        if(it_distance_to_delete != D.end()){
            D.erase(*it_distance_to_delete);
        }
        
        // insert two iterations
		D.insert(cur - *it_left); 
        D.insert(*it_right- cur);

		A.insert(cur);
		auto ans = D.end(); --ans;
		std::cout << *ans << " ";       // greatest distance is always at the end of the multiset

        it++;
	}
}

int main(){
    std::set<int> N{3,6,2};
    int x = 8;

    if(x < N.size()){
        std::cout << "x must be greater than the set size" << std::endl;  
        return 0;
    }

    traffic_lights(N, 8);
    return 0; 
}