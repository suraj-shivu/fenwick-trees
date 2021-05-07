#include<iostream>
#include<algorithm>
#include<vector>
#include<complex>
#include "generic_1D/fenwick_edit.hpp"
int main(){
	int n=4;
    
    std::cout << "Declaring complex fenwick tree using iterators of vector<complex<int>>.\n";
    std::vector<std::complex<int>> b(n);
    b[0] = {1,3};
    b[1] = {2,4};
    b[2] = {3,5};
    b[3] = {4,6};
    Fenwick_Tree<std::complex<int>, mul<std::complex<int>>> a(b.begin(),b.end());
	std::cout << "Printing Fenwick_Tree<complex<int>>.\n";
	std::cout << a;
	std::cout << "\n\n";
	
	std::cout << "Initializing a new fenwick tree using copy constructor by copying the previously constructed tree.\n";
    Fenwick_Tree<std::complex<int>, mul<std::complex<int>>> c(a);
	std::cout << "Printing fenwick tree created by copy constructor\n";
	std::cout << c;
	std::cout << "\n\n";

	std::vector<double> dbl = {1.1, 2.2, 3.3, 4.4};
	std::cout << "Declaring complex fenwick tree using iterators of vector<double>.\n";
	Fenwick_Tree<double, mul<double>> d {1.1, 2.2, 3.3 ,4.4};
	std::cout << "Printing Fenwick_Tree<double>.\n";
	std::cout << d << '\n';
	std::cout << "\n\n";

	std::cout << "Checking copy assignment.\n";
	Fenwick_Tree<double, mul<double>> e = d;
	std::cout << "Printing Fenwick_Tree<double>.\n";
	std::cout << e << '\n';
	std::cout << "\n\n";
    
	std::cout<<std::boolalpha;
	std::cout << "comparing a and c\n";
    std::cout<< "Are the equal? " << (a==c) << std::endl;
    std::cout<< "Are they different? " << (a!=c) << std::endl;
	std::cout << "\n\n";

	std::cout << "Point query at 2\n";
    std::cout<<a.point_query(2)<<std::endl;

	std::cout << "Range query between (1,2)\n";
    std::cout<<a.range_query(1,2)<<std::endl;
	std::cout << "\n\n";

    std::cout<<"Before range update"<<std::endl;
    std::cout<<a;
	std::cout << "\n";
    a.update(1,3,{1,2});
    std::cout<<"After range update"<<std::endl;
	std::cout << "\n";
    std::cout<< a;
    //stl testing

    //find
	std::cout << "\n\n";
    Fenwick_Tree<double, mul<double>>::Iterator p = std::find(d.begin(), d.end(), 1.1);
    if(p!=d.end())
        std::cout<<"Element found: "<<*p<<" at position "<<p-d.begin()<<std::endl;
    else
        std::cout<<"Element not found"<<std::endl;
	std::cout << "\n\n";

    // //print
	std::cout << "Printing tree before fill\n";
	std::cout << a;
	std::cout << "\n\n";
    //fill
	std::cout << "Printing tree after fill\n";
    std::fill(a.begin(), a.end(), 100);
	std::cout << a;

    return 0;
}
