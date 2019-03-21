#include "DefaultHeaderFiles.h"

Enemy02::Enemy02()
{
    int randomNumber = rand() % 2;
    if (randomNumber == 0)
    {
        x = 75;
        y = 10;
        AddMove(WEST, 0);
        AddMove(NORTH_WEST, 100);
    }
    else if (randomNumber == 1)
    {
        x = 65;
        y = 15;
        AddMove(WEST, 0);
        AddMove(SOUTH, 100);
        AddMove(WEST, 300);
    }
    /*x = 80;
    y = 20;*/
    row = 3;
    col = 3;
    speedX = 1;
    speedY = 1;
    colour = RED;

    isInTheScreen = false;

    updateDelayTimer = 0;
    updateDelayDuration = 20;

    shootDelayTimer = 10;
    shootDelayDuration = 500;
    enableShooting = false;
    bulletType = STRAIGHT;

    //! character design
    char tempSprite[3][3] = {
                                {' ', '1', 'X'},
                                {(char)16, '1', ' '},
                                {' ', '1', 'X'}
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

void Enemy02::Update(int elapsedTime)
{
    updateDelayTimer += elapsedTime;
    shootDelayTimer += elapsedTime;
    moveTimer += elapsedTime;

    if (updateDelayTimer < updateDelayDuration)
    {
        return;
    }
    updateDelayTimer %= updateDelayDuration;

    //MoveLeft();
    UpdateMove(elapsedTime);

    if (shootDelayTimer > shootDelayDuration)
    {
        enableShooting = true;
        shootDelayTimer = 0;
    }
}
