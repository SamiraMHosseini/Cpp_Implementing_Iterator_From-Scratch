 # Implementing Forward Iterator From Scratch in a Custom Class in C++

# Description:

This repository contains an implementation of a fixed-size array with a custom iterator in C++. The FixedSizeArray class is a simple generic data structure that provides a fixed-size container for storing elements of any type.

The real strength of this implementation lies in its custom iterator, which adheres to the forward iterator concept. The iterator is defined as a nested struct inside the FixedSizeArray class and provides functionalities for iterating over the elements of the array.

# The iterator includes implementations of:

Pre-increment and post-increment operations: These are used to advance the iterator through the array.

Dereferencing operations (operator* and operator->): These are used to access the value currently pointed at by the iterator.

Equality and inequality comparison operations: These are used to compare two iterators to see if they point to the same location.

In addition, the FixedSizeArray class itself provides methods to get iterators pointing to the start and end of the array (the begin and end methods, respectively), to access elements at specific indexes (using the overloaded operator[]), and to get the total capacity of the array (using the size method).

The class also takes care of allocating and deallocating the memory for the array, throwing exceptions if there are any issues (such as running out of memory or trying to access an element at an invalid index).

Please feel free to browse the code, use it in your own projects, or suggest improvements!

This code is intended as a learning resource for those interested in understanding how to implement their own iterators and generic data structures in C++. Feedback and contributions are welcome.
