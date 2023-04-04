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


// fills array with integers ============================================================

    void fill() {
      srand(time(NULL));
      for (int i = 0; i < _size; i++) {
        _ptr_array[i] = rand() % 10;
      }
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


// removes several elements from head and returns deleted elements as array =============

    array<T> remove_h(int amount) {
      array<T> return_value(amount);
      return_value._size = amount;
      return_value._ptr_array = new T[amount];

      for (int i = 0; i < amount; i++) {
        return_value._ptr_array[i] = _ptr_array[i];
      }

      T *temp_char = new T[_size - amount];

      for (int i = 0; i < _size - amount; i++) {
        temp_char[i] = _ptr_array[i + amount];
      }

      delete[] _ptr_array;

      _ptr_array = temp_char;
      _size = _size - amount;

      return return_value;
    }


// removes several elements from tail and returns deleted elements as array =============

    array<T> remove_t(int amount) {
      array<T> return_value(amount);
      return_value._size = amount;
      return_value._ptr_array = new T[amount];

      int j = 0;
      for (int i = _size - amount; i < _size; i++, j++) {
        return_value._ptr_array[i - (_size - amount)] = _ptr_array[i];
      }

      T *temp_char = new T[_size - amount];

      for (int i = 0; i < _size - amount; i++) {
        temp_char[i] = _ptr_array[i];
      }

      delete[] _ptr_array;

      _ptr_array = temp_char;
      _size = _size - amount;

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


// concatenates two arrays ==============================================================

    array<T>& operator + (const array<T> &another) {
      T *temp_arr = new T[_size + another._size];

      for (int i = 0; i < _size; i++) {
        temp_arr[i] = _ptr_array[i];
      }

      int j = 0;
      for (int i = _size; i < _size + another._size; i++, j++) {
        temp_arr[i] = another._ptr_array[j];
      }

      _size = _size + another._size;
      _ptr_array = temp_arr;

      return *this;
    }

// remove several elements from tail ====================================================

    array<T>& operator - (int amount) {
      this->remove_t(amount);

      return *this;
    }


// bubble sort ==========================================================================

    void bubble_sort() {

      int count = _size;

      while (count--) {
        for (int i = 1; i < _size; i++) {
          if (_ptr_array[i - 1] > _ptr_array[i]) {
            std::swap(_ptr_array[i - 1], _ptr_array[i]);
          }
        }
      }
    }


// selection sort =======================================================================

    void selection_sort() {
      for (int i = 0; i < _size; i++) {
        int smallest = i;
        for (int j = i + 1; j < _size; j++) {
          if (_ptr_array[smallest] > _ptr_array[j]) {
            smallest = j;
          }

          if (smallest != i) {
            std::swap(_ptr_array[smallest], _ptr_array[i]);
          }
        }
      }
    }


// insertion sort =======================================================================

    void insertion_sort() {
      for (int i = 1; i < _size; i++) {
        int sorted = i - 1;
        while (sorted > -1 && _ptr_array[sorted] > _ptr_array[sorted + 1]) {
          std::swap(_ptr_array[sorted], _ptr_array[sorted + 1]);
          sorted--;
        }
      }
    }


// quick sort ===========================================================================

    void quick_sort() {
      q_sort(this->_ptr_array, 0, this->size() - 1);
    }

// merge sort ===========================================================================

/*    void merge_sort() {
      m_sort(this->_ptr_array, 0, this->size() - 1);
  }
*/


  private:
    int _size;
    T *_ptr_array;

    void q_sort(int *arr, int left, int right) {
      int i = left;
      int j = right;
      int pivot = arr[(i + j) / 2];

      while (i <= j) {
        while (arr[i] < pivot) {
          i++;
        }

        while (arr[j] > pivot) {
          j--;
        }

        if (i <= j) {
          std::swap(arr[i], arr[j]);
          i++;
          j--;
        }
      }

      if (j > left) {
        q_sort(arr, left, j);
      }

      if (i < right) {
        q_sort(arr, i, right);
      }
    }

/*
    void merge(int *arr, int begin, int mid, int end) {
      int sub_arr_len_1 = mid - begin + 1;
      int sub_arr_len_2 = end - mid;
      int *left_arr = new int[sub_arr_len_1];
      int *right_arr = new int[sub_arr_len_2];

      for (int i = 0; i < sub_arr_len_1; i++) {
        left_arr[i] = arr[begin + 1];
      }

      for (int i = 0; i < sub_arr_len_2; i++) {
        right_arr[i] = arr[mid + 1 + i];
      }

      int index_sarr_1 = 0;
      int index_sarr_2 = 0;
      int index_merged_arr = begin;

      while (index_sarr_1 < sub_arr_len_1 && index_sarr_2 < sub_arr_len_2) {
        if (left_arr[index_sarr_1] <= right_arr[index_sarr_2]) {
          arr[index_merged_arr] = left_arr[index_sarr_1];
          index_sarr_1++;
        } else {
          arr[index_merged_arr] = right_arr[index_sarr_2];
          index_sarr_2++;
        }
      }

      while (index_sarr_1 < sub_arr_len_1) {
        arr[index_merged_arr] = left_arr[index_sarr_1];
        index_sarr_1++;
        index_merged_arr++;
      }

      while (index_sarr_2 < sub_arr_len_2) {
        arr[index_merged_arr] = right_arr[index_sarr_2];
        index_sarr_2++;
        index_merged_arr++;
      }

      delete[] left_arr;
      delete[] right_arr;
    }

    void m_sort(int *arr, int begin, int end) {
      if (begin >= end) {
        return;
      }

      int mid = begin + (end - begin) / 2;
      m_sort(arr, begin, mid);
      m_sort(arr, mid + 1, end);
      merge(arr, begin, mid, end);
    }
*/
};

















