#include<iostream>
#include<algorithm>
#include<vector>
#include<complex>
#include "generic_1D/fenwick_edit.hpp"
int main(){
    int n=4;
    //Fenwick_Tree<double> a(n); //declare type here
    std::vector<std::complex<int> > b(n);
    b[0] = {1,3};
    b[1] = {2,4};
    b[2] = {3,5};
    b[3] = {4,6};
    Fenwick_Tree<std::complex<int> > a(b.begin(),b.end());
    //a.make_tree(b.begin(),b.end(),b.size());
    //a.construct_tree();
    //b[0]=2;
     Fenwick_Tree<std::complex<int> > c(a);
    // Fenwick_Tree<double> d(a);


    std::cout<<std::boolalpha;
    std::cout<< (a==c) << std::endl;
    std::cout<< (a!=c) << std::endl;
    std::cout<<a.point_query(2)<<std::endl;
    std::cout<<a.range_query(1,2)<<std::endl;
    std::cout<<"Before range update"<<std::endl;
    std::cout<<a;
    a.update(1,3,{1,2});
    std::cout<<"After range update"<<std::endl;
    std::cout<< a;
    //b.display();
    //stl testing

    //find
	const float val = 1.0;
    // Fenwick_Tree<double>::Iterator p = std::find(a.begin(), a.end(), {1,2});
    // if(p!=a.end())
    //     std::cout<<"Element found: "<<*p<<" at position "<<p-a.begin()<<std::endl;
    // else
    //     std::cout<<"Element not found"<<std::endl;     
    // //print
    for(auto i: a)
    std::cout<<i<<std::endl;
    //fill
    std::fill(a.begin(), a.end(), 100);
    for(auto i: a)
    std::cout<<i<<std::endl;
    return 0;
}
