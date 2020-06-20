#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "../DataDefinitions.h"
#include "GameModel.h"
#include <string>

class Player : public Entity{
  private:
    size_t id;
    PlayerRootData root;
    Inventory inventory;
    HealthAndManaData health;
    PositionData position;
    size_t gold;
    size_t level;
    friend class GameModel;

  public:
    Player(MainPlayerData playerData, size_t id);
    ~Player();
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    void move(std::string x, std::string y);
};

#endif
