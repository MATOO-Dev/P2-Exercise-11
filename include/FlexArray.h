#pragma once
#include <iostream>

template<class T, unsigned int sizeFakt, unsigned int initialSize>
class FlexArray {
public:
	class FlexArrayIterator
	{
	friend class FlexArray;
	private:
		T* location;
		FlexArrayIterator(T* adress) {location = adress;};
	public:
		~FlexArrayIterator() {}

		//a)
		//dereference operator
		T operator* () { return *location;}
		//prefix-increment
		FlexArrayIterator& operator++ () {location = location + 1; return *this;}
		//postfix-increment
		FlexArrayIterator& operator++ (const int) {location = location + 1; return *(this + 1);}

		//b)
		//equality operator
		bool operator== (const FlexArrayIterator& other) {return location == other.location;}
		//non-equality operator
		bool operator!= (const FlexArrayIterator& other) {return location != other.location;}
		//member access operator
		FlexArrayIterator* operator-> () {return this;}
		//example function to test access operator
		T* getLocation() {return location;}
		//prefix-decrement
		FlexArrayIterator& operator-- () {location = location - 1; return *this;}
		//postfix-decrement
		FlexArrayIterator& operator-- (const int) {location = location - 1; return *(this - 1);}

		//c)
		T operator[](uint offset) {return *(location + offset);}
		//todo: adjust these so they dont go out of bounds (or rather use nullptr if out of bounds)
		FlexArrayIterator operator+(const uint offset) {return FlexArrayIterator(location + offset);}
		FlexArrayIterator* operator+=(const uint offset) {location = location + offset; return this;}
		FlexArrayIterator operator-(const uint offset) {return FlexArrayIterator(location - offset);}
		FlexArrayIterator* operator-=(const uint offset) {location = location - offset; return this;}

		//d)
		bool operator< (const FlexArrayIterator& other){return location < other.location;}
		bool operator<= (const FlexArrayIterator& other){return location <= other.location;}
		bool operator> (const FlexArrayIterator& other){return location > other.location;}
		bool operator>= (const FlexArrayIterator& other){return location >= other.location;}
	};

	//a)
	FlexArrayIterator begin()
	{
		return FlexArrayIterator(data);
	}

	//a)
	FlexArrayIterator end()
	{
		return FlexArrayIterator(data + size);
	}

	FlexArray(T defaultV) {
		size = initialSize;
		data = new T[size];
		defaultValue = defaultV;
		for (unsigned int i = 0; i < size; i++) {
			data[i] = defaultV;
		}
	}


	~FlexArray() {
		delete[] data;
	}

	void set(unsigned int pos, T value) {
		while (pos >= size) enlarge();
		data[pos] = value;
	}

	T get(unsigned int pos) {
		while (pos >= size) enlarge();
		return data[pos];
	}

	void print() {
		for (unsigned int i = 0; i < size; i++) {
			std::cout << data[i];
			if (i != size - 1) std::cout << ", ";
		}
		std::cout << std::endl;
	}

	void exchange(unsigned int i, unsigned int j) {
		while (i >= size || j >= size) enlarge();
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}

	uint getSize(){return size;}


private:
	void enlarge() {
		T* newData = new T[size * sizeFakt];
		for (unsigned int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		for (unsigned int i = size; i < sizeFakt * size; i++) {
			newData[i] = defaultValue;
		}
		delete[] data;
		data = newData;
		size *= sizeFakt;
	}



	T defaultValue;
	T* data;
	unsigned int size;
};

