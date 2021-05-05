#include<iostream>
#include<algorithm>
#include<vector>
#include "generic_1D/fenwick_edit.hpp"
int main(){
    int n=10;
    Fenwick_Tree<double> a(n),c(n);  //declare type here
    std::vector<double> b{1,2,3,4,5,6,7,8,9,10};
    c.make_tree(b.begin(),b.end(),b.size());
    a.construct_tree();
    //Fenwick_Tree<double> c = a;
    std::cout<<a.point_query(5)<<std::endl;
    std::cout<<a.range_query(4,9)<<std::endl;
    //c.update(1,3,1);
    a.display();
    
    //stl testing

    //find
	const float val = 1.0;
    Fenwick_Tree<double>::Iterator p = std::find(a.begin(), a.end(), 1.0);
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
