#ifndef BILIST_HPP
#define BILIST_HPP
namespace permyakov {
  template < class T >
  struct BiList {
    T val;
    BiList * next;
    BiList * prev;
  };
  template < class T > T value(const BiList < T > * list);  
  template < class T > void setValue(BiList < T > * list, const T v);
  template < class T > BiList < T > * next(const BiList < T > * list);
  template < class T > BiList < T > * prev(const BiList < T > * list);
  template < class T > void setNext(BiList < T > * list, const BiList < T > * to);
  template < class T > void setPrev(BiList < T > * list, const BiList < T > * to);
  template < class T > BiList < T > * first(BiList < T > * list);
  template < class T > BiList < T > * last(BiList < T > * list);
  template < class T > BiList < T > * addAfter(BiList < T > * list1, BiList < T > * list2);
  template < class T > BiList < T > * clearToEnd(BiList < T > * list, BiList < T > * end);
  template < class T > BiList < T > * convertVecToList(const T * vec, const size_t size);
}
#endif