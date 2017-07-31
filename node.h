#ifndef _NODE_H_  
#define _NODE_H_  
  
#ifndef NULL  
#include <cstddef>  
#endif  // NULL  
  
// linked list node  
//template <typename T>  
struct node  
{  
public:  
  T nodeValue;      // data held by the node  
  node<T> *next;    // next node in the list  
  
  // default constructor with no initial value  
  node() : next(NULL)  
  {}  
  
  // constructor. initialize nodeValue and next  
  node(const T& item, node<T> *nextNode = NULL) :   
          nodeValue(item), next(nextNode)  
  {}  
};  
  
#endif // _NODE_H_  
