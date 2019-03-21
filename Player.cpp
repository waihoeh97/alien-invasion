#include "DefaultHeaderFiles.h"

Player::Player()
{
    //! initialize all the attribute (Player attribute & GameObject attribute)
    x = 16;
    y = 5;
    row = 3;
    col = 3;
    speedX = 1;
    speedY = 1;
    colour = YELLOW;

    bulletType = STRAIGHT;
    updateDelayDuration = 60;

    enableShooting = false;
    score = 0;
    health = 20;
    life = 3;
    shootDelayTimer = 0;
    shootDelayDuration = 10;

    //! character design
    char tempSprite[3][3] = {
                                {'X', '1', ' '},
                                {' ', '1', (char)16},
                                {'X', '1', ' '}
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

void Player::Update(int elapsedTime)
{
    //!     0                20
    updateDelayTimer += elapsedTime;
        //! 20               60
    if (updateDelayTimer < updateDelayDuration)
    {
        return;
    }
    //!
    updateDelayTimer %= updateDelayDuration;

    shootDelayTimer += elapsedTime;
    if (shootDelayTimer < shootDelayDuration)
    {
        return;
    }
    shootDelayTimer %= shootDelayDuration;

    //! player input control player avatar movement
    if (GetAsyncKeyState(VK_LEFT))
    {
        MoveLeft();
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        MoveRight();
    }
    if (GetAsyncKeyState(VK_UP))
    {
        MoveUp();
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        MoveDown();
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        enableShooting = true;
    }

    if (CheckOverBoundary())
    {
        //! cannot move;
        x = xOld;
        y = yOld;
    }
}
