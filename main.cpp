#include "DefaultHeaderFiles.h"

int startTime = 0;
int currentTime = 0;
int elapsedTime = 0;
int lastUpdateTime = 0;

bool isExit = false;

Player player;
BigBoss bigBoss;

vector<Enemy*> enemyList;
vector<Bullet> playerBulletList;
vector<Bullet> enemyBulletList;
vector<SpawnInfo> spawnList;
vector<Item*> itemList;
vector<ItemSpawnInfo> itemSpawnList;

void DrawHealth()
{
    if (player.health < 7)
    {
        textcolor(LIGHTRED);
    }
    else if (player.health >= 7 && player.health <= 13)
    {
        textcolor(LIGHTGREEN);
    }

    for (int i = 0; i < player.health; i++)
    {
        cout << char(219);
    }

    for (int i = 0; player.health + i < 20; i++)
    {
        cout << " ";
    }
    textcolor(WHITE);
}

void DrawBossHealth()
{
    if (bigBoss.health < 10)
    {
        textcolor(LIGHTRED);
    }
    else if (bigBoss.health >= 7 && bigBoss.health <= 23)
    {
        textcolor(LIGHTMAGENTA);
    }

    for (int i = 0; i < bigBoss.health; i++)
    {
        cout << char(219);
    }

    for (int i = 0; bigBoss.health + i < 30; i++)
    {
        cout << " ";
    }
    textcolor(WHITE);
}

//! draw border
void DrawBorder()
{
                   //!     4               77
    for (int i = BOUNDARY_LEFT; i < BOUNDARY_RIGHT; i++)
    {
        gotoxy(i, BOUNDARY_TOP);
        cout << char(205);
    }
    for (int i = BOUNDARY_LEFT; i < BOUNDARY_RIGHT; i++)
    {
        gotoxy(i, BOUNDARY_BOTTOM);
        cout << char(205);
    }
    for (int i = BOUNDARY_TOP; i < BOUNDARY_BOTTOM; i++)
    {
        gotoxy(BOUNDARY_LEFT, i);
        cout << char(186);
    }
    for (int i = BOUNDARY_TOP; i < BOUNDARY_BOTTOM; i++)
    {
        gotoxy(BOUNDARY_RIGHT, i);
        cout << char(186);
    }
    gotoxy(BOUNDARY_LEFT, BOUNDARY_TOP);
    cout << char(201);
    gotoxy(BOUNDARY_LEFT, BOUNDARY_BOTTOM);
    cout << char(200);
    gotoxy(BOUNDARY_RIGHT, BOUNDARY_TOP);
    cout << char(187);
    gotoxy(BOUNDARY_RIGHT, BOUNDARY_BOTTOM);
    cout << char(188);
}

void DrawHUD()
{
    textcolor(LIGHTGREEN);
    gotoxy(BOUNDARY_LEFT, BOUNDARY_TOP - 1);
    cout << "Health : " , DrawHealth();
    textcolor(LIGHTCYAN);
    gotoxy(BOUNDARY_LEFT, BOUNDARY_TOP - 3);
    cout << "Score: " << player.score;
    textcolor(WHITE);
    gotoxy(BOUNDARY_LEFT + 20, BOUNDARY_TOP - 3);
    cout << "Life : " << player.life;
    textcolor(LIGHTRED);
    if (player.score >= 200)
    {
        gotoxy(BOUNDARY_LEFT + 30, BOUNDARY_TOP - 1);
        cout << "Boss Health : ", DrawBossHealth();
    }
}

