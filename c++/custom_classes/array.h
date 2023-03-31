#pragma once
#include <iostream>

template <typename T>
class array {
  public:

// declaration constructor ==============================================================
    array() {
      _ptr_array = nullptr;
      _size = 0;
    }


// basic constructor ====================================================================
    array(int size = 0) {
      _ptr_array = new T[size];
      _size = size;
    }


// copying constructor ==================================================================
    array(array &old) {
      this->_ptr_array = new T[old._size];
      this->_size = old._size;

      for (int i = 0; i < old._size; i++) {
        this->_ptr_array[i] = old._ptr_array[i];
      }
    }


// destructor ===========================================================================
    ~array() {
      delete[] _ptr_array;
    }


// returns array`s size =================================================================
    int size() {
      return _size;
    }


// prints array elements to console =====================================================
    void print() {
      for (int i = 0; i < _size; i++) {
        std::cout << _ptr_array[i] << " ";
      }
      
      std::cout << std::endl;
    }


// change element`s data with index =====================================================

    void change(int index, const T &data) {
      _ptr_array[index] = data;
    }


// inserts new element to array as the first element ====================================

    void insert(int index, const T &data) {
      T *temp_arr = new T[_size];

      for (int i = 0; i < index; i++) {
        temp_arr[i] = _ptr_array[i];
      }

      temp_arr[index] = data;

      for (int i = index + 1; i < _size; i++) {
        temp_arr[i] = _ptr_array[i - 1];
      }

      delete[] _ptr_array;

      _size += 1;
      _ptr_array = temp_arr;
    }


// inserts new element to array as the first element ====================================

    void insert_f(const T &data) {
      T *temp_arr = new T[_size];

      temp_arr[0] = data;
      for (int i = 0; i < _size; i++) {
        temp_arr[i + 1] = _ptr_array[i];
      }
      delete[] _ptr_array;

      _size += 1;
      _ptr_array = temp_arr;
    }


// inserts new element to array as the last element =====================================

    void insert_l(const T &data) {
      T *temp_arr = new T[_size];

      temp_arr[_size] = data;
      for (int i = 0; i < _size; i++) {
        temp_arr[i] = _ptr_array[i];
      }
      delete[] _ptr_array;

      _size += 1;
      _ptr_array = temp_arr;
    }


// removes element from array with index ================================================

    T remove(int index) {
      T return_value = _ptr_array[index];  
      T *temp_arr = new T[_size - 1];

      for (int i = 0; i < index; i++) {
        temp_arr[i] = _ptr_array[i];
      }

      for (int i = index + 1; i < _size; i++) {
        temp_arr[i - 1] = _ptr_array[i];
      }

      delete[] _ptr_array;

      _size -= 1;
      _ptr_array = temp_arr;

      return return_value;
    }

// removes the first element of array ===================================================

    T remove_f() {
      T return_value = _ptr_array[0];  
      T *temp_arr = new T[_size - 1];

      for (int i = 0; i < _size; i++) {
        temp_arr[i] = _ptr_array[i + 1];
      }

      delete[] _ptr_array;

      _size -= 1;
      _ptr_array = temp_arr;

      return return_value;
    }


// removes the first element of array ===================================================

    T remove_l() {
      T return_value = _ptr_array[_size - 1];  
      T *temp_arr = new T[_size - 1];

      for (int i = 0; i < _size - 1; i++) {
        temp_arr[i] = _ptr_array[i];
      }

      delete[] _ptr_array;

      _size -= 1;
      _ptr_array = temp_arr;

      return return_value;
    }


// reverses array =======================================================================

    void reverse() {
      T *temp_arr = new T[_size];

      int j = _size - 1;
      for (int i = 0; i < _size; i++, j--) {
        temp_arr[i] = _ptr_array[j];
      }

      delete[] _ptr_array;

      _ptr_array = temp_arr;
    }

// returns index of the first element, that equals data =================================

    int index_of(const T &data) {
      int i = 0;
      for (; i < _size; i++) {
        if (_ptr_array[i] == data) {
          break;
        }
      }
      return i;
    }



// concatenate two arrays ===============================================================

    array<T>& operator += (const array<T> &another) {
      T *temp_arr = new T[this->_size + another._size];

      for (int i = 0; i < this->_size; i++) {
        temp_arr[i] = this->_ptr_array[i];
      }

      int j = 0;
      for (int i = this->_size; i < this->_size + another._size; i++, j++) {
        temp_arr[i] = another._ptr_array[j];
      }

      this->_size = this->_size + another._size;
      this->_ptr_array = temp_arr;

      return *this;
    }


  private:
    int _size;
    T *_ptr_array;
};

















