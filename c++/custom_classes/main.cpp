#include "types.h"

int main() {

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

  std::cout << "operator +=" << std::endl;
  array<int> another_int_arr(3);
  int_arr += another_int_arr;
  int_arr.print();
  std::cout << "size: " << int_arr.size() << std::endl;

  return 0;
}