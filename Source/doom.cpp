/**
 * @file doom.cpp
 *
 * Implementation of the map of the stars quest.
 */
#include "doom.h"

#include "control.h"
#include "engine.h"
#include "engine/cel_sprite.hpp"
#include "engine/load_cel.hpp"
#include "engine/render/cel_render.hpp"
#include "utils/stdcompat/optional.hpp"

namespace devilution {
namespace {
OptionalOwnedCelSprite DoomCel;
} // namespace

bool DoomFlag;

void doom_init()
{
	DoomCel = LoadCel("Items\\Map\\MapZtown.CEL", 640);
	DoomFlag = true;
}

void doom_close()
{
	DoomFlag = false;
	DoomCel = std::nullopt;
}

void doom_draw(const Surface &out)
{
	if (!DoomFlag) {
		return;
	}

	CelDrawTo(out, GetUIRectangle().position + Displacement { 0, 352 }, CelSprite { *DoomCel }, 0);
}

} // namespace devilution
