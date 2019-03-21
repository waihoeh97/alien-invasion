#include "DefaultHeaderFiles.h"

Enemy01::Enemy01()
{
    int randomNumber = rand() % 2;
    if (randomNumber == 0)
    {
        x = 70;
        y = 5;
        AddMove(WEST, 100);
        AddMove(SOUTH_WEST, 1000);
    }
    else if (randomNumber == 1)
    {
        x = 65;
        y = 15;
        AddMove(WEST, 100);
        AddMove(SOUTH_WEST, 1000);
    }
    //! x = 55;
    //! y = 5;
    row = 3;
    col = 3;
    speedX = 1;
    speedY = 1;
    colour = GREEN;

    isInTheScreen = false;

    updateDelayTimer = 0;
    updateDelayDuration = 60;

    shootDelayTimer = 10;
    shootDelayDuration = 500;
    enableShooting = false;
    bulletType = DUAL;

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

void Enemy01::Update(int elapsedTime)
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
