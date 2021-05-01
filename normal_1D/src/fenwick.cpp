#include<iostream>
#include "normal_1D/fenwick.hpp"
/* #include<algorithm> */
/* #include<vector> */
FenwickTree::FenwickTree(int n){
	this->size = n;
	this->BIT = new int[n+1];
	for(int i=0;i<=this->size;i++){
		BIT[i]=0;
	}
};
FenwickTree::~FenwickTree(){
	delete[] this->BIT;
}
void FenwickTree::constructTree(){
    int delta;
	std::cout<<"Enter Elements\n";
    for(int i=0;i<size;++i){
        std::cin >> delta;
        update(i,delta);
    }
}
int FenwickTree::pointQuery(int p){
    int sum = 0;
    ++p;
    while(p > 0){
        /* std::cout<<"INSIDE POINT "<<p<<" "<<sum<<" "<<BIT[p]<<std::endl; */
        sum += BIT[p];
        p -= p & (-p);
        
    }
    return sum;
}
int FenwickTree::rangeQuery(int l, int r){
    return pointQuery(r) - pointQuery(l);
}
void FenwickTree::update(int i, int delta){
    ++i;
    while(i <= size){
        BIT[i] += delta;
        i += i & (-i);
    }
}
void FenwickTree::display(){
	int results[size+1];
	std::cout << "\n";
    std::cout << "fenwick array internal: ";
    for(int i=0;i<=size;i++){
        std::cout<<BIT[i]<<" ";
		results[i] = pointQuery(i);
    }
	std::cout << "\n";
    std::cout << "Cumulative Array:       ";
	for (int i = 0; i < size; i++) {
		std::cout << results[i] << " ";
	}
	std::cout << "\n";
    std::cout<<"\n";
}
