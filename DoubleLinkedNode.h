#include <iostream>
using namespace std;
template <typename E>
class DoubleLinkedNode
{
public:
  DoubleLinkedNode();
  //DoubleLinkedNode(const E& e);
  DoubleLinkedNode(const E& e, DoubleLinkedNode* _prev = NULL, DoubleLinkedNode* _next = NULL);


  ~DoubleLinkedNode();
  //ListNode *next;
  E data;
  DoubleLinkedNode *next;
  DoubleLinkedNode *prev;

};

template<typename E> DoubleLinkedNode<E>::DoubleLinkedNode()
{
  next = NULL;
  prev = NULL;
}

/*template<typename E> DoubleLinkedNode<E>::DoubleLinkedNode(const E& e)
{
  data = e;
  next = NULL;//nullptr
  prev = NULL;//nullptr
}
*/
template<typename E> DoubleLinkedNode<E>::DoubleLinkedNode(const E& e, DoubleLinkedNode* _prev, DoubleLinkedNode* _next)
{
  data = e;
  next = _next;//nullptr
  prev = _prev;//nullptr
}

template<typename E> DoubleLinkedNode<E>::~DoubleLinkedNode()
{
  //research this
  next = NULL;//nullptr
  prev = NULL;//nullptr
}
