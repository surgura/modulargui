/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

// Header guard
#ifndef MGUI_LINKED_LIST_H
#define MGUI_LINKED_LIST_H

// Include files
#include "Types.h"

/// A node in the linked list.
typedef struct Mgui_LinkedListNode
{
    /// The previous node in the list. Null if this is the first node.
    struct Mgui_LinkedListNode* previous;

    /// The next node in the list. Null if this is the last node.
    struct Mgui_LinkedListNode* next;
} Mgui_LinkedListNode;

/// A doubly linked list with arbitrary size for each node.
typedef struct
{
    /// The first node in the list
    Mgui_LinkedListNode* first;

    /// The last node in the list
    Mgui_LinkedListNode* last;
} Mgui_LinkedList;

// End header guard
#endif // MGUI_LINKED_LIST_H
