#pragma once
#include "GameProc.h"


class Player
{
public:
	Player();
	sf::Sprite GetPlayerSprite();
	void PlayerWay( sf::Keyboard::Key key, bool PressedKey );
	void PlayerRun();
	bool GetMoveUp();
	bool GetMoveDown();
	void TurnCar_Player();


private:


private:
	sf::Texture texture;
	sf::Texture turnLeftTexture;
	sf::Texture turnRightTexture;
	sf::Sprite playerSprite;
	bool moveUp, moveLeft, moveDown, moveRight;
	float speed;
	float HP;
	sf::Time time;
};


Player::Player()
{
	texture.loadFromFile("../CarRace/PlayerCar.png");
	turnLeftTexture.loadFromFile("../CarRace/PlayerCarLeft.png");
	turnRightTexture.loadFromFile("../CarRace/PlayerCarRight.png");
	playerSprite.setTexture( texture );
	playerSprite.setPosition( 300.f, 450.f );
	speed = 200;
	HP = 10000;
	moveUp = moveLeft = moveDown = moveRight = false;
	time = sf::seconds( 1.f/7000.f);
}

sf::Sprite Player::GetPlayerSprite()
{
	return playerSprite;
}

void Player::PlayerWay( sf::Keyboard::Key key, bool PressedKey )
{
	if (key == sf::Keyboard::W)
		moveUp = PressedKey;
	else if (key == sf::Keyboard::A)
		moveLeft = PressedKey;
	else if (key == sf::Keyboard::S)
		moveDown = PressedKey;
	else if (key == sf::Keyboard::D)
		moveRight = PressedKey;
}

void Player::PlayerRun()
{
	sf::Vector2f movement( 0.f, 0.f );

	if ( moveUp )
		movement.y -= speed;
	if ( moveLeft )
		movement.x -= speed * 1.7;
	if ( moveDown )
		movement.y += speed;
	if ( moveRight )
		movement.x += speed * 1.7;

	playerSprite.move ( movement * time.asSeconds() );
}


bool Player::GetMoveUp()
{
	return moveUp;
}

void Player::TurnCar_Player()
{
	if ( moveLeft )
		playerSprite.setTexture( turnLeftTexture );
	else if ( moveRight )
		playerSprite.setTexture( turnRightTexture );
	else 
		playerSprite.setTexture( texture );
}

bool Player::GetMoveDown()
{
	return moveDown;
}