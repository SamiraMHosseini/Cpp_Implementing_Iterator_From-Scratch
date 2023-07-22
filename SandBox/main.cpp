#include <iostream>

template <typename T>
class FixedSizeArray
{

private:
	struct iterator
	{
		// properties of our iterator 
		using Category = std::forward_iterator_tag;
		using Distance = std::ptrdiff_t;
		// shorthand
		using Pointer = T*;
		using Reference = T&;
		using value_type = T;

		iterator()
		{
			currPtr = nullptr;
		}

		iterator(Pointer currPtr)
		{
			this->currPtr = currPtr;
		}

		// increment the iterator (pre-increment)
		iterator operator++()
		{

			++(this->currPtr);
			return *this;

		}

		// increment the iterator (post-increment)
		iterator operator++(T)
		{

			iterator temp = *this;
			++(this->currPtr);
			return temp;
		}

		// access the value the iterator is pointing to
		Pointer operator->()
		{

			if (this->currPtr == nullptr)
			{
				throw std::runtime_error("Attempt to dereference a null pointer.");
			}
			return this->currPtr;
		}

		// equality comparison
		bool operator==(const iterator& it)
		{
			return (this->currPtr == it.currPtr);
		}

		// inequality comparison
		bool operator!=(const iterator& it)
		{
			return (this->currPtr != it.currPtr);
		}

		// dereference the iterator
		Reference operator* ()
		{
			if (this->currPtr == nullptr)
			{
				throw std::runtime_error("Attempt to dereference a null pointer.");
			}
			return  *(this->currPtr);
		}
	private:
		Pointer currPtr;
	};

public:
	// constructor which attempts to allocate memory for the array
	FixedSizeArray(std::size_t capacity)
	{
		try
		{
			this->poData = new T[capacity]();
			this->capacity = capacity;
		}
		catch (const std::bad_alloc& e)
		{

			std::cout << e.what();
			this->poData = nullptr;
			this->capacity = 0;
			throw std::runtime_error("Failed to allocate memory for the array.");
		}
	}

	// get iterator to the beginning
	iterator begin()
	{
		return iterator(this->poData);
	}

	// get iterator to the end
	iterator end()
	{
		return iterator(this->poData + this->capacity);
	}

	// overloaded [] operator to provide direct access to array elements
	// throws an exception if the index is out of range
	T& operator[](std::size_t index)
	{
		if (index >= capacity)
		{
			throw std::runtime_error("Array index out of range.");
		}
		T& result = this->poData[index];
		return result;
	}

	// get the size of the array
	std::size_t size()
	{
		return this->capacity;
	}

	// destructor that deallocates memory for the array
	~FixedSizeArray()
	{
		if (this->poData != nullptr)
		{
			delete[] this->poData;
			this->poData = nullptr;
		}
	}
	// Data------------------------------------------------
private:
	T* poData;              // Pointer to array of elements - po means the pointer is ownded by the class
	std::size_t capacity;  // Total capacity of the array

};

int main()
{
	FixedSizeArray<int> array(3);
	array[0] = 10;
	array[1] = 25;
	array[2] = 43;
	for (auto it = array.begin(); it != array.end(); ++it)
	{
		std::cout << *it << '\n';
	}


}