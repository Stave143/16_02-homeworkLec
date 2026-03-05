#include <iostream>
#include <cstddef>

namespace permyakov {
  template < class T >
  struct BiList {
    T val;
    BiList * next;
    BiList * prev;
  };
  template < class T > T value(BiList < T > * list);  
  template < class T > void setValue(BiList < T > * list, const T v);
  template < class T > BiList < T > * next(BiList < T > * list);
  template < class T > BiList < T > * prev(BiList < T > * list);
  template < class T > void setNext(BiList < T > * list, const BiList < T > * to);
  template < class T > void setPrev(BiList < T > * list, const BiList < T > * to);
  template < class T > BiList < T > * first(BiList < T > * list);
  template < class T > BiList < T > * last(BiList < T > * list);
  template < class T > BiList < T > * addAfter(BiList < T > * list1, BiList < T > * list2);
  template < class T > BiList < T > * clearTo(BiList < T > * list, BiList < T > * end);
  template < class T > BiList < T > * convertVecToList(const T * vec, const size_t size);
}

int main()
{ 
  const size_t SIZE = 10;
  int * vec = new int[SIZE];
  for(size_t i = 0; i < SIZE; ++i) {
    vec[i] = i;
  }
  permyakov::BiList < int > * list = static_cast< permyakov::BiList < int > * > (nullptr);
  try{
    list = permyakov::convertVecToList(vec, SIZE);
  } catch (...) {
    delete[] vec;
    return 1;
  }
  try {
    for(size_t i = 0; i < SIZE; ++i) {  
      std::cout << permyakov::value(list) << '\n';

      list = permyakov::next(list);
    }
  } catch (...) {
    delete[] vec;
    permyakov::clearTo(permyakov::first(list), static_cast< permyakov::BiList < int > * > (nullptr));
    return 1;
  }
  delete[] vec;
  permyakov::clearTo(permyakov::first(list), static_cast< permyakov::BiList < int > * > (nullptr));
  return 0;
}

namespace permyakov {
  template < class T > 
  T value(BiList < T > * list)
  {
    return list -> val;
  }

  template < class T > 
  void setValue(BiList < T > * list, T v)
  {
    list -> val = v;
  }

  template < class T > 
  BiList < T > * next(BiList < T > * list)
  {
    if(!(list -> next)) {
      return first(list);
    }
    return list -> next;
  }

  template < class T > 
  BiList < T > * prev(BiList < T > * list)
  {
    if(!(list -> prev)) {
      return last(list);
    }
    return list -> prev;
  }

  template < class T > 
  void setNext(BiList < T > * list, BiList < T > * to)
  {
    list -> next = to;
  }

  template < class T > 
  void setPrev(BiList < T > * list, BiList < T > * to)
  {
    list -> prev = to;
  }

  template < class T > 
  BiList < T > * first(BiList < T > * list)
  {
    while(prev(list)) {
      list = prev(list);
    }
    return list;
  }

  template < class T > 
  BiList < T > * last(BiList < T > * list)
  {
    while(last(list)) {
      list = last(list);
    }
    return list;
  }

  template < class T > 
  BiList < T > * addAfter(BiList < T > * list1, BiList < T > * list2)
  {
    BiList < T > * temp = next(list1);
    setNext(list1, first(list2));
    setPrev(first(list2), list1);
    setNext(last(list2), temp);
    setPrev(temp, last(list2));
    return prev(temp);
  }

  template < class T > 
  BiList < T > * clearTo(BiList < T > * list, BiList < T > * end)
  {
    BiList < T > * temp = nullptr;
    if(prev(list)) {
      temp = prev(list);
    }
    while(next(list) != end) {
      list = next(list);
      delete[] prev(list);
    }
    delete[] list;
    if(temp) {
      setNext(temp, end);
    }
    if(end) {
      setPrev(end, temp);
    }
    return end;
  }

  template < class T > 
  BiList < T > * convertVecToList(const T * vec, const size_t size)
  {
    BiList < int > * list = nullptr;
    list = new BiList < int >;//конструктор по умолчанию
    BiList < int > * head = list;
    for(size_t i = 0; i < size; ++i) {
      BiList < int > * temp = list;
      setValue(list, vec[i]);
      if(i + 1 < size) {
        try {
          list = new BiList < int > {0, nullptr, temp};//конструктор присваивания
        } catch (...) {
          clearTo(head, static_cast < BiList < int > * > (nullptr));
          throw;
        }
      }
      setNext(temp, list);
    }
    return head;
  }
}