void Shoot(bool isPlayer, GameObject& object)
{
    BULLET_TYPE tempBulletType;
    vector<Bullet>* tempBulletList;
    bool tempIsReverseDirection = false;

    //! check the object -> player or enemy?
    //! initialization
    if (isPlayer)
    {
        //! from the general object -> Explicitly casting -> get back particular object
        tempBulletType = ((Player*)&object)->bulletType;
        tempBulletList = &playerBulletList;
        player.enableShooting = false;
    }
    else
    {
        //! from the general object -> Explicitly casting -> get back particular object
        tempBulletType = ((Enemy*)&object)->bulletType;
        tempBulletList = &enemyBulletList;
        ((Enemy*)&object)->enableShooting = false;
        tempIsReverseDirection = true;
    }

    //! select bullet type
    if (tempBulletType == STRAIGHT)
    {
        if (isPlayer)
        {
            //! create the bullet
            Bullet tempBullet;
            tempBullet.x = object.x + 1;
            tempBullet.y = object.y + 1;
            tempBullet.direction = EAST;
            tempBullet.colour = CYAN;
            tempBullet.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet);
        }
        else
        {
            //! create the bullet
            Bullet tempBullet;
            tempBullet.x = object.x + 1;
            tempBullet.y = object.y + 1;
            tempBullet.direction = EAST;
            tempBullet.colour = YELLOW;
            tempBullet.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet);
        }

    }
    else if (tempBulletType == DUAL)
    {
        if (isPlayer)
        {
            //! create the first bullet
            Bullet tempBullet1;
            tempBullet1.x = object.x + 1;
            tempBullet1.y = object.y + 2;
            tempBullet1.direction = EAST;
            tempBullet1.colour = MAGENTA;
            tempBullet1.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet1);

            //! create the second bullet
            Bullet tempBullet2;
            tempBullet2.x = object.x + 1;
            tempBullet2.y = object.y;
            tempBullet2.direction = EAST;
            tempBullet2.colour = MAGENTA;
            tempBullet2.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet2);
        }
        else
        {
            //! create the first bullet
            Bullet tempBullet1;
            tempBullet1.x = object.x + 1;
            tempBullet1.y = object.y + 2;
            tempBullet1.direction = EAST;
            tempBullet1.colour = MAGENTA;
            tempBullet1.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet1);

            //! create the second bullet
            Bullet tempBullet2;
            tempBullet2.x = object.x + 1;
            tempBullet2.y = object.y;
            tempBullet2.direction = EAST;
            tempBullet2.colour = MAGENTA;
            tempBullet2.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet2);
        }
    }
    else if (tempBulletType == TRIPLE)
    {
        if (isPlayer)
        {
            //! create the first bullet
            Bullet tempBullet1;
            tempBullet1.x = player.x;
            tempBullet1.y = player.y;
            tempBullet1.direction = NORTH_EAST;
            tempBullet1.colour = GREEN;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet1);

            //! create the second bullet
            Bullet tempBullet2;
            tempBullet2.x = player.x + 2;
            tempBullet2.y = player.y + 1;
            tempBullet2.direction = EAST;
            tempBullet2.colour = GREEN;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet2);

            //! create the second bullet
            Bullet tempBullet3;
            tempBullet3.x = player.x;
            tempBullet3.y = player.y + 2;
            tempBullet3.direction = SOUTH_EAST;
            tempBullet3.colour = GREEN;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet3);
        }
        else
        {
            //! create the first bullet
            Bullet tempBullet1;
            tempBullet1.x = object.x;
            tempBullet1.y = object.y;
            tempBullet1.direction = NORTH_EAST;
            tempBullet1.colour = GREEN;
            tempBullet1.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet1);

            //! create the second bullet
            Bullet tempBullet2;
            tempBullet2.x = object.x + 2;
            tempBullet2.y = object.y + 1;
            tempBullet2.direction = EAST;
            tempBullet2.colour = GREEN;
            tempBullet2.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet2);

            //! create the second bullet
            Bullet tempBullet3;
            tempBullet3.x = object.x;
            tempBullet3.y = object.y + 2;
            tempBullet3.direction = SOUTH_EAST;
            tempBullet3.colour = GREEN;
            tempBullet3.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet3);
        }
    }
    else if (tempBulletType == FOURLEAFS)
    {
        if (isPlayer)
        {
            //! create the bullet
            Bullet tempBullet;
            tempBullet.x = player.x + 1;
            tempBullet.y = player.y + 1;
            tempBullet.direction = NORTH_EAST;
            tempBullet.colour = GREEN;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet);
            //! create the bullet
            Bullet tempBullet1;
            tempBullet1.x = player.x + 1;
            tempBullet1.y = player.y + 1;
            tempBullet1.direction = NORTH_WEST;
            tempBullet1.colour = LIGHTGREEN;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet1);
            //! create the bullet
            Bullet tempBullet2;
            tempBullet2.x = player.x + 1;
            tempBullet2.y = player.y + 1;
            tempBullet2.direction = SOUTH_EAST;
            tempBullet2.colour = LIGHTGREEN;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet2);
            //! create the bullet
            Bullet tempBullet3;
            tempBullet3.x = player.x + 1;
            tempBullet3.y = player.y + 1;
            tempBullet3.direction = SOUTH_WEST;
            tempBullet3.colour = GREEN;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet3);
        }
    }
    else if (tempBulletType == LASER)
    {
        if (isPlayer)
        {
            //! create the bullet
            Bullet tempBullet;
            tempBullet.x = player.x + 1;
            tempBullet.y = player.y + 1;
            tempBullet.direction = EAST;
            tempBullet.speedX = 5;
            tempBullet.updateDelayTimer = 2;
            tempBullet.colour = LIGHTGRAY;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet);
        }
    }
    else if (tempBulletType == SWORD)
    {
        if (isPlayer)
        {
            //! create the first bullet
            Bullet tempBullet1;
            tempBullet1.x = player.x;
            tempBullet1.y = player.y;
            tempBullet1.direction = NORTH;
            tempBullet1.colour = LIGHTRED;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet1);

            //! create the second bullet
            Bullet tempBullet2;
            tempBullet2.x = player.x + 2;
            tempBullet2.y = player.y + 1;
            tempBullet2.direction = EAST;
            tempBullet2.colour = LIGHTRED;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet2);

            //! create the second bullet
            Bullet tempBullet3;
            tempBullet3.x = player.x;
            tempBullet3.y = player.y + 2;
            tempBullet3.direction = SOUTH;
            tempBullet3.colour = LIGHTRED;
            //! store the created bullet to the bullet vector
            playerBulletList.push_back(tempBullet3);
        }
        else
        {
            //! create the first bullet
            Bullet tempBullet1;
            tempBullet1.x = object.x;
            tempBullet1.y = object.y;
            tempBullet1.direction = NORTH;
            tempBullet1.colour = LIGHTRED;
            tempBullet1.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet1);

            //! create the second bullet
            Bullet tempBullet2;
            tempBullet2.x = object.x + 2;
            tempBullet2.y = object.y + 1;
            tempBullet2.direction = EAST;
            tempBullet2.colour = LIGHTRED;
            tempBullet2.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet2);

            //! create the second bullet
            Bullet tempBullet3;
            tempBullet3.x = object.x;
            tempBullet3.y = object.y + 2;
            tempBullet3.direction = SOUTH;
            tempBullet3.colour = LIGHTRED;
            tempBullet3.isReverseDirection = tempIsReverseDirection;
            //! store the created bullet to the bullet vector
            tempBulletList->push_back(tempBullet3);
        }
    }
    player.enableShooting = false;
}

