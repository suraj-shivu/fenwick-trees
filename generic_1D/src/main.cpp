#include<iostream>
#include<algorithm>
#include<vector>
#include "generic_1D/fenwick.hpp"
int main(){
    int n=12;
    FenwickTree<int> a(n);  //declare type here
    a.constructTree();
    std::cout<<a.pointQuery(5)<<std::endl;
    std::cout<<a.rangeQuery(4,9)<<std::endl;
    a.display();
    return 0;
}
