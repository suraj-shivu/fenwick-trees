#include <iostream>

class FenwickTree{
    private:
        int* BIT;
        int size;
    public:
        FenwickTree(int n);
        void constructTree();
        int pointQuery(int p);
        int rangeQuery(int r, int l);
        void update(int i, int delta);
        void display();
        ~FenwickTree();
};
