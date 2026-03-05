#include "BILIST_HPP"

namespace permyakov {
  template < class T > 
  T value(const BiList < T > * list)
  {
    return list -> val;
  }

  template < class T > 
  void setValue(BiList < T > * list, T v)
  {
    list -> val = v;
  }

  template < class T > 
  BiList < T > * next(const BiList < T > * list)
  {
    return list -> next;
  }

  template < class T > 
  BiList < T > * prev(const BiList < T > * list)
  {
    return list -> prev;
  }

  template < class T > 
  void setNext(BiList < T > * list, const BiList < T > * to)
  {
    list -> next = to;
  }

  template < class T > 
  void setPrev(BiList < T > * list, const BiList < T > * to)
  {
    list -> prev = to;
  }

  template < class T > 
  BiList < T > * first(BiList < T > * list)
  {
    while(prev(list)) {
      list = prev(list);
    }
  }

  template < class T > 
  BiList < T > * last(BiList < T > * list)
  {
    while(last(list)) {
      list = last(list);
    }
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
    setPrev(list, temp);
    if(temp) {
      setNext(temp, list);
    }
    if(end) {
      setPrev(end, list);
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
          clearTo(head, nullptr);
          throw;
        }
      }
    }
    return head;
  }
}