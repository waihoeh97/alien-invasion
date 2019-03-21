#ifndef _BIGBOSS_H_INCLUDED
#define _BIGBOSS_H_INCLUDED
#include "DefaultHeaderFiles.h"

class BigBoss : public Enemy
{
public:
    BigBoss();
    int health;
    void Update(int elapsedTime);
    void setBullet(BULLET_TYPE bullet);
};

//void Enemy01::update(int elapsedTime) = 0;

#endif // _BIGBOSS_H_INCLUDED


