/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

// Header guard
#ifndef MGUI_LINKED_LIST_FUNCTIONS_H
#define MGUI_LINKED_LIST_FUNCTIONS_H

// Include files
#include "Mgui/LinkedList.h"

/// Codes for the results of the linked list functions.
typedef enum
{
    /// Everything went as expected.
    MGUI_LINKEDLIST_SUCCESS,

    /// Allocing memory was needed but it failed.
    /// No data was changed.
    MGUI_LINKEDLIST_ALLOC_ERROR
} Mgui_LinkedList_Result;

/// Initialize a linked list.
/// @param  list    The list to initialize.
void Mgui_LinkedList_Construct(Mgui_LinkedList* list);

/// Cleanup a linked list. Frees all memory.
/// Linked list structure is free to use as if it where never used.
/// @param  list    The list to clean up.
void Mgui_LinkedList_Deconstruct(Mgui_LinkedList* list);

/// Add a new node with an arbitrary size at the back of the list.
/// @param  list            The list to add to.
/// @param  resultNode      The variable to store the result pointer to the node in.
/// @param  dataSize        The size of data to be contained in the node.
/// @return                 How executing the function went.
///         MGUI_SUCCESS     Everything went as expected.
///         MGUI_ALLOC_ERROR Allocing memory was needed but it failed.
///                         No data was changed.
Mgui_LinkedList_Result Mgui_LinkedList_PushBack(Mgui_LinkedList* list, Mgui_LinkedListNode** resultNode, Mgui_U32 dataSize);

/// Remove a node from the list.
/// @param  list        The list to remove from.
/// @param  node        The node to remove.
void Mgui_LinkedList_Remove(Mgui_LinkedList* list, Mgui_LinkedListNode* node);

/// Get the first node from a linked list
/// @param  list    The list to get the first node from
/// @return         The first node of the list
Mgui_LinkedListNode* Mgui_LinkedList_First(Mgui_LinkedList* list);

/// Get the next node in the list.
/// Returns null pointer if this was the last node in the list.
/// @param  node        The node to get the next sibling from.
/// @return             The next node, or null pointer,
///                     if the provided node was the last one in the list.
Mgui_LinkedListNode* Mgui_LinkedList_Next(Mgui_LinkedListNode* node);

/// Get the data from a node.
/// @param  node        The node to get the data from.
void* Mgui_LinkedList_GetData(Mgui_LinkedListNode* node);

// End header guard
#endif // MGUI_LINKED_LIST_FUNCTIONS_H
