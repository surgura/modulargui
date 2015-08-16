/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

// Include files
#include "LinkedListFunctions.h"
#include <stdlib.h>

void Mgui_LinkedList_Construct(Mgui_LinkedList* list)
{
    list->first = 0;
    list->last = 0;
}

void Mgui_LinkedList_Deconstruct(Mgui_LinkedList* list)
{
    Mgui_LinkedListNode* node = list->first;
    while(node != 0)
    {
        Mgui_LinkedListNode* toFree = node;
        node = node->next;
        free(toFree);
    }
}

Mgui_LinkedList_Result Mgui_LinkedList_PushBack(Mgui_LinkedList* list, Mgui_LinkedListNode** resultNode, Mgui_U32 dataSize)
{
    // Calculate size of node
    Mgui_U32 nodeSize = sizeof(Mgui_LinkedListNode) + dataSize;
    // Alocate memory for node
    Mgui_LinkedListNode* newNode = malloc(nodeSize);
    if(newNode == 0)
        return MGUI_LINKEDLIST_ALLOC_ERROR;

    // If there is a last node
    if(list->last != 0)
    {
        // Set previous for new node to old last node
        newNode->previous = list->last;
        // Set new node next to 0
        newNode->next = 0;

        // Set next for old last
        list->last->next = newNode;
        // Set new node as last
        list->last = newNode;
    }
    else
    {
        // Set new node as last and first
        list->first = newNode;
        list->last = newNode;
        // Set previous and next of new node to 0
        newNode->next = 0;
        newNode->previous = 0;
    }

    // Set return value
    *resultNode = newNode;

    return MGUI_LINKEDLIST_SUCCESS;
}

void Mgui_LinkedList_Remove(Mgui_LinkedList* list, Mgui_LinkedListNode* node)
{
    // If this is the first node
    if(node->previous == 0)
    {
        // Set first node to this nodes next node
        list->first = node->next;
    }
    else
    {
        // Set previous nodes next to this nodes next
        node->previous->next = node->next;
    }

    // If this is the last node
    if(node->next == 0)
    {
        // Set last node to this nodes previous node
        list->last = node->previous;
    }
    else
    {
        // Set next nodes previous to this nodes previous
        node->next->previous = node->previous;
    }

    // Free memory
    free(node);
}

Mgui_LinkedListNode* Mgui_LinkedList_First(Mgui_LinkedList* list)
{
    return list->first;
}

Mgui_LinkedListNode* Mgui_LinkedList_Next(Mgui_LinkedListNode* node)
{
    return node->next;
}

void* Mgui_LinkedList_GetData(Mgui_LinkedListNode* node)
{
    // Skip node struct to get to the data
    return (Mgui_U8*)node + sizeof(Mgui_LinkedListNode);
}
