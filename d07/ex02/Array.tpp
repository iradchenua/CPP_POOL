#include <stdexcept>
#include <iostream>

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>

class Array {
	public:
		Array<T>() : _size(0), _array(NULL) {
			
		};

		Array<T>(unsigned int size) : _size(size) {
			if (this->_size == 0) {
				this->_array = NULL;
				return ;
			}
			this->_array = new T[this->_size];
		};

		~Array<T>() {
			delete [] this->_array;
		};

		T const & operator[](unsigned int const & idx) const {
			if (idx < 0 || idx >= this->_size)
				throw std::out_of_range("index is out of range");
			return (this->_array[idx]);
		}

		T & operator[](unsigned int const & idx) {
			if (idx < 0 || idx >= this->_size)
				throw std::out_of_range("index is out of range");
			return (this->_array[idx]);
		}

		Array(Array<T> const & array) : _size(0), _array(NULL) {
			*this = array;
		}
		Array<T> const & operator=(Array<T> const & array) {
			if (this->_array)
				delete [] this->_array;

			this->_size = array.size();
			this->_array = new T[this->_size];

			for (unsigned int idx = 0; idx < this->_size; idx++) {
				(*this)[idx] = array[idx];
			}
			return (*this);
		}

		unsigned int const & size() const {
			return (this->_size);
		}
	private:
		unsigned int _size;
		T *_array;
};

#endif