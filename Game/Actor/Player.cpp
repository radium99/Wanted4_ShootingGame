#include "Player.h"
#include "Actor/PlayerBullet.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include "Level/Level.h"


Player::Player()
	: super("<=A=>", Vector2::Zero, Color::Green)
{
	// 생성 위치 설정.
	int xPosition = (Engine::Get().GetWidth() / 2) - width/2; // 왼쪽을 기준으로 하기 때문에 객체 크기를 2로 나눈 몫만큼 뺀다.
	int yPosition = Engine::Get().GetHeight() - 2; 
	SetPosition(Vector2(xPosition, yPosition));
}

Player::~Player()
{
}

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 종료 처리.
	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		QuitGame();
	}

	//좌우 방향키 입려처리.
	if (Input::Get().GetKey(VK_LEFT))
	{
		MoveLeft();

	}
	if (Input::Get().GetKey(VK_RIGHT))
	{
		MoveRight();

	}

	// 스페이스 키를 활용해 탄약 발사
	if (Input::Get().GetKeyDown(VK_SPACE))
	{
		Fire();
	}

}

void Player::MoveRight()
{
	// 이동 처리.
	//Vector2 position = GetPosition();
	position.x += 1;

	//좌표 검사.
	// Getter Setter쓰는게 더 좋을 듯 이방법보다
	// 문자열로 플레이어를 나타낼 것이기 때문에 기준은 가장 왼쪽 <부분인다.(<-=A=-> 형태) x + width이 화면 오른쪽보다 
	if (position.x + width > Engine::Get().GetWidth())
	{

		position.x -= 1;
	}
}

void Player::MoveLeft()
{
	// 이동 처리.
	//Vector2 position = GetPosition();
	position.x -= 1;

	//좌표 검사.
	if (position.x < 0)
	{
		position.x = 0;
	}
}

void Player::Fire()
{
	// 위치 설정.
	Vector2 bulletPosition(position.x + (width / 2), position.y);


	// 액터 생성.
	GetOwner()->AddNewActor(new PlayerBullet(bulletPosition));
}
