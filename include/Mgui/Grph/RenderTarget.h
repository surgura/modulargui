/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

// Header guard
#ifndef GRPH_RENDER_TARGET_H
#define GRPH_RENDER_TARGET_H

// Include files
#include "Texture.h"
#include "Vector2u32.h"

/// A target that can be rendered to.
typedef struct
{
    /// The user provided data that is sent with all functions.
    void* userData;
    
    /// Draw a texture
    /// @param  userData    The user data stored in this object
    /// @param  texture     The texture to draw
    /// @param  position    The position to draw at. From the left top corner of the texture.
    void (*drawTexture) (void* userData, Grph_Texture* texture, Grph_Vector2u32* position);
} Grph_RenderTarget;

/// Construct a render target
/// @param  userData    Data that is sent with all functions
/// @param  drawTexture Function to draw a texture to the render target
///     @param  renderTarget    The render target to construct
///     @param  userData        The user data provided in this function
///     @param  texture         The texture to draw
///     @param  position        The position to draw at. From the left top corner of the texture.
Grph_RenderTarget_Construct(Grph_RenderTarget* renderTarget, void* userData, void (*drawTexture) (void* userData, Grph_Texture* texture, Grph_Vector2u32* position));

// End header guard
#endif // GRPH_RENDER_TARGET_H