bool CheckBoundingBoxCollision(GameObject a, GameObject b)
{
    if (a.x + a.col < b.x ||
        a.x > b.x + b.col ||
        a.y + a.row < b.y ||
        a.y > b.y + b.row)
    {
        return false;
    }
    return true;
}

void CheckCollision()
{
    //! enemy vs bullet
    for (int i = 0; i < enemyList.size(); i++)
    {
        for (int j = 0; j < playerBulletList.size(); j++)
        {
            if (CheckBoundingBoxCollision(*enemyList[i], playerBulletList[j]))
            {
                //! true -> both object colliding
                enemyList[i]->isToBeDestroyed = true;
                playerBulletList[i].isToBeDestroyed = true;
                player.score += 10;
            }
        }
    }
    //! player vs enemy Bullet
    for (int i = 0; i < enemyBulletList.size(); i++)
    {
        if (CheckBoundingBoxCollision(enemyBulletList[i], player))
        {
            enemyBulletList[i].isToBeDestroyed = true;
            player.isToBeDestroyed = true;
            player.health -= 1;
        }
    }

    //! player vs BigBoss
    if (player.score >= 200)
    {
        for (int i = 0; i < playerBulletList.size(); i++)
        {
            if (CheckBoundingBoxCollision(playerBulletList[i], bigBoss))
            {
                playerBulletList[i].isToBeDestroyed = true;
                bigBoss.isToBeDestroyed = true;
                bigBoss.health -= 1;
            }
        }
    }
}

