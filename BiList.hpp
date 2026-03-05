#ifndef BILIST_HPP
#define BILIST_HPP
namespace permyakov {
  template < class T >
  struct BiList {
    T val;
    BiList * next;
    BiList * prev;
  };
  template < class T > T value(BiList < T > * list);
  template < class T > BiList < T > * next(BiList < T > * list);
  template < class T > BiList < T > * prev(BiList < T > * list);
  template < class T > void setNext(BiList < T > * list, BiList < T > * to);
  template < class T > void setPrev(BiList < T > * list, BiList < T > * to);
  template < class T > BiList < T > * first(BiList < T > * list);
  template < class T > BiList < T > * last(BiList < T > * list);
  template < class T > BiList < T > * addAfter(BiList < T > * list1, BiList < T > * list2);
  template < class T > void clearToEnd(BiList < T > * list, BiList < T > * end);
}
#endif
/* 1
BiList(); конструктор
BiList(BiList); копирование
BiList(BiList&&); присваивание
~T(); деструктор
*/