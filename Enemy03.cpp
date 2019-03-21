#include "DefaultHeaderFiles.h"

Enemy03::Enemy03()
{
    int randomNumber = rand() % 2;
    if (randomNumber == 0)
    {
        x = 45;
        y = 60;
        AddMove(SOUTH, 0);
        AddMove(WEST, 1000);
        AddMove(EAST, 3000);
        AddMove(NORTH, 5000);
        AddMove(WEST, 9000);
    }
    else if (randomNumber == 1)
    {
        x = 30;
        y = 55;
        AddMove(NORTH, 0);
        AddMove(WEST, 1000);
        AddMove(SOUTH, 3000);
        AddMove(WEST, 9000);
    }
    /*x = 30;
    y = 20;*/
    row = 3;
    col = 3;
    speedX = 1;
    speedY = 1;
    colour = LIGHTBLUE;

    isInTheScreen = false;

    updateDelayTimer = 0;
    updateDelayDuration = 60;

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

void Enemy03::Update(int elapsedTime)
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
