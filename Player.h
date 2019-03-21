#include "DefaultHeaderFiles.h"
//! player inherited from GameObject
class Player : public GameObject
{
public:
    //! define unique attribute for the player only
    bool enableShooting;
    int score;
    int health;
    int shootDelayTimer;
    int shootDelayDuration;
    int life;
    BULLET_TYPE bulletType;

    Player();
    void Update(int elapsedTime);
};
