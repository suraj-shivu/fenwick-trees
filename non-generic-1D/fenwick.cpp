#include<iostream>
#include<algorithm>
#include<vector>

class FenwickTree{
    private:
        int* BIT;
        int size;
    public:
        FenwickTree(int n){
            size = n;
            BIT = new int[n+1];
            for(int i=0;i<=size;i++){
                BIT[i]=0;
            }
        };
        void constructTree();
        int pointQuery(int p);
        int rangeQuery(int r, int l);
        void update(int i, int delta);
        void display();
        ~FenwickTree(){
            delete[] BIT;
        }
};
void FenwickTree::constructTree(){
    int delta;
    for(int i=0;i<size;++i){
        std::cout<<"Enter Elements\n";
        std::cin >> delta;
        update(i,delta);
    }
}
int FenwickTree::pointQuery(int p){
    int sum = 0;
    ++p;
    while(p > 0){
        std::cout<<"INSIDE POINT "<<p<<" "<<sum<<" "<<BIT[p]<<std::endl;
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
    for(int i=0;i<=size;i++){
        std::cout<<BIT[i]<<" ";
    }
    std::cout<<"\n";
}
int main(){
    int n=10;
    FenwickTree a(10);
    a.constructTree();
    std::cout<<a.pointQuery(4)<<std::endl;
    std::cout<<a.rangeQuery(4,9)<<std::endl;
    a.display();
    return 0;
}