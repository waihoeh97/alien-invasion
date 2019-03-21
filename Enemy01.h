#ifndef _ENEMY01_H_INCLUDED
#define _ENEMY01_H_INCLUDED
#include "DefaultHeaderFiles.h"

class Enemy01 : public Enemy
{
public:
    Enemy01();
    void Update(int elapsedTime);
};

//void Enemy01::update(int elapsedTime) = 0;

#endif // _ENEMY01_H_INCLUDED
