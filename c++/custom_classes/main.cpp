#include "types.h"

int main() {


 // array class demo ==================================================================== 
  std::cout << "ARRAY" << std::endl;
  std::cout << "creating, print()s and size" << std::endl;
  array<int> int_arr(6);
  std::cout << "size: " << int_arr.size() << std::endl;
  int_arr.print();
    
  std::cout << std::endl;

  std::cout << "change" << std::endl;
  int_arr.change(2, 4);
  int_arr.print();

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

  std::cout << "operator +=" << std::endl;
  array<int> another_int_arr(3);
  int_arr += another_int_arr;
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

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

  return 0;
}