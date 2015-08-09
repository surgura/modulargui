/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

/**
    Header guard
**/
#ifndef MGUI_GUI_H
#define MGUI_GUI_H

/**
    Include files
**/
#include "Modular/Modular.h"

typedef struct
{

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
void Mgui_Destruct(Mdr_ModuleId module, Mdr_InstanceId instance);

/**
    @todo
**/
void Mgui_NewWindow(Mgui_GuiInstance* guiInstance);

#endif // MGUI_GUI_H
