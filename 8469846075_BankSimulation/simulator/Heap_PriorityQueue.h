/** ADT priority queue: Heap-based implementation.
    Listing 17-3.
 @file Heap_PriorityQueue.h */

#ifndef _HEAP_PRIORITY_QUEUE
#define _HEAP_PRIORITY_QUEUE

#include "ArrayMinHeap.h"
#include "PriorityQueueInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class Heap_PriorityQueue : public PriorityQueueInterface<ItemType>,
private ArrayMinHeap<ItemType>
{
public:
   Heap_PriorityQueue();
   Heap_PriorityQueue(const int size);
   Heap_PriorityQueue(const ItemType arr[], const int size);

   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove();
   
   /** @pre The priority queue is not empty. */
   ItemType peek() const throw(PrecondViolatedExcep);
}; // end Heap_PriorityQueue

#include "Heap_PriorityQueue.cpp"
#endif
