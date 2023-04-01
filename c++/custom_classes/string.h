#pragma once
#include <iostream>

class string {
  public:

// basic constructor ====================================================================

    string() {
      _ptr_text = nullptr;
      _length = 0;
    }


// basic constructor ====================================================================

    string(const char *data) {
      _length = length(data);
      _ptr_text = new char[_length + 1];

      for (int i = 0; i < _length; i++) {
        _ptr_text[i] = data[i];
      }

      _ptr_text[_length] = '\0';
    }


// copying constructor ==================================================================

    string(string &old) {
      for (int i = 0; i < _length; i++) {
        _ptr_text[i] = old._ptr_text[i];
      }
    }


// destructor ===========================================================================

    ~string() {
      delete[] _ptr_text;
    }

    int length() {
      return _length;
    }

    int length(const char *data) {
      int i = 0;

      while (*data != '\0') {
        i++;
        data++;
      }

      return i;
    }


// prints string to console =============================================================

    void print() {
      for (int i = 0; i < _length; i++) {
        std::cout << _ptr_text[i];
      }

      std::cout << std::endl;
    }


// changes character with index =========================================================

    void change(const char *data, int index) {
      _ptr_text[index] = *data;
    }


// inserts character to a string with index =============================================

    void insert(const char *data, int index) {
      _length += 1;
      char *temp_char = new char[_length];
      for (int i = 0; i < index; i++) {
        temp_char[i] = _ptr_text[i];
      }
      
      temp_char[index] = *data;

      for (int i = index; i < _length; i++) {
        temp_char[i + 1] = _ptr_text[i];
      }

      temp_char[_length] = '\0';

      delete[] _ptr_text;

      _ptr_text = temp_char;
    }


// inserts character to a string as the first element ===================================

    void insert_f(const char *data) {
      _length += 1;
      char *temp_char = new char[_length];

      temp_char[0] = *data;
      for (int i = 1; i < _length; i++) {
        temp_char[i] = _ptr_text[i - 1];
      }

      temp_char[_length] = '\0';

      delete[] _ptr_text;

      _ptr_text = temp_char;
    }


// inserts character to a string as the first element ===================================

    void insert_l(const char *data) {
      _length += 1;
      char *temp_char = new char[_length];

      for (int i = 0; i < _length; i++) {
        temp_char[i] = _ptr_text[i];
      }

      temp_char[_length - 1] = *data;
      temp_char[_length] = '\0';

      delete[] _ptr_text;

      _ptr_text = temp_char;
    }


// removes character from string with index =============================================

    char remove(int index) {
      char return_value = _ptr_text[index];
      char *temp_char = new char[_length - 1];
      
      for (int i = 0; i < index; i++) {
        temp_char[i] = _ptr_text[i];
      }

      for (int i = index + 1; i < _length; i++) {
        temp_char[i - 1] = _ptr_text[i];
      }

      delete[] _ptr_text;

      _ptr_text = temp_char;
      _length -= 1;

      return return_value;
    }


// removes the first character from string ==============================================
    char remove_f() {
      char return_value = _ptr_text[0];
      char *temp_char = new char[_length - 1];

      for (int i = 0; i < _length; i++) {
        temp_char[i] = _ptr_text[i + 1];
      }

      delete[] _ptr_text;

      _length -= 1;
      _ptr_text = temp_char;

      return return_value;
    }


// removes the last character from string ===============================================

    char remove_l() {
      char return_value = _ptr_text[_length - 1];  
      char *temp_char = new char[_length - 1];

      for (int i = 0; i < _length - 1; i++) {
        temp_char[i] = _ptr_text[i];
      }

      delete[] _ptr_text;

      _length -= 1;
      _ptr_text = temp_char;

      return return_value;
    }


// removes several elements from head and returns deleted elements as string ============

    string remove_h(int amount) {
      string return_value;
      return_value._length = amount;
      return_value._ptr_text = new char[amount + 1];
      return_value._ptr_text[amount] = '\0';

      for (int i = 0; i < amount; i++) {
        return_value._ptr_text[i] = _ptr_text[i];
      }

      char *temp_char = new char[_length - amount + 1];

      for (int i = 0; i < _length - amount; i++) {
        temp_char[i] = _ptr_text[i + amount];
      }

      temp_char[_length - amount] = '\0';

      delete[] _ptr_text;

      _ptr_text = temp_char;
      _length = _length - amount;

      return return_value;
    }


// removes several elements from tail and returns deleted elements as string ============

    string remove_t(int amount) {
      string return_value;
      return_value._length = amount;
      return_value._ptr_text = new char[amount + 1];
      return_value._ptr_text[amount] = '\0';

      int j = 0;
      for (int i = _length - amount; i < _length; i++, j++) {
        return_value._ptr_text[i - (_length - amount)] = _ptr_text[i];
      }

      char *temp_char = new char[_length - amount + 1];

      for (int i = 0; i < _length - amount; i++) {
        temp_char[i] = _ptr_text[i];
      }

      temp_char[_length - amount] = '\0';

      delete[] _ptr_text;

      _ptr_text = temp_char;
      _length = _length - amount;

      return return_value;
    }


// returns index of the first element that equals to data from argument =================

    int index_of(const char *data) {
      int i = 0;
      for (; i < _length; i++) {
        if (_ptr_text[i] == *data) {
          break;
        }
      }
      return i;
    }


// reverses the string ==================================================================

    void reverse() {
      char *temp_char = new char[_length];

      int j = _length - 1;
      for (int i = 0; i < _length; i++, j--) {
        temp_char[i] = _ptr_text[j];
      }

      delete[] _ptr_text;

      _ptr_text = temp_char;
    }


// concatenates two strings =============================================================

    string& operator + (const string &another) {
      char *temp_char = new char[_length + another._length + 1];

      for (int i = 0; i < _length; i++) {
        temp_char[i] = _ptr_text[i];
      }

      int j = 0;
      for (int i = _length; i < _length + another._length; i++, j++) {
        temp_char[i] = another._ptr_text[j];
      }

      _length = _length + another._length;
      _ptr_text = temp_char;
      _ptr_text[_length] = '\0';

      return *this;
    }


// assigns one string to another ========================================================

    string& operator = (const string &another) {
      char *temp_char = new char[another._length + 1];

      for (int i = 0; i < another._length; i++) {
        temp_char[i] = another._ptr_text[i];
      }

      delete[] _ptr_text;

      _ptr_text = temp_char;
      _length = another._length;
      _ptr_text[_length] = '\0';

      return *this;
    }


// assigns one string to another ========================================================

    string& operator - (int amount) {
      this->remove_t(amount);

      return *this;
    }


  private:
    int _length;
    char *_ptr_text;
};