void SpawnEnemy(ENEMY_TYPE type)
{
    Enemy* tempEnemy;
    if (type == ENEMY_01)
    {
        tempEnemy = new Enemy01();
    }
    else if (type == ENEMY_02)
    {
        tempEnemy = new Enemy02();
    }
    else if (type == ENEMY_03)
    {
        tempEnemy = new Enemy03();
    }
    //! after enemy created, store to the enemy list (vector)
    enemyList.push_back(tempEnemy);
}

void SpawnItem(ITEM_TYPE itemType)
{
    Item* tempItem;
    if (itemType == HEALTH_PACK)
    {
        tempItem = new Item(itemType);
    }
    else if (itemType == DUAL_PACK)
    {
        tempItem = new Item(itemType);
    }
    else if (itemType == TRIPLE_PACK)
    {
        tempItem = new Item(itemType);
    }
    else if (itemType == FOURLEAFS_PACK)
    {
        tempItem = new Item(itemType);
    }
    else if (itemType == EXTRA_PACK)
    {
        tempItem = new Item(itemType);
    }
    else if (itemType == SLOWER_PACK)
    {
        tempItem = new Item(itemType);
    }
    else if (itemType == FASTER_PACK)
    {
        tempItem = new Item(itemType);
    }
    itemList.push_back(tempItem);
}

//! spawn info needed
void AddEnemy(ENEMY_TYPE type, int time)
{
    SpawnInfo tempSpawnInfo;
    tempSpawnInfo.type = type;
    tempSpawnInfo.time = time;
    tempSpawnInfo.isSpawned = false;

    spawnList.push_back(tempSpawnInfo);
}

void AddItem(ITEM_TYPE type, int time)
{
    ItemSpawnInfo tempItemSpawnInfo;
    tempItemSpawnInfo.type = type;
    tempItemSpawnInfo.time = time;
    tempItemSpawnInfo.isSpawned = false;

    itemSpawnList.push_back(tempItemSpawnInfo);
}

void AddEnemyPattern01(int timeOffSet)
{
    AddEnemy(ENEMY_01, timeOffSet + 100);
    AddEnemy(ENEMY_02, timeOffSet + 150);
    AddEnemy(ENEMY_03, timeOffSet + 200);
    AddItem(HEALTH_PACK, timeOffSet + 200);
}

void AddEnemyPattern02(int timeOffSet)
{
    AddEnemy(ENEMY_02, timeOffSet + 450);
    AddEnemy(ENEMY_02, timeOffSet + 300);
    AddEnemy(ENEMY_02, timeOffSet + 500);
    AddItem(HEALTH_PACK, timeOffSet + 200);
    //AddItem(DUAL_PACK, timeOffSet + 600);
}

void AddEnemyPattern03(int timeOffSet)
{
    AddEnemy(ENEMY_03, timeOffSet + 600);
    AddEnemy(ENEMY_03, timeOffSet + 650);
    AddEnemy(ENEMY_03, timeOffSet + 900);
    //AddItem(TRIPLE_PACK, timeOffSet + 1000);
    //AddItem(SLOWER_PACK, timeOffSet + 700);
}

void AddEnemyPattern04(int timeOffSet)
{
    AddEnemy(ENEMY_01, timeOffSet + 550);
    AddEnemy(ENEMY_01, timeOffSet + 350);
    AddEnemy(ENEMY_01, timeOffSet + 400);
    //AddItem(EXTRA_PACK, timeOffSet + 800);
    //AddItem(FASTER_PACK, timeOffSet + 600);
}

void InitializeSpawnList()
{
    for (int i = 0; i < 200; i++)
    {
        int randType = rand() % 4;
        if (randType == 0)
        {
            AddEnemyPattern01(1500 * i);
        }
        else if (randType == 1)
        {
            AddEnemyPattern02(1500 * i);
        }
        else if (randType == 2)
        {
            AddEnemyPattern03(1500 * i);
        }
        else if (randType == 3)
        {
            AddEnemyPattern04(1500 * i);
        }
    }
}

void UpdateSpawn()
{
    for (int i = 0; i < spawnList.size(); i++)
    {
        if (spawnList[i].isSpawned == true)
        {
            continue;
        }
        if (currentTime - startTime > spawnList[i].time)
        {
            SpawnEnemy(spawnList[i].type);
            spawnList[i].isSpawned = true;
        }
    }
}

