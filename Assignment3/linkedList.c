#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
* Allocates the list's sentinel and sets the size to 0.
* The sentinels' next and prev should point to eachother or NULL
* as appropriate.
*/
static void init(struct LinkedList* list) {
	list->frontSentinel = malloc(sizeof(struct Link));
	assert(list->frontSentinel != 0);
	list->backSentinel = malloc(sizeof(struct Link));
	assert(list->backSentinel);
	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;
	list->size = 0;
}

/**
* Adds a new link with the given value before the given link and
* increments the list's size.
*/
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	struct Link* newlink = malloc(sizeof(struct Link));
	assert(newlink != 0);
	newlink->value = value;
	newlink->prev = link->prev;
	newlink->next = link;
	link->prev->next = newlink;
	link->prev = newlink;
	list->size++;
}

/**
* Removes the given link from the list and
* decrements the list's size.
*/
static void removeLink(struct LinkedList* list, struct Link* link)
{
	link->prev->next = link->next;
	link->next->prev = link->prev;
	free(link);
	list->size--;
}

/**
* Allocates and initializes a list.
*/
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
* Deallocates every link in the list including the sentinels,
* and frees the list itself.
*/
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
* Adds a new link with the given value to the front of the deque.
*/
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
* Adds a new link with the given value to the back of the deque.
*/
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	addLinkBefore(list, list->backSentinel, value);
}

/**
* Returns the value of the link at the front of the deque.
*/
TYPE linkedListFront(struct LinkedList* list)
{
	assert(!linkedListIsEmpty(list));
	return list->frontSentinel->next->value;
}

/**
* Returns the value of the link at the back of the deque.
*/
TYPE linkedListBack(struct LinkedList* list)
{
	assert(!linkedListIsEmpty(list));
	return list->backSentinel->prev->value;
}

/**
* Removes the link at the front of the deque.
*/
void linkedListRemoveFront(struct LinkedList* list)
{
	assert(!linkedListIsEmpty(list));
	removeLink(list, list->frontSentinel->next);
}

/**
* Removes the link at the back of the deque.
*/
void linkedListRemoveBack(struct LinkedList* list)
{
	assert(!linkedListIsEmpty(list));
	removeLink(list, list->backSentinel->prev);
}

/**
* Returns 1 if the deque is empty and 0 otherwise.
*/
int linkedListIsEmpty(struct LinkedList* list)
{
	return list->size == 0;
}

/**
* Prints the values of the links in the deque from front to back.
*/
void linkedListPrint(struct LinkedList *list)
{
	struct Link * temp;
	temp = list->frontSentinel;
	while (temp) {
		printf(" %d, ", temp->value);
		temp = temp->next;
	}
}

/**
* Adds a link with the given value to the bag.
*/
void linkedListAdd(struct LinkedList *list, TYPE value)
{
	//addLinkBefore(list, list->backSentinel, value);
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
* Returns 1 if a link with the value is in the bag and 0 otherwise.
*/
int linkedListContains(struct LinkedList* list, TYPE value)
{
	struct Link *current;
	assert(!linkedListIsEmpty(list));
	current = list->frontSentinel->next; /* Initialize current */
	while (current != list->backSentinel)
	{
		if (EQ(current->value, value))
			return 1;
		current = current->next;
	}
	return 0;
}

/**
* Removes the first occurrence of a link with the given value.
*/
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	struct Link *current;
	assert(!linkedListIsEmpty(list));
	current = list->frontSentinel->next; /* Initialize current */
	while (current != list->backSentinel)
	{
		if (EQ(current->value, value))
		{
			removeLink(list, current);
			break; /* Only remove one copy of it */
		}
		current = current->next;
	}
}
