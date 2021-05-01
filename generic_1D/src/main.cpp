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
    
    //stl testing

    //find
    FenwickTree<int>::Iterator p=std::find(a.begin(), a.end(), 3);
    if(p!=a.end())
        std::cout<<"Element found: "<<*p<<" at position "<<p-a.begin()<<std::endl;
    else
        std::cout<<"Element not found"<<std::endl;     
    //print
    for(auto i: a)
    std::cout<<i<<std::endl;
    //fill
    std::fill(a.begin(), a.end(), 100);
    for(auto i: a)
    std::cout<<i<<std::endl;
    return 0;
}
