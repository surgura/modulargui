/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

#ifndef MGUI_ELEMENT_H
#define MGUI_ELEMENT_H

#include "Grph/RenderTarget.h"

/** The base of each GUI element. **/
typedef struct
{
    /// The user data that is passed with the draw function
    void* userData;

    /// A function to draw this specific element
    /// @param  element     A pointer to the specific element.
    /// @param  userData    The user data stored in this element
    void (*draw) (void* userData, Grph_RenderTarget* renderTarget);
} Mgui_Element;

#endif // MGUI_ELEMENT_H
