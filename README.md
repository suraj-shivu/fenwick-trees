# fenwick-trees

An implementation of the [fenwick tree](https://en.wikipedia.org/wiki/Fenwick_tree) data-structure. It supports operations such as :-

1. Point Query
2. Range Query
3. Point Update
4. Range Update

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
