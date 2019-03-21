#include "DefaultHeaderFiles.h"

class Bullet : public GameObject
{
public:
    DIRECTION direction;
    bool isReverseDirection;
    //constructor
    Bullet();

    void Update(int elapsedTime);
};
