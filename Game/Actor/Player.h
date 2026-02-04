#pragma once

#include "Actor/Actor.h"

using namespace Wanted;

class Player : public Actor
{
	RTTI_DECLARATIONS(Player, Actor)

public:
	Player();
	~Player();

private:
	virtual void Tick(float deltaTime) override; // 다형성원리 질문: 해당 코드는 어떤 원리로 (상위가 public이면  하위가 무엇이든 상관없음)

	//오른쪽 이동 함수.
	void MoveRight();

	//왼쪽 이동 함수.
	void MoveLeft();

	// 탄약 발사 함수.
	void Fire();

private:


};

