#ifndef _LINKEDQUEUE_H_  
#define _LINKEDQUEUE_H_  
  
#include "node.h"       // node class  
  
// implements a linked queue  
template <typename T>  
class linkedQueue  
{  
public:  
    // Constructor: creates an empty queue.  
    // Postcondition: qsize = 0, qfront = qback = NULL  
    linkedQueue();  
      
    // copy constructor. builds a copy of obj  
    linkedQueue(const linkedQueue<T>& obj);  
      
    // destructor. clear the linked list  
    ~linkedQueue();  
          
    linkedQueue<T>& operator= (const linkedQueue<T>& rhs);  
      
    // insert an element at the rear of the queue  
    // Postcondition: the queue has one more element  
    void push(const T& item);  
      
    // remove an element from the front of the queue.  
    // Precondition: the queue is not empty. if the queue  
    // is empty, throw an underflowError exception  
    // Postcondition: the queue has one less element  
    void pop();  
          
    // return a reference to the front of the queue.  
    // Precondition: the queue is not empty. if the queue  
    // is empty, throw an underflowError exception  
    T& front();  
      
    // constant version  
    const T& front() const;   
      
    // return the current size of the queue  
    int size() const;  
          
    // return true if the queue is empty; otherwise return false  
    bool empty() const;  
  
    // clear the list. used by the destructor and assignment  
    void clear();  
  
          
private:  
    // the linked list with qfront stores the elements.  
    // qback points to the rear of the queue  
    node<T> *qfront, *qback;  
      
    // number of elements in the queue  
    int qsize;  
      
    // copy q so the current list is identical to q  
    void copy(const linkedQueue<T>& q);  
          
    // allocate a node with value item and pointer value NULL  
    // and return a pointer to it. if memory allocation fails,  
    // throw the memoryAllocationError exception  
    node<T> *getNode(const T& item);    
};  
  
template <typename T>  
void linkedQueue<T>::copy(const linkedQueue<T>& q)  
{  
    // qback moves through the list we are building and  
    // winds up at the rear of our new list. p  
    // moves through the list we are copying  
    node<T> *newNode, *p = q.qfront;  
      
    // initially, the list is empty  
    qfront = qback = NULL;  
      
    // nothing to do if p is NULL  
    if (p != NULL)  
    {  
        // create the first node in the queue and assign  
        // its addres to qback  
        qfront = qback = getNode(p->nodeValue);  
          
        // move forward in the list we are copying  
        p = p->next;  
          
        // copy remaining items  
        while(p != NULL)  
        {  
            // insert new node at the back  
            newNode = getNode(p->nodeValue);  
            qback->next = newNode;  
              
            // qback is the new node  
            qback = newNode;  
              
            // move to the next node of the list we are copying  
            p = p->next;  
        }  
    }  
      
    // the size of the new list is the size of q  
    qsize = q.qsize;  
}  
  
template <typename T>  
void linkedQueue<T>::clear()  
{  
    node<T> *curr = qfront, *p;  
      
    // delete nodes until we arrive at the end of the list  
    while (curr != NULL)  
    {  
        // save curr in p and move curr forward  
        // to the next list node  
        p = curr;  
        curr = curr->next;  
          
        // delete node p  
        delete p;  
    }  
      
    // specify an emtpy list  
    qfront = qback = NULL;  
    qsize = 0;  
}  
  
template <typename T>  
node<T> *linkedQueue<T>::getNode(const T& item)  
{  
    // allocate a new node  
    node<T> *newNode = new node<T> (item);  
    if (newNode == NULL)  
    {  
        assert(newNode == NULL);  
    }  
    return newNode;  
}  
  
// create the empty list qfront = qback = NULL and qsize = 0  
template <typename T>  
linkedQueue<T>::linkedQueue(): qfront(NULL), qback(NULL), qsize(0)  
{}  
  
template <typename T>  
linkedQueue<T>::linkedQueue(const linkedQueue<T>& obj)  
{  
    // call copy() and pass the pointer to the front of  
    // the linked list in obj  
    copy(obj);  
}  
  
template <typename T>  
linkedQueue<T>::~linkedQueue()  
{  
    // call clear()  
    clear();  
}  
  
template <typename T>  
linkedQueue<T>& linkedQueue<T>::operator= (const linkedQueue<T>& rhs)  
{  
    // delete the current list  
    clear();  
      
    // make the current object a copy of rhs  
    copy(rhs);  
      
    return *this;  
}  
  
// insert item into the queue by inserting it at  
// the back of the list  
template <typename T>  
void linkedQueue<T>::push(const T& item)  
{  
    // allocate space for the new node  
    node<T> *newNode = getNode(item);  
      
    // if the queue is empty, insert the new element at the front of  
    // the list and update both qfront and qback  
    if (qfront == NULL)  
    {  
        qfront = newNode;  
        qback = newNode;  
    }  
    // in a non-empty list, insert new element at back and update qback  
    else  
    {  
        qback->next = newNode;  
        qback = newNode;  
    }  
      
    // increment the queue size  
    qsize++;  
}  
  
// remove the item at the front of the queue by erasing  
// the first element in the linked list  
template <typename T>  
void linkedQueue<T>::pop()  
{  
    // if the queue is empty, assert  
    if (qsize == 0)  
    {  
        assert(qsize == 0);  
    }  
  
    // save the location of the front of the queue  
    node<T> *p = qfront;  
      
    // move the front forward one node  
    qfront= qfront->next;  
      
    // if the queue is now empty, set qback to NULL  
    if (qfront == NULL)  
        qback = NULL;  
      
    // delete the node  
    delete p;  
      
    // decrement the queue size  
    qsize--;  
}  
  
template <typename T>  
T& linkedQueue<T>::front()  
{  
    // if the queue is empty, assert  
    if (qsize == 0)  
    {  
         assert(qsize == 0);  
    }  
    // return the value at the front  
    return qfront->nodeValue;  
}  
  
template <typename T>  
const T& linkedQueue<T>::front() const  
{  
    // if the queue is empty, assert  
    if (qsize == 0)  
    {  
        assert(qsize == 0);  
    }  
    // return the value at the front  
    return qfront->nodeValue;  
}  
  
template <typename T>  
int linkedQueue<T>::size() const  
{  
    return qsize;  
}  
  
template <typename T>  
bool linkedQueue<T>::empty() const  
{  
    return qsize == 0;  
}  
  
#endif  // _LINKEDQUEUE_H_  
