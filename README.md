# fenwick-trees

An implementation of the [fenwick tree](https://en.wikipedia.org/wiki/Fenwick_tree) data-structure. It supports operations such as :-

1. Point Query
2. Range Query
3. Point Update
4. Range Update

The tree is internally indexed from 1 to n, rather than 0 to n-1.

Tree Construction takes ``` O(n)``` time where ``` n ``` is the size of the input array.
All other operations take ``` O(log(n))``` time to execute.

There are a wide range of operations available to initialize the data structure.
They are :-
- ```Fenwick_Tree()```: Default constructor with size 0
- ```Fenwick_Tree(int n)```: Single Variable constructor which needs type and size passed with the variable n. The Data-structure has the size stored and resource allocated to the tree and an array to store the input array. 
- ```Fenwick_Tree(ForwardIterator begin, ForwardIterator end)``` : Takes in type and two iterators from a different container to build the values present in the container into a fenwick tree.
- ```Fenwick_Tree(std::initializer_list<T> k)``` : Takes in initializer list to build the fenwick tree.
- ```Fenwick_Tree(const Fenwick_Tree&)```: Copy constructor.

We make use of two helper functions ```make_tree``` and ```construct_tree``` to store the values in the structure.

We have defined the meaning of the copy assignment operator for the same, while also defining the rules for `==`, `!=`, and `<<`.

We have mainly defined three functions for the operations specified before, they are:-
1. `point_query(int p)`: Sum from first position till point p
2. `range_query(int l, int r)`: Sum from l to r 
3. `update(int i, T delta)`: Update position i by adding delta.
4. `update(int i, int j, T delta)`: Add delta to all values from i to j.


We have also implemented a forward iterator to traverse and access the values stored in the fenwick tree for other purposes and to interact with stl functions.

Rules for `value_type`, `pointer`, `refernce`, etc. of the class have been defined.

Operators such as `==`, `!=`, `<`, `-`, `+` and more have rules defined for them in the iterator for iterator operatons.

The `begin()` and `end()` functions have been provided in the iterator to return the appropriate values for stl compatibility.


Generic functor support for addition, subtraction, and multiplication has been added.

--------------------------
### Instructions to run

```
mkdir build/
cd build/
cmake ..
```
To build and run the generic-1d use
```
make generic
./generic < ../in
```

To build and run the normal-1d use
```
make non-generic
./non-generic < ../in
```

To change the input, replace in with a text file.
