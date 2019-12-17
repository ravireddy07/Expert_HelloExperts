//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Array-based implementation of the ADT heap.
 @file ArrayMinHeap.cpp */

// COMPLETED BY Samir B. Bhatt

#include <cmath>
#include "ArrayMinHeap.h"
//#include "PrecondViolatedExcep.h"

// Private Utility Methods
template<class ItemType>
int ArrayMinHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
	int index = (2 * nodeIndex) + 1;

	if (index < 0 || index > itemCount)
		return -1;

	return index;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMinHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
	int index = (2 * nodeIndex) + 2;

	if (index < 0 || index >= itemCount)
		return -1;

	return index;
}  // end getRightChildIndex

template<class ItemType>
int ArrayMinHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
	int index = (nodeIndex - 1) / 2;

	if (index < 0 || index >= itemCount)
		return -1;

	return index;
}  // end getParentIndex

template<class ItemType>
bool ArrayMinHeap<ItemType>::isLeaf(const int nodeIndex) const
{
	return (nodeIndex >= (itemCount / 2) && nodeIndex <= itemCount);
}  // end isLeaf

// Converts a semiheap rooted at index root into a heap.
template<class ItemType>
void ArrayMinHeap<ItemType>::heapRebuild(int subTreeRootIndex) {
	// Recursively trickle the item at index root down to its proper position by
	// swapping it with its larger child, if the child is larger than the item.
	// If the item is at a leaf, nothing needs to be done.
	if (!isLeaf(subTreeRootIndex)) {
		int smallerChildIndex = getLeftChildIndex(subTreeRootIndex);
		int rightChildIndex = getRightChildIndex(subTreeRootIndex);

		if (rightChildIndex != -1) {
			if (items[rightChildIndex] < items[smallerChildIndex])
				smallerChildIndex = rightChildIndex;
		}

		// If the item in the root is greater than the item in the smaller child, swap items
		if (items[subTreeRootIndex] > items[smallerChildIndex]) {
			// swap
			swap(items[subTreeRootIndex], items[smallerChildIndex]);

			heapRebuild(smallerChildIndex);
		}

	}
}  // end heapRebuild

template<class ItemType>
void ArrayMinHeap<ItemType>::heapCreate() 
{
   for (int index = itemCount / 2; index >= 0; index--)
   {
      heapRebuild(index);  
   }  // end for
}  // end heapCreate

// Constructors
template<class ItemType>
ArrayMinHeap<ItemType>::ArrayMinHeap()
{
	itemCount = 0;
	maxItems = DEFAULT_CAPACITY;

	// Allocate the array
	items = new ItemType[maxItems];

} // end constructor

template<class ItemType>
ArrayMinHeap<ItemType>::ArrayMinHeap(const int arraySize) : itemCount(0), maxItems(2 * arraySize)
{
	// Allocate the array
	items = new ItemType[2 * arraySize];

} // end constructor

template<class ItemType>
ArrayMinHeap<ItemType>::ArrayMinHeap(const ItemType someArray[], const int arraySize) : itemCount(arraySize), maxItems(2 * arraySize)
{
   // Allocate the array
   items = new ItemType[2 * arraySize];
   
   // Copy given values into the array
   for (int i = 0; i < itemCount; i++)
      items[i] = someArray[i];
   
   // Reorganize the array into a heap
   heapCreate();
} // end constructor

// Destructor
template<class ItemType>
ArrayMinHeap<ItemType>::~ArrayMinHeap()
{
	delete[] items;
	itemCount = 0;
} // end destructor

// Public Interface Methods
template<class ItemType>
bool ArrayMinHeap<ItemType>::isEmpty() const {
	return (itemCount == 0);
}

template<class ItemType>
int ArrayMinHeap<ItemType>::getNumberOfNodes() const {
	return itemCount;
}

template<class ItemType>
int ArrayMinHeap<ItemType>::getHeight() const {
	return (int)ceil(log2((double)itemCount));
}

template<class ItemType>
ItemType ArrayMinHeap<ItemType>::peekTop() const throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("Attempted peek into an empty heap.");
   
   return items[0];
} // end peekTop

template<class ItemType>
bool ArrayMinHeap<ItemType>::add(const ItemType& newData) {
	if (itemCount >= maxItems)
		return false;

	// Insert newData into the bottom of the tree
	items[itemCount] = newData;

	// Trickle new item up to the appropriate spot in the tree
	int newDataIndex = itemCount;
	bool inPlace = false;

	while ((newDataIndex > 0) && !inPlace)
	{
		int parentIndex = getParentIndex(newDataIndex);

		if (items[newDataIndex] > items[parentIndex])
			inPlace = true;
		else
		{
			swap(items[newDataIndex], items[parentIndex]);
			newDataIndex = parentIndex;
		}
	}
	itemCount++;

	return inPlace;
}

template<class ItemType>
bool ArrayMinHeap<ItemType>::remove() {
	if (isEmpty())
		return false;

	// Copy the item from the last node into the root
	items[0] = items[itemCount - 1];

	// Remove the last node
	itemCount--;

	// Transform the semiheap back into a heap
	heapRebuild(0);

	return true;
}

template<class ItemType>
void ArrayMinHeap<ItemType>::clear() {
	itemCount = 0;
}