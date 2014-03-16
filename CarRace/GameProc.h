#pragma once
#include <SFML/Graphics.hpp>
#include "BackGround.h"
#include "Player.h"

class GameProc
{
public:
	GameProc();
	void Run_GameProc();

private:
	void GameUpdate_GameProc();
	void GameRender_GameProc();
	void GameProcEvent_GameProc();
	
private:	
	BackGround backGround;
	Player player;

	sf::RenderWindow renWin;
	sf::Time timeUpdate;
};

void GameProc::Run_GameProc()
{
	sf::Clock clock;
	sf::Time time;
	 

	while ( renWin.isOpen() )
	{
	GameProcEvent_GameProc();
	time += clock.restart();
		while ( time > timeUpdate )
		{
			time -= timeUpdate;
			GameProcEvent_GameProc();
			GameUpdate_GameProc();
		}

	GameRender_GameProc();
	}
}

GameProc::GameProc()
	: renWin(sf::VideoMode(700, 600), "My Game")
{
	timeUpdate = sf::seconds( 1.f/7000.f );
}

void GameProc::GameUpdate_GameProc()
{
	player.TurnCar_Player();
	
	player.PlayerRun();
	

	if ( player.GetMoveUp() )
		backGround.BackGroundRun_BackGround( player.GetMoveDown() );
	else if ( player.GetMoveDown() )
		backGround.BackGroundRun_BackGround( player.GetMoveDown() );
	backGround.BackGroundRun_BackGround( player.GetMoveDown() );
	
}


void GameProc::GameProcEvent_GameProc()
{
	sf::Event event;
	while (renWin.pollEvent( event ))
	{
		switch( event.type )
		{
		case sf::Event::KeyPressed:
			player.PlayerWay( event.key.code, true );
			break;
		case sf::Event::KeyReleased:
			player.PlayerWay( event.key.code, false );
			break;
		case sf::Event::Closed:
			renWin.close();
			break;
		}
	}
}


void GameProc::GameRender_GameProc()
{
	renWin.clear();
	renWin.draw( backGround.GetBackGroundSprite( 1 ) );
	renWin.draw( backGround.GetBackGroundSprite( 2 ) );
	renWin.draw( player.GetPlayerSprite() );

	renWin.display();
}



	
