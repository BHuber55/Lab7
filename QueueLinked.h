#if !defined (QUEUELINKED_H)
#define QUEUELINKED_H

//write enqueue and dequeue
#include "NextNode.h"

template < class T >
class QueueLinked
{

   private:
      NextNode<T>* back;
      int sze;

   public:
      QueueLinked();
      ~QueueLinked();
      bool isEmpty();
      int size();
      void dequeueAll(); 
      T* peek();
      T* dequeue();
      void enqueue(T* item);

};

template < class T >
QueueLinked<T>::QueueLinked()
{
   back = NULL;
   sze = 0;
}

template < class T >
QueueLinked<T>::~QueueLinked()
{
   dequeueAll();
}

template < class T >
bool QueueLinked<T>::isEmpty()
{
    return sze == 0;
}

template < class T >
int QueueLinked<T>::size()
{
    return sze;
}

template < class T >
void QueueLinked<T>::dequeueAll()
{
   if (sze == 0) return;

   NextNode<T>* prev = NULL;
   NextNode<T>* curr = back->getNext();  //the head
   back->setNext(NULL);  //break the bridge link

   while (curr != NULL)
   {
      prev = curr;
      curr = curr->getNext();
      delete prev;
   }

   sze = 0;
}

template < class T >
T* QueueLinked<T>::peek()
{
    T* item = NULL;
    if (!isEmpty()) 
    {  
      // queue is not empty; retrieve front
      NextNode<T>* head = back->getNext();
      item = head->getItem();
    }
    return item;
}

template < class T >
void QueueLinked<T>::enqueue(T* item)
{
    NextNode<T>* node = new NextNode<T>(item);

	//this is for a singular linked circular list..
    //DO THIS (enqueueing the first item is a special case)

	if (back == NULL)
	{
		node->setNext(node);
		back = node;
	}
	else
	{
		node->setNext(back->getNext());
		back->setNext(node);	//because you have to reassign back to point to the new back..
		back = node;
	}
    sze++;
}

template < class T >
T* QueueLinked<T>::dequeue()
{
    T* item = NULL;

    //DO THIS (dequeueing the last item is a special case)
    //also, check that there are items before dequeueing

	NextNode<T>* curr = NULL;

	if (size() == 1)
	{
		curr = back;
		back = NULL;
		item = curr->getItem();
	}

	else if (!isEmpty())
	{
		NextNode<T>* prev = curr;
		curr = back->getNext();
		back->setNext(curr->getNext());
	}
	item = curr->getItem();
	delete curr;
	sze--;
    return item;
}

#endif
