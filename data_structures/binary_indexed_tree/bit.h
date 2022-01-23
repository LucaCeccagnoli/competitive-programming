#pragma once
#include <vector>

class BIT{
    public:
        std::vector<int> tree;

        BIT(int size);
        BIT(std::vector<int> const &arr);
        int sum(int index);
        void update(int index, int value);

    private:
        int succ(int i);
        int prev(int i);
};