/**
    Include files
**/
#include "Mgui/Gui.h"
#include <stdio.h>

void Mgui_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId)
{
}

void Mgui_Destruct(Mdr_ModuleId module, Mdr_InstanceId instance)
{
}

void Mgui_NewWindow(Mgui_GuiInstance* guiInstance)
{
    printf("created window");
}
