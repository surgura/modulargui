/**
    Include files
**/
#include "Mgui/Gui.h"
#include "Mgui/Element.h"
#include "LinkedListFunctions.h"

void Mgui_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId)
{
    // get the common data
    Mgui_Gui* gui = Mdr_GetModuleCommonData(moduleId);

    // construct the elements linked list
    Mgui_LinkedList_Construct(&gui->elements);
}

void Mgui_Destruct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId)
{
    // get the common data
    Mgui_Gui* gui = Mdr_GetModuleCommonData(moduleId);

    // destruct dynamic element array
    Mgui_LinkedList_Deconstruct(&gui->elements);
}

void Mgui_Draw(Mgui_Gui* gui, Grph_RenderTarget* renderTarget)
{
    // for each element
    for (Mgui_LinkedListNode* node = Mgui_LinkedList_First(&gui->elements); node; node = Mgui_LinkedList_Next(node))
    {
        // draw it
        Mgui_Element* element = Mgui_LinkedList_GetData(node);
        element->draw(element, renderTarget);
    }
}

void Mgui_AddElement(Mgui_Gui* gui, Mgui_Element* element)
{
    Mgui_LinkedListNode* node;
    Mgui_LinkedList_PushBack(&gui->elements, &node, sizeof(Mgui_Element*)); // todo error
    *(Mgui_Element**)Mgui_LinkedList_GetData(node) = element;
}
