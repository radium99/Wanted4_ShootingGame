#include "Timer.h"

// 생성자: 타이머 설정 시간 값 전달.
Timer::Timer(float targetTime)
	: targetTime(targetTime)
{
}

void Timer::Tick(float deltaTime)
{
	// 경과타임 업데이트.
	elapsedTime += deltaTime;
}

// 경과시간 리셋 함수.
void Timer::Reset()
{
	elapsedTime = 0.0f;
}

// 설정한 시간만큼 흘렀는지 확인하는 함수.
bool Timer::IsTimeOut() const
{
	return elapsedTime >= targetTime;
}

// 목표 시간 설정 함수.
void Timer::SetTargetTime(float newTargetTime)
{
	targetTime = newTargetTime;
}
