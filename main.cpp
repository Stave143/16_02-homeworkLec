#include <iostream>
#include "BiList.hpp"

int main()
{  
  const size_t SIZE = 10;
  int * vec = new int(SIZE);
  for(size_t i = 0; i < SIZE; ++i) {
    vec[i] = i;
  }
  permyakov::BiList < int > * list = nullptr;
  try{
    list = permyakov::convertVecToList(vec, SIZE);
  } catch (...) {
    delete[] vec;
    return 1;
  }
  for(size_t i = 0; i < SIZE; ++i) {
    std::cout << permyakov::value(list);
    list = permyakov::next(list);
  }
  delete[] vec;
  permyakov::clearTo(permyakov::first(list), static_cast< permyakov::BiList < int > * > (nullptr));
  return 0;
}
