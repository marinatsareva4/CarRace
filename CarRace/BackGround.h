#pragma once
#include <iostream>
#include "GameProc.h"

using namespace std;

class BackGround
{
public:
	BackGround();
	sf::Sprite GetBackGroundSprite( int num );
	void BackGroundRun_BackGround( bool moveDown );
	

private:
	void Run_BackGround();

private:
	sf::Sprite backGroundSpriteOne;
	sf::Sprite backGroundSpriteTwo;
	sf::Texture textures;
	float speed;
	sf::Time time;
	
};

BackGround::BackGround()
{
	if (!textures.loadFromFile("../CarRace/Road.png"))
		cout<<"Bad";
	backGroundSpriteOne.setTexture( textures );
	backGroundSpriteTwo.setTexture( textures );
	backGroundSpriteOne.setPosition(0.f,0.f);
	backGroundSpriteTwo.setPosition(0.f,-595.f);
	time = sf::seconds( 1.f/660.f );
	speed = 80;
}

sf::Sprite BackGround::GetBackGroundSprite( int num )
{
	if ( num == 1 )
		return backGroundSpriteOne;
	else if ( num == 2 )
		return backGroundSpriteTwo;
	else return backGroundSpriteOne;
}

void BackGround::BackGroundRun_BackGround( bool moveDown )
{
	sf::Vector2f movement( 0.f, 0.f );
	float koef = 1.f;
	if ( moveDown ) 
		koef = 3.f;
	
	movement.y += speed;

	backGroundSpriteOne.move( movement * time.asSeconds() / koef  );
	backGroundSpriteTwo.move( movement * time.asSeconds() / koef  );

	if ( backGroundSpriteOne.getPosition().y >= 595 )
		backGroundSpriteOne.setPosition( 0.f, -595.f );
	if ( backGroundSpriteTwo.getPosition().y >= 595 )
		backGroundSpriteTwo.setPosition( 0.f, -595.f );
}