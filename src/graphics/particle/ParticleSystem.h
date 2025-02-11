/*
 * Copyright 2011-2020 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */
/* Based on:
===========================================================================
ARX FATALIS GPL Source Code
Copyright (C) 1999-2010 Arkane Studios SA, a ZeniMax Media company.

This file is part of the Arx Fatalis GPL Source Code ('Arx Fatalis Source Code'). 

Arx Fatalis Source Code is free software: you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Arx Fatalis Source Code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Arx Fatalis Source Code.  If not, see 
<http://www.gnu.org/licenses/>.

In addition, the Arx Fatalis Source Code is also subject to certain additional terms. You should have received a copy of these 
additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Arx 
Fatalis Source Code. If not, please request a copy in writing from Arkane Studios at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing Arkane Studios, c/o 
ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/

#ifndef ARX_GRAPHICS_PARTICLE_PARTICLESYSTEM_H
#define ARX_GRAPHICS_PARTICLE_PARTICLESYSTEM_H

#include <array>
#include <string_view>
#include <vector>

#include "core/TimeTypes.h"
#include "graphics/BaseGraphicsTypes.h"
#include "graphics/Renderer.h"
#include "graphics/Draw.h"
#include "graphics/particle/Particle.h"
#include "graphics/particle/ParticleParams.h"
#include "math/Types.h"
#include "math/Vector.h"
#include "math/Quantizer.h"
#include "util/Flags.h"


class ParticleParams;
class TextureContainer;

class ParticleSystem {
	
public:
	
	std::vector<Particle> m_particles;
	
	// these are used for the particles it creates
	ParticleParams m_parameters;
	
	ParticleSystem();
	
	void SetParams(const ParticleParams & params);
	
	void SetPos(const Vec3f & pos);
	
	void Render();
	
	void StopEmission();
	bool IsAlive() const;
	
	void Update(GameDuration delta);
	
private:
	
	Vec3f m_nextPosition;
	int iParticleNbAlive;
	
	std::array<TextureContainer *, 20> tex_tab;
	int iNbTex;
	GameDuration iTexTime;
	
	glm::mat4x4 eMat;
	
	math::Quantizer m_storedTime;
	
	void SetParticleParams(Particle * particle);
	
	void SetTexture(std::string_view name, int count, GameDuration delay);
	
};

#endif // ARX_GRAPHICS_PARTICLE_PARTICLESYSTEM_H
