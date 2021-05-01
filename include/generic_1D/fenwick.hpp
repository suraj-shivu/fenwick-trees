#include<iostream> 
#include<algorithm>
#include<iterator>

template <typename T>
class FenwickTree{
    private:
        T* BIT;
        int size;
    public:

	struct Iterator 
	{
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type   = std::ptrdiff_t;
		using value_type        = T;
		using pointer           = T*;
		using reference         = T&;

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }
		Iterator& operator++() { m_ptr++; return *this; }  
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
		friend T operator- (const Iterator a, const Iterator b) { return a.m_ptr - b.m_ptr; };
		friend T operator+ (const Iterator a, const Iterator b) { return a.m_ptr + b.m_ptr; };    

		private:
		pointer m_ptr;
	};

    Iterator begin() { return Iterator(&BIT[0]); }
    Iterator end()   { return Iterator(&BIT[size+1]); }
	FenwickTree(int n){
		size = n;
		BIT = new T[n+1];
		for(int i=0;i<=size;i++){
			BIT[i]=T();
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
    std::cout<<"Enter Elements\n";
    for(int i=0;i<size;++i){
        std::cin >> delta;
        update(i,delta);
    }
}
template <typename T>
T FenwickTree<T>::pointQuery(int p){
    T sum = T();
    ++p;
    while(p > 0){
        /* std::cout<<"INSIDE POINT "<<p<<" "<<sum<<" "<<BIT[p]<<std::endl; */
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
    T results[size+1];
    std::cout << "fenwick array internal: ";
    for(int i=0;i<=size;i++){
        std::cout<<BIT[i]<<" ";
        results[i] = pointQuery(i);
    }
    std::cout<<"\n";
    std::cout << "Cumulative Array:       ";
    for(int i = 0; i < size; i++) {
        std::cout << results[i] << " ";
    }
    std::cout<<"\n";
}
