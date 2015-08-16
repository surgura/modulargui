#include <Modular/Modular.h>
#include <Mgui/Mgui.h>

int main()
{
    Mdr_Factory factory;
    Mdr_Initialize(&factory);

    Mdr_ModuleId guiId;
    Mdr_Register(&factory, &guiId, sizeof(Mgui_Gui), sizeof(Mgui_GuiInstance), Mgui_Construct, Mgui_Destruct);
    Mgui_Gui* gui = Mdr_GetModuleCommonData(guiId);

    Mdr_InstanceId instanceId;
    Mdr_Instantiate(&factory, &instanceId);
    Mgui_Image* image = Mgui_NewImage(gui, Mdr_GetModuleInstanceData(guiId, instanceId));

    Grph_RenderTarget renderTarget;
    while (1)
    {
        Mgui_Draw(gui, &renderTarget);
    }

    Mdr_Destroy(&factory, instanceId);

    Mdr_Cleanup(&factory);

    while(1){}

    return 0;
}
