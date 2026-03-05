#include "BILIST_HPP"

namespace permyakov {
  template < class T > 
  T value(BiList < T > * list)
  {
    return list -> val;
  }

  template < class T > 
  BiList < T > * next(BiList < T > * list)
  {
    return list -> next;
  }

  template < class T > 
  BiList < T > * prev(BiList < T > * list)
  {
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
  void clearTo(BiList < T > * list, BiList < T > * end)
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
  }
}