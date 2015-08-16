/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

#ifndef MGUI_GUI_H
#define MGUI_GUI_H

/**
    Include files
**/
#include "Modular/Modular.h"
#include "Grph/RenderTarget.h"
#include "LinkedList.h"
#include "Element.h"

typedef struct
{
    Mgui_LinkedList elements;
} Mgui_Gui;

typedef struct
{
} Mgui_GuiInstance;

/**
    Construct function for the gui module
    @param  module          The id of this module.
    @param  instance        The id of the instance being created.
**/
void Mgui_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId);

/**
    Destruct function for the gui module
    @param  module          The id of this module.
    @param  instance        The id of the instance being destroyed.
**/
void Mgui_Destruct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId);

/**
    Draw the gui
    @param  renderTarget    The render target to draw to.
**/
void Mgui_Draw(Mgui_Gui* gui, Grph_RenderTarget* renderTarget);

/// Add an element to the root draw list
/// @param  gui     The gui to add to
/// @param  element The element to add
void Mgui_AddElement(Mgui_Gui* gui, Mgui_Element* element);

#endif // MGUI_GUI_H
