/// This Source Code Form is subject to the terms of the Mozilla Public
/// License, v. 2.0. If a copy of the MPL was not distributed with this
/// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @author Aart Stuurman

// Header guard
#ifndef GRPH_TEXTURE_H
#define GRPH_TEXTURE_H

/// Texture interface that contain user provided data
typedef struct
{
    /// The user provided data for this texture
    void* userData;
} Grph_Texture;

/// Construct a texture
/// @param  texture     The texture to construct
/// @param  userData    The user provided data that actually is the texture
void Grph_Texture_Construct(Grph_Texture* texture, void* userData);

/// Get the user data from a texture
/// @param  texture     The texture to get the user data from
/// @return             The user data from the texture
void* Grph_Texture_GetUserData(Grph_Texture* texture);

// End header guard
#endif GRPH_TEXTURE_H
