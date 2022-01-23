#pragma once
#include <vector>

class SegmentTree{
    public:
        std::vector<int> tree;

        SegmentTree(std::vector<int> const &arr);
        void update(int left, int right, int value);
    private:
        void updateUtil(int node, int left, int right, int value);
};