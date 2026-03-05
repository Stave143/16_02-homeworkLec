#include <iostream>
#include "BILIST_HPP"

int main()
{  
  const size_t SIZE = 10;
  int * vec = new int(SIZE);
  for(size_t i = 0; i < SIZE; ++i) {
    vec[i] = i;
  }
  try{
    per::BiList list = convertVecToList(vec, SIZE);
  } catch (...) {
    delete[] vec;
    return 1;
  }
  for(size_t i = 0; i < SIZE; ++i) {
    std::cout << per::value(list);
    list = next(list);
  }
  delete[] vec;
  clearTo(per::begin(list), nullptr)
  return 0;
}
