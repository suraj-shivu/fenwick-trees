#include <iostream>
#include "normal_1D/fenwick.hpp"
int main(){
    int n=12;
    FenwickTree a(n);
    a.constructTree();
    std::cout<<a.pointQuery(5)<<std::endl;
    std::cout<<a.rangeQuery(4,9)<<std::endl;
    a.display();
    return 0;
}
