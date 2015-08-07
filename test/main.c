#include <Modular/Modular.h>
#include <Mgui/Mgui.h>

int main()
{
    Mdr_Factory factory;
    Mdr_Initialize(&factory);

    Mdr_ModuleId guiId;
    Mdr_Register(&factory, &guiId, sizeof(Mgui_Gui), sizeof(Mgui_GuiInstance), Mgui_Construct, Mgui_Destruct);

    Mdr_InstanceId instance;
    Mdr_Instantiate(&factory, &instance);

    Mdr_Destroy(&factory, instance);

    Mdr_Cleanup(&factory);

    while(1){}

    return 0;
}
