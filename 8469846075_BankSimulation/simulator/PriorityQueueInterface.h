//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file PriorityQueueInterface.h */

#ifndef _PRIORITY_QUEUE_INTERFACE
#define _PRIORITY_QUEUE_INTERFACE

template<class ItemType>
class PriorityQueueInterface

{
public:
   /** Sees whether this priority queue is empty.
    @return  True if the priority queue is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to this priority queue.
    @post  If the operation was successful, newEntry is in the
       priority queue.
    @param newEntry  The object to be added as a new entry.
    @return  True if the addition is successful or false if not. */
   virtual bool add(const ItemType& newEntry) = 0;
   
   /** Removes from this priority queue the entry having the 
       highest priority.
    @post  If the operation was successful, the highest priority 
       entry has been removed.
    @return  True if the removal is successful or false if not. */
   virtual bool remove() = 0;
   
   /** Returns the highest-priority entry in this priority queue.
    @pre  The priority queue is not empty.
    @post  The highest-priority entry has been returned, and the
       priority queue is unchanged.
    @return  The highest-priority entry. */
   virtual ItemType peek() const = 0;
}; // end PriorityQueueInterface
#endif
