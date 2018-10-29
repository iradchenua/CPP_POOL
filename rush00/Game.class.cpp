#include "Game.class.hpp"
#include <unistd.h>
#define ESC 27
#define BORDER 3

void	initColorPair(int pairId, int color) {
	init_pair(pairId, color, COLOR_BLACK);
}

void	ncursesStaffInit(void) {
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();	
}

Game::Game(void) {
	int term_h;
	int term_w;

	ncursesStaffInit();
	getmaxyx(stdscr, term_h, term_w);
	_h = term_h - 2;
	_w = term_w - 1;

	_score = 0;
	_TerroristCount = term_w / 2;
	_maxBlustCount = 20;

	_Blusts = new Blust[_maxBlustCount];

	std::srand(std::time(0));
	_createRandomEnemies();
	_createRandomSpace();

	_TerroristModel = _enemies[0].getEntityModel();
	_borderTopDownModel = '-';
	_borderLeftRightModel = '|';
}

void	Game::_drawBorder(void) const{
	attron(COLOR_PAIR(BORDER));

    for (int h = 0; h < _h; h++){
    	mvaddch(h, 0, _borderLeftRightModel);
		mvaddch(h, _w, _borderLeftRightModel);
    }

    for (int w = 0; w <= _w; w++){
        mvaddch(0, w, _borderTopDownModel);
        mvaddch(_h, w, _borderTopDownModel);
    }
    mvaddch(0, _w, '+');
    mvaddch(_h, _w, '+');
    mvaddch(_h, 0, '+');
    mvaddch(0, 0, '+');
}
 

Game::Game(Game const & Game) {
	ncursesStaffInit();
	*this = Game;
}

void Game::_drawEntity(AGameEntity const & entity) const {
	move(entity.getY(), entity.getX());
	attron(COLOR_PAIR(entity.getEntityColorPairId()));
	addch(entity.getEntityModel());
}

void	Game::_HeroMove(Hero & Hero) {
	char  symbol;
	float prevX;
	float prevY;

	prevX = Hero.getX();
	prevY = Hero.getY();

	Hero.move();
	symbol = mvinch(Hero.getY(), Hero.getX()) & A_CHARTEXT;
	if (symbol == _TerroristModel) {
		system("afplay ./resources/explosion.mp3 &");
		Hero.kill();
	}
	if (symbol == '|')
		Hero.setX(prevX);
	if (symbol == '-')
		Hero.setY(prevY);
	move(Hero.getY(), Hero.getX());
}

void	Game::_checkBorderCollision(AGameEntity & entity) {
	char symbol = mvinch(entity.getY(), entity.getX()) & A_CHARTEXT;

	if (symbol == '-') {
		if (entity.getEntityModel() != '.')
			entity.kill();
		else
			entity.setY(1);
	}

}

void	Game::_entityMove(AGameEntity & entity) {
	entity.move();
	_checkBorderCollision(entity);
	if (entity.getIsAlive())
		move(entity.getY(), entity.getX());
}

void	Game::_createBlust(Hero & Hero) {

	for (int bi = 0; bi < _maxBlustCount; bi++)  {

		if (Hero.getShoot() && !_Blusts[bi].getIsAlive())
		{
			system("afplay ./resources/laser.wav &");
			_Blusts[bi].setY(Hero.getY());
			_Blusts[bi].setX(Hero.getX());
			_Blusts[bi].live();
			break ;
		}
	}
}

void	Game::_drawEntities(AGameEntity *entites, int count) {
	for (int i = 0; i < count; i++)
	{
		if (entites[i].getIsAlive())
			Game::_drawEntity(entites[i]);
	}
}

void	Game::_initColorPairs() {
	for (int i = 0; i < 7; i++) {
		initColorPair(i, i);
	}
}

void	Game::_setRandomEntityPosition(AGameEntity & entity) {
	
	entity.setX((std::rand()) % (_w - 1)+ 1);
	entity.setY(std::rand() % 4 + 1);
}

void	Game::_setRandomEntitySpeed(AGameEntity & entity) {
	entity.setSpeed((std::rand() % 10) * 0.0001 + 0.0001);
}

