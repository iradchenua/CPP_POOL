#include "Hero.class.hpp"
#include "Terrorist.class.hpp"
#include "Space.class.hpp"
#include <ncurses.h>
#include <iostream>

#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

class Game {
	public:
		Game(void);
		Game(Game const & Game);

		~Game(void);
		Game & operator=(Game const & Game);

		void	game(void);

		int 	getWidth(void) const;
		int 	getHeight(void) const;

		void	showFinalScore() const;
		void	showGameScore() const;

		void 			setUpScore(int diff);

	private:
		void	_checkBorderCollision(AGameEntity & entity);
		void	_checkCollision();
		
		void	_entityMove(AGameEntity & entity);
		void 	_drawEntity(AGameEntity const & entity) const;
		void	_drawBorder(void) const;
		void	 _HeroMove(Hero & Hero);
		void	_frame(Hero & Hero);
		void	_initColorPairs();
		
		void	_createRandomEnemies(void);
		void	_setRandomEntityPosition(AGameEntity & entity);
		void	_setRandomEntitySpeed(AGameEntity & entity);

		void	_setRandomSpacePosition(Space & space);
		void	_createRandomSpace(void);


		void			_moveEntities(AGameEntity *entities, int count);
		void			_drawEntities(AGameEntity *entities, int count);

		void			_createBlust(Hero & Hero);

		int 			_w;
		int 			_h;
		int 			_maxBlustCount;
		int 			_TerroristCount;

		char			_TerroristModel;
		char			_borderTopDownModel;
		char			_borderLeftRightModel;

		unsigned int	_score;
		Terrorist 			*_enemies;
		Blust			*_Blusts;
		Space			*_space;
};

#endif