void UpdateItemSpawn()
{
    for (int i = 0; i < itemSpawnList.size(); i++)
    {
        if (itemSpawnList[i].isSpawned == true)
        {
            continue;
        }
        if (currentTime - startTime > itemSpawnList[i].time)
        {
            SpawnItem(itemSpawnList[i].type);
            itemSpawnList[i].isSpawned = true;
        }
    }
}

int main()
{
    system("mode con: cols=80 lines=30");
    srand(time(NULL));

    DrawBorder();
    InitializeSpawnList();

    startTime = clock();
    //! Game loop
    do
    {
        currentTime = clock();

        UpdateSpawn();
        UpdateItemSpawn();
        player.Update(elapsedTime);
        bigBoss.Update(elapsedTime);
        if (player.enableShooting)
        {
            Shoot(true, player);
        }
        if (player.score >= 200)
        {
            if (bigBoss.enableShooting)
            {
                Shoot(false, bigBoss);
            }
        }

        //! enemy update
        for (int i = 0; i < enemyList.size(); i++)
        {
            enemyList[i]->Update(elapsedTime);
            if (enemyList[i]->enableShooting)
            {
                Shoot(false, *enemyList[i]);
            }
        }

        //! player bullet update
        for (int i = 0; i < playerBulletList.size(); i++)
        {
            playerBulletList[i].Update(elapsedTime);
        }
        //! enemy bullet update
        for (int i = 0; i < enemyBulletList.size(); i++)
        {
            enemyBulletList[i].Update(elapsedTime);
        }
        //! item update
        for (int i = 0; i < itemList.size(); i++)
        {
            itemList[i]->Update(elapsedTime);
        }

        player.Draw();
        if (player.score >= 200)
        {
            bigBoss.Draw();
        }
        CheckCollision();

        //! draw enemy
        for (int i = 0; i < enemyList.size(); i++)
        {
            //! is out of screen
            if (enemyList[i]->isToBeDestroyed)
            {
                enemyList[i]->DrawTrail();
                enemyList.erase(enemyList.begin() + i);
                i--;
            }
            else
            {
                //! Draw
                enemyList[i]->Draw();
            }
        }

        //! draw item
        for (int i = 0; i < itemList.size(); i++)
        {
            //! is out of screen
            if (itemList[i]->isToBeDestroyed)
            {
                itemList[i]->DrawTrail();
                itemList.erase(itemList.begin() + i);
                i--;
            }
            else
            {
                //! Draw
                itemList[i]->Draw();
            }
        }

        //! draw player bullet
        for (int i = 0; i < playerBulletList.size(); i++)
        {
            //! is out of screen
            if (playerBulletList[i].isToBeDestroyed)
            {
                playerBulletList[i].DrawTrail();
                playerBulletList.erase(playerBulletList.begin() + i);
                i--;
            }
            else
            {
                //! Draw
                playerBulletList[i].Draw();
            }
        }

        //! draw enemy bullet
        for (int i = 0; i < enemyBulletList.size(); i++)
        {
            //! is out of screen
            if (enemyBulletList[i].isToBeDestroyed)
            {
                enemyBulletList[i].DrawTrail();
                enemyBulletList.erase(enemyBulletList.begin() + i);
                i--;
            }
            else
            {
                //! Draw
                enemyBulletList[i].Draw();
            }
        }
        //! BigBoss Bullet Management
        if(bigBoss.health >=20 && bigBoss.health<=24)
        {
            bigBoss.setBullet(DUAL);
        }

        if(bigBoss.health >=10 && bigBoss.health<=19)
        {
            bigBoss.setBullet(TRIPLE);
        }

        if(bigBoss.health >=1 && bigBoss.health<=9)
        {
            bigBoss.setBullet(SWORD);
        }

        if (player.health <= 0)
        {
            player.life -= 1;
            player.health = 20;
        }
        if (player.life <= 0)
        {
            isExit = true;
        }
        if (bigBoss.health <= 0)
        {
            bigBoss.isToBeDestroyed = true;
            isExit = true;
        }
        DrawHUD();

        elapsedTime = (clock() - lastUpdateTime)*1000 / CLOCKS_PER_SEC;
        lastUpdateTime = clock();
        Sleep(25);

    } while (!isExit);
    cout << "\n\n";
    system("PAUSE");
    return 0;
}
