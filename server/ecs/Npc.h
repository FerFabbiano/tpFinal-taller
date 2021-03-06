#ifndef NPC_H
#define NPC_H

#include "Entity.h"
#include "../../DataDefinitions.h"
#include "../GameModel.h"

class NPC : public LiveEntity {
  public:
    NPC(EnemyData npcData, size_t level);
    NPC(const NPC&) = delete;
    NPC& operator=(const NPC&) = delete;
    bool checkCollision(Entity& otherEntity) const override;
    bool checkInRange(Entity& otherEntity, double distance) const override;
    bool attack(LiveEntity &entity, int xCoord, int yCoord) override;
    bool drop(DropItemData &drop);
    void setNextRespawn();
    void setEnemyData(EnemyData &enemy);
    void rcvDamage(int &damage) override;
    static std::unique_ptr<NPC> createNPC(
      size_t id,
      PositionData position,
      NPCClass npcType);
    static size_t getNewId();
    
  private:
    NPCClass type;
    PositionData spawnPosition;
    std::chrono::system_clock::time_point lastAttack;
    static size_t idGenerator;
    friend class GameModel;
};

#endif
