#include "DefaultHeaderFiles.h"

Item::Item()
{

}
Item::Item(ITEM_TYPE type)
{
    int randomNumberX = 20 + rand() % 60;
    int randomNumberY = 10 + rand() % 30;
    x = randomNumberX;
    y = randomNumberY;
    row = 3;
    col = 3;
    speedX = 1;
    speedY = 1;
    colour = WHITE;

    //isInTheScreen = false;

    updateDelayTimer = 0;
    updateDelayDuration = 40;
    itemType = type;
    char pack = ' ';

    if (type == HEALTH_PACK)
    {
        pack = 'H';
    }
    else if (type == DUAL_PACK)
    {
        pack = 'D';
    }
    else if (type == EXTRA_PACK)
    {
        pack = 'E';
    }
    else if (type == FASTER_PACK)
    {
        pack = 'F';
    }
    else if (type == SLOWER_PACK)
    {
        pack = 'S';
    }

    char tempSprite[3][3] = {
                                {'|', '-', '|'},
                                {'|', pack, '|'},
                                {'|', '-', '|'}
                            };

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

void Item::Update(int elapsedTime)
{
    updateDelayTimer += elapsedTime;

    if (updateDelayTimer < updateDelayDuration)
    {
        return;
    }
    updateDelayTimer %= updateDelayDuration;

    MoveLeft();
}
