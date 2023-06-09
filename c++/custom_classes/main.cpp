#include "types.h"

int main() {


// array class demo ==================================================================== 
  
  std::cout << "ARRAY" << std::endl;
  std::cout << "creating, print()s and size" << std::endl;
  array<int> int_arr(16);
  int_arr.fill();
  std::cout << "size: " << int_arr.size() << std::endl;
  int_arr.print();
    
  std::cout << std::endl;

  std::cout << "change" << std::endl;
  int_arr.change(0, 4);
  int_arr.change(4, 9);
  int_arr.change(5, 1);
/*  int_arr.print();

  std::cout << std::endl;

  std::cout << "insert" << std::endl;
  int_arr.insert(4, 8);
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  std::cout << std::endl;

  std::cout << "insert_f" << std::endl;
  int_arr.insert_f(5);
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  std::cout << std::endl;

  std::cout << "insert_l" << std::endl;
  int_arr.insert_l(9);
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  std::cout << std::endl;

  std::cout << "remove" << std::endl;
  std::cout << "returned value: " << int_arr.remove(3) << std::endl;
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  std::cout << std::endl;

  std::cout << "remove_f" << std::endl;
  std::cout << "returned value: " << int_arr.remove_f() << std::endl;
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  std::cout << std::endl;

  std::cout << "remove_l" << std::endl;
  std::cout << "returned value: " << int_arr.remove_l() << std::endl;
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  std::cout << std::endl;

  std::cout << "remove_h" << std::endl;
  int_arr.remove_h(3).print();
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;
  int_arr.insert_f(4);
  int_arr.insert_f(1);
  int_arr.insert_f(5);
  int_arr.insert_f(0);
  int_arr.insert_f(9);

  std::cout << std::endl;

  std::cout << "remove_t" << std::endl;
  int_arr.remove_t(1).print();
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  std::cout << std::endl;

  std::cout << "reverse" << std::endl;
  std::cout << "before: ";
  int_arr.print();
  int_arr.reverse();
  std::cout << "after: ";
  int_arr.print();

  std::cout << std::endl;

  std::cout << "index_of" << std::endl;
  int_arr.print();
  std::cout << "returned value: " << int_arr.index_of(8) << std::endl;

  std::cout << std::endl;

  std::cout << "operator +" << std::endl;
  array<int> another_int_arr(3);
  array<int> res_arr = int_arr + another_int_arr;
  res_arr.print();
  std::cout << "size: " << res_arr.size() << std::endl;

  std::cout << std::endl;

  std::cout << "operator -" << std::endl;
  std::cout << "before: ";
  int_arr.print();
  std::cout << "after: ";
  int_arr = int_arr - 2;
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  std::cout << std::endl;
*/
 
// array sorting algorithms =============================================================

  std::cout << "bubble sort" << std::endl;
  std::cout << "before: ";
  int_arr.print();
  std::cout << "after:  ";
  int_arr.bubble_sort();
  int_arr.print();

  std::cout << std::endl;

  int_arr.fill();
  std::cout << "selection sort" << std::endl;
  std::cout << "before: ";
  int_arr.print();
  std::cout << "after:  ";
  int_arr.selection_sort();
  int_arr.print();

  std::cout << std::endl;

  int_arr.fill();
  std::cout << "insertion sort" << std::endl;
  std::cout << "before: ";
  int_arr.print();
  std::cout << "after:  ";
  int_arr.insertion_sort();
  int_arr.print();

  std::cout << std::endl;

  int_arr.fill();
  std::cout << "quick sort" << std::endl;
  std::cout << "before: ";
  int_arr.print();
  std::cout << "after:  ";
  int_arr.quick_sort();
  int_arr.print();

  std::cout << std::endl;
  std::cout << std::endl;



// string class demo ===================================================================

  std::cout << "STRING" << std::endl;
  std::cout << "creating, print()s and size" << std::endl;
  string str("abcdefghijklmnopqrstuvwxyz");
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "change" << std::endl;
  str.change("Z", 2);
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "insert" << std::endl;
  str.insert("M", 3);
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "insert_f" << std::endl;
  str.insert_f("L");
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "insert_l" << std::endl;
  str.insert_l("J");
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "remove" << std::endl;
  std::cout << "returned value: " << str.remove(13) << std::endl;
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "remove_f" << std::endl;
  std::cout << "returned value: " << str.remove_f() << std::endl;
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "remove_l" << std::endl;
  std::cout << "returned value: " << str.remove_l() << std::endl;
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "remove_h" << std::endl;
  str.remove_h(5).print();
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "remove_t" << std::endl;
  str.remove_t(3).print();
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "index_of" << std::endl;
  std::cout << "returned value: " << str.index_of("e") << std::endl;
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "reverse" << std::endl;
  std::cout << "before: ";
  str.print();
  str.reverse();
  std::cout << "after: ";
  str.print();

  std::cout << std::endl;

  std::cout << "operator +" << std::endl;
  string concat_str(" sdfas");
  str = str + concat_str;
  str.print();
  std::cout << "size: " << concat_str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "operator =" << std::endl;
  string assign_str("asdf31");
  str = assign_str;
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  std::cout << std::endl;

  std::cout << "operator -" << std::endl;
  str = str - 2;
  str.print();
  std::cout << "size: " << str.length() << std::endl;

  return 0;
}