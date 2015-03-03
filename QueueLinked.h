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

	//not sure about this case.
	if (size() == 0)
	{
		node->getNext();

		back->setNext(node);
	}

	else if (!isEmpty())
	{
		NextNode<T>* curr = back->getNext();	//get the next-> from top of list node.
		node->setNext(curr);
		back->setNext(node);	//because you have to reassign back to point to the new back..
	}

	delete curr;

    sze++;
}

template < class T >
T* QueueLinked<T>::dequeue()
{
    T* item = NULL;

    //DO THIS (dequeueing the last item is a special case)
    //also, check that there are items before dequeueing

	if (size() == 1)
	{
		dequeueAll();
	}

	else if (!isEmpty())
	{
		//this just sets the current 
		NextNode<T>* curr = getItem();
		curr->back->getNext();

		NextNode<T>* prev = NULL;
		prev 

		//now we need to actually delete curr and set pointers correctly again.



		sze--;
	}

    return item;
}

#endif
