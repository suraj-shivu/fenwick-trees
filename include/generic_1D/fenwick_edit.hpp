/* TODO:
        Few operators
        convert to stl definition
        i cant figure out how to overload replace without making it a member/friend function
        static type checks
        error handling
   WORK DONE: 
        This is just a edit of the original + few constructors + range update
        Done in a separate file to test and compare with original.
        works fine to me as of now
*/
#include<iostream>
#include<algorithm>
#include<iterator>

template <typename T>
class Fenwick_Tree{
    private:
        int size_;
        T* tree_;
        T* inp_array_;
    public:
        // constructors
        Fenwick_Tree():size_(0), tree_(new T[1]), inp_array_(new T[1]){ tree_[0]=T(); inp_array_[0]=T(); }
        
        explicit Fenwick_Tree(int n):size_(n), tree_(new T[n+1]), inp_array_(new T[n+1]){
            for(int i=0;i<n;++i){
                tree_[i]=T();
            }
        }
        //copy constructor        
        Fenwick_Tree(const Fenwick_Tree& cop_tree){
            size_ = cop_tree.size_;
            tree_ = new T[size_+1];
            inp_array_ = new T[size_+1]; 
            for(int i=0;i <= size_; ++i){
                tree_[i] = cop_tree.tree_[i];
                inp_array_[i] = cop_tree.inp_array_[i];  
            }
        }
        // copy assignment
        Fenwick_Tree& operator=(const Fenwick_Tree& cop_tree){
            Fenwick_Tree<T> new_tree(cop_tree.size_);
            for(int i=0;i <= size_; ++i){
                tree_[i] = cop_tree.tree_[i];
                inp_array_[i] = cop_tree.inp_array_[i];  
            }
            cop_tree.~Fenwick_Tree();
            return new_tree;
        }
        template<class ForwardIterator>
        Fenwick_Tree(ForwardIterator begin, ForwardIterator end){
            size_ = std::distance(begin, end);
            tree_ = new T[size_+1];
            inp_array_ = new T[size_+1];
            for(int i=0;i<=size_;i++){
                tree_[i] = T();
            }
            make_tree(begin, end, size_);
        }
        
        template<class ForwardIterator>
        void make_tree(ForwardIterator begin, ForwardIterator end, int size){
            for(auto it = begin; it < end; ++it){
                auto val = *it;
                inp_array_[std::distance(begin, it) + 1] = val;
                for(auto i = std::distance(begin, it); i < size; i = i | (i+1) ){
                    tree_[i+1] += val;
                    //display();
                }
                //std::cout<<std::endl;
            }

        }

        ~Fenwick_Tree(){
            delete [] tree_;
            delete [] inp_array_;
        }

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

        Iterator begin() { return Iterator(&tree_[0]); }
        Iterator end()   { return Iterator(&tree_[size_+1]);}
        int size(){
            return size_;
        }
        void construct_tree();
        T point_query(int p);
	    T range_query(int r, int l);
	    void update(int i, const T delta);
        void update(int i, int j, const T delta);
        void display();

};
template <typename T>
void Fenwick_Tree<T>::construct_tree(){
    T delta;
    std::cout<<"Enter Elements\n";
    for(int i=0;i<size_;++i){
        std::cin >> delta;
        update(i,delta);
    }
}

template <typename T>
T Fenwick_Tree<T>::point_query(int p){
    T sum = T();
    ++p;
    if(p < 0 || p > size_+1)
        throw std::out_of_range("Query out of range");
    while(p > 0){
        /* std::cout<<"INSIDE POINT "<<p<<" "<<sum<<" "<<BIT[p]<<std::endl; */
        sum += tree_[p];
        p -= p & (-p);
        
    }
    return sum;
}
template <typename T>
T Fenwick_Tree<T>::range_query(int l, int r){
    return point_query(r) - point_query(l);
}
template <typename T>
void Fenwick_Tree<T>::update(int i, T delta){
    ++i;
    inp_array_[i] += delta;
    while(i <= size_){
        tree_[i] += delta;
        i += i & (-i);
    }
}
template <typename T>
void Fenwick_Tree<T>::update(int i,int j ,T delta){
    for (int k = i; k <= j;++k){
        inp_array_[k] += delta;
    }
    ++j;
    while(j <= size_){
        tree_[j] += -delta;
        j += j & (-j);
    }
    while(i <= size_){
        tree_[i] += delta;
        i += i & (-i);
    }
}


template <typename T>
void Fenwick_Tree<T>::display(){
    T results[size_+1];
    std::cout << "fenwick array internal: ";
    for(int i=0;i<=size_;i++){
        std::cout<<tree_[i]<<" ";
        results[i+1] = point_query(i);
    }
    std::cout<<"\n";
    std::cout << "Cumulative Array:       ";
    for(int i = 1; i <= size_; i++) {
        std::cout << results[i] << " ";
    }
    std::cout<<"\n";
    std::cout << "Init Array:       ";
    for(int i = 1; i <= size_; i++) {
        std::cout << inp_array_[i] << " ";
    }
    std::cout<<"\n";
}

