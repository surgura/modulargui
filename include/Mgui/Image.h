/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

#ifndef MGUI_IMAGE_H
#define MGUI_IMAGE_H

/**
    Include files
**/
#include "Gui.h"
#include "Grph/Texture.h"

typedef struct
{

} Mgui_Image;

/**
    Create a new image element.
    @param  gui             The common data for gui instances.
    @param  instance        The instance to create it for.
    @return                 The new element.
**/
Mgui_Image* Mgui_NewImage(Mgui_Gui* gui, Mgui_GuiInstance* instance);

/**
    Set the texture for an image element.
    @param  image           The image to set it for
    @param  texture         The texture to set
**/
void Mgui_Image_SetTexture(Mgui_Image* image, Grph_Texture* texture);

#endif // MGUI_IMAGE_H
