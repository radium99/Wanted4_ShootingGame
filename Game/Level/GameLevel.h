#pragma once

#include "Level/Level.h"

using namespace Wanted;


class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level) //rtti라고 작성하고 ctrl + 스페이스로 자동완성

public:
	GameLevel();
	~GameLevel();

private:
	
};


