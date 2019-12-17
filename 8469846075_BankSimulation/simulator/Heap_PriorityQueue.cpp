//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Modified by Samir B. Bhatt

/** Heap-based implementation of the ADT priority queue.
    Listing 17-4.
 @file Heap_PriorityQueue.cpp */

#include "Heap_PriorityQueue.h"

template<class ItemType>
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue() : ArrayMinHeap<ItemType>() {
}  // end constructor

template<class ItemType>
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue(const int size) : ArrayMinHeap<ItemType>(size) {
}  // end constructor

template<class ItemType>
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue(const ItemType arr[], const int size) : ArrayMinHeap<ItemType>(arr, size) {
}

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::isEmpty() const
{
	return ArrayMinHeap<ItemType>::isEmpty();
}  // end isEmpty

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
	return ArrayMinHeap<ItemType>::add(newEntry);
}  // end add

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::remove()
{
	return ArrayMinHeap<ItemType>::remove();
}  // end remove

template<class ItemType>
ItemType Heap_PriorityQueue<ItemType>::peek() const throw(PrecondViolatedExcep)
{
   try
   {
	   return ArrayMinHeap<ItemType>::peekTop();
   }
   catch (PrecondViolatedExcep e)
   {
      throw PrecondViolatedExcep("Attempted peek into an empty priority queue.");
   }  // end try/catch
}  // end peek