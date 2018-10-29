#ifndef GAME_ENTITY_CLASS_HPP
#define GAME_ENTITY_CLASS_HPP

#include <ncurses.h>

class AGameEntity
{
    public:
        AGameEntity();
        AGameEntity(int x, int y);
        AGameEntity(AGameEntity const & src);
        virtual ~AGameEntity();

        AGameEntity &operator=(const AGameEntity &rhs);
        virtual void move();

        float   getX() const;
	    float   getY() const;
        float   getSpeed() const;

        void    setX(float x);
	    void    setY(float y);
        void    setSpeed(float speed);
        void    defaultSetter();

        unsigned int   getEntityColorPairId() const;
        char            getEntityModel() const;
        
        bool         getIsAlive() const;
        void         kill();
        void         live();
    protected:
        char           _entityModel;
        unsigned int   _entityColorPairId;
        bool            _isAlive;
        float             _speed;
        float           _x;
        float           _y;
};

#endif