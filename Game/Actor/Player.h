#pragma once

#include "Actor/Actor.h"
#include "Util/Timer.h"

using namespace Wanted;

class Player : public Actor
{
	// 발사 모드.
	enum class FireMode  //보통 이름 앞에 E를 붙여줌. 강사님은 안붙히심. 
	{
		None = -1,
		OneShot,
		Repeat
	};
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

	// 연속 발사 함수.
	void FireInterval();

	// 발사 가능여부 확인 함수.
	bool CanShoot() const;


private:
	// 발사 모드.
	FireMode fireMode = FireMode::None;

	// 타이머 변수.
	Timer timer;

	//// 경과 시간.
	//float elapasedTime = 0.0f;

	//// 연사 시간 간격.
	float fireInterval = 0.2f;
};