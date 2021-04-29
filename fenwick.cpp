#include<iostream>
#include<algorithm>
#include<vector>
template <typename T>
class FenwickTree{
    private:
        T* BIT;
        int size;
    public:
        FenwickTree(int n){
            size = n;
            BIT = new T[n+1];
            for(int i=0;i<=size;i++){
                BIT[i]=0;
            }
        };
        void constructTree();
        T pointQuery(int p);
        T rangeQuery(int r, int l);
        void update(int i, T delta);
        void display();
        ~FenwickTree(){
            delete[] BIT;
        }
};
template <typename T>
void FenwickTree<T>::constructTree(){
    T delta;
    for(int i=0;i<size;++i){
        std::cout<<"Enter Elements\n";
        std::cin >> delta;
        update(i,delta);
    }
}
template <typename T>
T FenwickTree<T>::pointQuery(int p){
    T sum = T();
    ++p;
    while(p > 0){
        std::cout<<"INSIDE POINT "<<p<<" "<<sum<<" "<<BIT[p]<<std::endl;
        sum += BIT[p];
        p -= p & (-p);
        
    }
    return sum;
}
template <typename T>
T FenwickTree<T>::rangeQuery(int l, int r){
    return pointQuery(r) - pointQuery(l);
}
template <typename T>
void FenwickTree<T>::update(int i, T delta){
    ++i;
    while(i <= size){
        BIT[i] += delta;
        i += i & (-i);
    }
}
template <typename T>
void FenwickTree<T>::display(){
    for(int i=0;i<=size;i++){
        std::cout<<BIT[i]<<" ";
    }
    std::cout<<"\n";
}

int main(){
    int n=10;
    FenwickTree<float> a(n);  //declare type here
    a.constructTree();
    std::cout<<a.pointQuery(4)<<std::endl;
    std::cout<<a.rangeQuery(4,9)<<std::endl;
    a.display();
    return 0;
}
