#include "DefaultHeaderFiles.h"

class Item : public GameObject
{
public:
    DIRECTION direction;
    //bool isReverseDirection;
    ITEM_TYPE itemType;
    //constructor
    Item();
    Item(ITEM_TYPE type);

    void Update(int elapsedTime);
};


