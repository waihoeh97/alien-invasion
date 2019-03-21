#include "DefaultHeaderFiles.h"

BigBoss::BigBoss()
{
    x = 60;
    y = 15;
    AddMove(SOUTH, 1000);
    row = 5;
    col = 5;
    speedX = 1;
    speedY = 1;
    colour = RED;
    health = 30;

    isInTheScreen = false;

    updateDelayTimer = 0;
    updateDelayDuration = 60;

    shootDelayTimer = 10;
    shootDelayDuration = 500;
    enableShooting = false;
    bulletType = STRAIGHT;

    //! character design
    char tempSprite[5][5] = {
                                {' ', (char)233, (char)233, (char)233, (char)233},
                                {' ', (char)233, (char)233, (char)233, (char)233},
                                {'<', (char)233, (char)233, (char)233, (char)233},
                                {' ', (char)233, (char)233, (char)233, (char)233},
                                {' ', (char)233, (char)233, (char)233, (char)233},
                            };
    //! copy the design to the sprite attribute
    sprite = new char*[row];
    for (int i = 0; i < row; i++)
    {
        sprite[i] = new char[col];
        for (int j = 0; j < col; j++)
        {
            sprite[i][j] = tempSprite[i][j];
        }
    }
}

void BigBoss::setBullet(BULLET_TYPE bullet)
{
    bulletType = bullet;
}

void BigBoss::Update(int elapsedTime)
{
    updateDelayTimer += elapsedTime;
    shootDelayTimer += elapsedTime;
    moveTimer += elapsedTime;

    if (updateDelayTimer < updateDelayDuration)
    {
        return;
    }
    updateDelayTimer %= updateDelayDuration;

    UpdateMove(elapsedTime);

    if (shootDelayTimer > shootDelayDuration)
    {
        enableShooting = true;
        shootDelayTimer = 0;
    }

    if (CheckOverBoundary())
    {
        if (y >= 25 && x <= 50)
        {
            AddMove(NORTH, 100);
        }
        else if (y <= 10 && x <= 50)
        {
            AddMove(SOUTH, 100);
        }
        else if (y >= 25 && x >= 50)
        {
            AddMove(NORTH, 100);
        }
        else if (y <= 10 && x >= 50)
        {
            AddMove(SOUTH, 100);
        }
    }
}

