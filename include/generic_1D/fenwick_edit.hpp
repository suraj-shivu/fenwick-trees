#include<iostream>
#include<algorithm>
#include<iterator>
#include<type_traits>

template<typename T>
struct add {
	T operator() (T x, T y) const {
		return x + y;
	}
};

template<typename T>
struct sub {
	T operator() (T x, T y) const {
		return x - y;
	}
};

template<typename T>
struct mul {
	public:
	T operator() (T x, T y) const {
		return x * y;
	}
};

template <typename T, typename T_op=add<T>>
class Fenwick_Tree{
    private:
        int size_;
        T* tree_;
        T* inp_array_;
		T_op oper_;
    public:
        // constructors
        Fenwick_Tree():size_(0), tree_(new T[1]), inp_array_(new T[1]), oper_(new T_op()){ 
			tree_[0]=T(); 
			inp_array_[0]=T();
			if (std::is_same<T_op, mul<T>>::value){
				tree_[0] = T() + 1;
			}
		}
        
        explicit Fenwick_Tree(int n):size_(n), tree_(new T[n+1]), inp_array_(new T[n+1]){
            for(int i=0;i<n;++i){
                tree_[i]=T();
            }
			if (std::is_same<T_op, mul<T>>::value){
				tree_[0] = T() + 1;
			}
        }
        //copy constructor        
        Fenwick_Tree(const Fenwick_Tree& cop_tree){
            size_ = cop_tree.size_;
            tree_ = new T[size_+1];
            inp_array_ = new T[size_+1]; 
			oper_ = cop_tree.oper_;
            for(int i=0;i <= size_; ++i){
                tree_[i] = cop_tree.tree_[i];
                inp_array_[i] = cop_tree.inp_array_[i];  
            }
        }
        // copy assignment
        Fenwick_Tree& operator=(const Fenwick_Tree& cop_tree){
            Fenwick_Tree<T> new_tree(cop_tree);
            cop_tree.~Fenwick_Tree();
            return new_tree;
        }
        Fenwick_Tree& operator=(const std::initializer_list<T> li){
            Fenwick_Tree<T> new_tree(li.begin(),li.end());
            return new_tree;
        }
        template<class ForwardIterator>
        Fenwick_Tree(ForwardIterator begin, ForwardIterator end){
            size_ = std::distance(begin, end);
            tree_ = new T[size_+1];
            inp_array_ = new T[size_+1];
			if (std::is_same<T_op, mul<T>>::value){
				for(int i=0;i<=size_;i++){
					tree_[i] = T() + 1;
				}
			} else {
				for(int i=0;i<=size_;i++){
					tree_[i] = T();
				}
			}
            make_tree(begin,end,size_);
        }

        template<class ForwardIterator>
        void make_tree(ForwardIterator begin, ForwardIterator end, int size){
            for(auto it = begin; it < end; ++it){
                auto val = *it;
                inp_array_[std::distance(begin, it) + 1] = val;
                for(auto i = std::distance(begin, it); i < size; i = i | (i+1) ){
                    tree_[i+1] = oper_(tree_[i+1], val);
                }
            }

        }
        
        Fenwick_Tree(std::initializer_list<T> k){
            size_ = k.size();
            tree_ = new T[size_+1];
            inp_array_ = new T[size_+1];
			if (std::is_same<T_op, mul<T>>::value){
				/* tree_[0] = T() + 1; */
				for(int i=0;i<=size_;i++){
					tree_[i] = T() + 1;
				}
			} else {
				for(int i=0;i<=size_;i++){
					tree_[i] = T();
				}
			}
            make_tree(k.begin(), k.end(), size_);
        }

        ~Fenwick_Tree(){
            delete [] tree_;
            delete [] inp_array_;
        }

        struct Iterator 
        {
            using iterator_category = std::forward_iterator_tag;
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
            friend bool operator< (const Iterator& a, const Iterator& b) { return a.m_ptr < b.m_ptr; };
            friend T operator- (const Iterator a, const Iterator b) { return a.m_ptr - b.m_ptr; };
            friend T operator+ (const Iterator a, const Iterator b) { return a.m_ptr + b.m_ptr; };    

            private:
            pointer m_ptr;
        };

        Iterator begin() const { return Iterator(&tree_[0]); }
        Iterator end() const  { return Iterator(&tree_[size_+1]);}
        int size() const{
            return size_;
        }
        void construct_tree();
        T point_query(int p) const;
	    T range_query(int r, int l);
	    void update(int i, const T delta);
        void update(int i, int j, const T delta);
        inline bool operator==(const Fenwick_Tree& b){
            return this->size()==b.size() && std::equal(this->begin(),this->end(),b.begin());
        }
        inline bool operator!=(const Fenwick_Tree& b){
            return !(*this==b);
        }
        T operator[](int p){
            if(p<0 || p > size_+ 1)
                throw std::out_of_range("Index out of range");
            return tree_[p];
        }
	friend std::ostream& operator<<(std::ostream& os,const Fenwick_Tree& obj)
        {
            T* results = new T[obj.size_ + 1] ;
            os << "fenwick array internal: ";
            for(int i=0;i<obj.size_;i++){
                os<<obj.tree_[i+1]<<" ";
                results[i+1] = obj.point_query(i);
            }
            os<<"\n";
            os << "Cumulative Array:       ";
            for(int i = 1; i <= obj.size_; i++) {
                os << results[i] << " ";
            }
            os<<"\n";
            os<< "Init Array:              ";
            for(int i = 1; i <= obj.size_; i++) {
                os<< obj.inp_array_[i] << " ";
            }
            os<<"\n";
            delete [] results;
            return os;
        }
        void display();

};
template <typename T, typename T_op>
void Fenwick_Tree<T, T_op>::construct_tree(){
    T delta;
    std::cout<<"Enter Elements\n";
    for(int i=0;i<size_;++i){
        std::cin >> delta;
        update(i,delta);
    }
}

template <typename T, typename T_op>
T Fenwick_Tree<T, T_op>::point_query(int p) const{
    T res = T();
	if (std::is_same<T_op, mul<T>>::value) {
		res += 1;
	}
    ++p;
    if(p < 0 || p > size_)
        throw std::out_of_range("Query out of range");
    while(p > 0){
        res = oper_(res, tree_[p]);
        p -= p & (-p);
        
    }
    return res;
}
template <typename T, typename T_op>
T Fenwick_Tree<T, T_op>::range_query(int l, int r){
	if (std::is_same<T_op, mul<T>>::value) {
		return point_query(r) / point_query(l);
	}
    return point_query(r) - point_query(l);
}
template <typename T, typename T_op>
void Fenwick_Tree<T, T_op>::update(int i, T delta){
    ++i;
    inp_array_[i] = oper_(inp_array_[i], delta);
    while(i <= size_){
        tree_[i] = oper_(tree_[i], delta);
        i += i & (-i);
    }
}
template <typename T, typename T_op>
void Fenwick_Tree<T, T_op>::update(int i,int j ,T delta){
    for (int k = i; k <= j;++k){
		inp_array_[i] = oper_(inp_array_[i], delta);
    }
    ++j;
    while(j <= size_){
		if (std::is_same<T_op, mul<T>>::value) {
			tree_[j] = oper_(tree_[j], 1/delta);
		} else {
			tree_[j] = oper_(tree_[j], -delta);
		}
        j += j & (-j);
    }
    while(i <= size_){
        tree_[i] = oper_(tree_[i], delta);
        i += i & (-i);
    }
}

template <typename T, typename T_op>
void Fenwick_Tree<T, T_op>::display(){
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