void	Game::_createRandomEnemies(void) {
	_enemies = new Terrorist[_TerroristCount];

	for (int i = 0; i < _TerroristCount; i++) {
		_setRandomEntityPosition(_enemies[i]);
		_setRandomEntitySpeed(_enemies[i]);
	}
}

void	Game::_moveEntities(AGameEntity *entites, int count) {
	for (int i = 0; i < count; i++) {
		if (entites[i].getIsAlive())
			_entityMove(entites[i]);
		else if (entites[i].getEntityModel() == _TerroristModel) {
			if ((std::rand() % 2)) {
				entites[i].live();
				_setRandomEntityPosition(entites[i]);
			}
		}
	}
}

void	Game::_checkCollision() {
	int bX;
	int bY;
	int eX;
	int eY;

	for (int bi = 0; bi < _maxBlustCount; bi++) {
		 if (_Blusts[bi].getIsAlive()) {
	 		bX = _Blusts[bi].getX();
	 		bY = _Blusts[bi].getY();
		 	for (int ei = 0; ei < _TerroristCount; ei++) {
		 		eX = _enemies[ei].getX();
		 		eY = _enemies[ei].getY();
		 		if (_enemies[ei].getIsAlive() && bX == eX) {

		 			if (bY == eY)
		 			{
		 				_Blusts[bi].kill();
		 				_enemies[ei].kill();
		 				system("afplay ./resources/explosion.mp3 &");
						setUpScore(20);
		 			}
		 		}
		 	}
		 }
	}
}

void	Game::_frame(Hero & Hero) {


	_drawBorder();
	_moveEntities(_space, _TerroristCount);
	_drawEntities(_space, _TerroristCount);	

	Game::showGameScore();
	_createBlust(Hero);

	_moveEntities(_Blusts, _maxBlustCount);
	_moveEntities(_enemies, _TerroristCount);
	_checkCollision();

	_drawEntities(_Blusts, _maxBlustCount);
	_drawEntities(_enemies, _TerroristCount);
	
	
	_HeroMove(Hero);
	Game::_drawEntity(Hero);
	
}

void 	Game::game() {
	system("afplay resources/Kept.mp3 &");
	Hero	Hero(_w / 2, _h - 1);
	int key;
	clock_t begin_time = clock();

	key = 0;
	Game::_initColorPairs();
	while (Hero.getIsAlive()) {
		while ((key = getch()) != ERR)
		{
			if (key == ESC)
				return ;
			Hero.checkKey(key);
		}
		erase();
		_frame(Hero);
		if (float( clock () - begin_time ) /  CLOCKS_PER_SEC > 0.5)
		{
			begin_time = clock();
			setUpScore(1);
		}
		usleep(10);
		Hero.releaseKeys();
	}
	system("afplay ./resources/explosion.mp3 &");
	usleep(550000);
}

Game & Game::operator=(Game const & Game) {
	_w = Game.getWidth();
	_h = Game.getHeight();
	return (*this);
}

Game::~Game(void) {
	endwin();
	delete [] _enemies;
	delete [] _Blusts;
	delete [] _space;

	system("killall afplay");
	showFinalScore();
}

int Game::getWidth(void) const {
	return (_w);
}

int Game::getHeight(void) const {
	return (_h);
}

void Game::setUpScore(int diff)
{
	_score += diff;
}

void Game::showFinalScore() const
{
	std::cout << "Your final score is: " \
	<< _score << std::endl;
}

void Game::showGameScore() const {
	attron(COLOR_PAIR(BORDER));
	mvprintw(_h + 1, _w - 10, "Time: %d", clock()/CLOCKS_PER_SEC);
	mvaddstr(_h + 1, 1, (("Score: " + std::to_string(_score)).c_str()));
	
}


void	Game::_setRandomSpacePosition(Space & space) {	
	space.setX(std::rand() % (_w - 1) + 1);
	space.setY(std::rand() % (_h - 1) + 1);
}
void	Game::_createRandomSpace(void) {
	_space = new Space[_TerroristCount];

	for (int i = 0; i < _TerroristCount; i++) {
		_setRandomSpacePosition(_space[i]);
	}
	for (int i = 0; i < _TerroristCount/2; i++) {
		_space[i].setSpeed(_space[i].getSpeed() - 0.0002);
	}
}
