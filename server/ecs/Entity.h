#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>

#include "../../DataDefinitions.h"

/**
 * @brief Se define entidad como un objeto que participa en el juego 
 * de alguna manera, no necesariamente un NPC o un jugador.
 */
class Entity {
  protected:
    PositionData position;
  public:
    explicit Entity(PositionData& p);
    virtual ~Entity();
    static bool checkPositionCollision(
      const PositionData& p1, const PositionData&p2);
    static double getPositionDistance(
      const PositionData& p1, const PositionData&p2);
    static bool checkPositionInRange(
      const PositionData& p1,
      const PositionData& p2,
      double distance);
    static MovementData getPositionDirection(
      const PositionData& from, const PositionData& to);
    virtual bool checkCollision(Entity& otherEntity) const;
    virtual bool checkInRange(Entity& otherEntity, double distance) const;
};

/**
 * @brief Se define a una entidad viva como un objeto que participa en el juego
 * y que tiene un estado de salud.
 */
class LiveEntity: public Entity {
  protected:
    friend class Player;
    size_t level;
    HealthAndManaData health;
    SkillsData skills;
  public:
    LiveEntity(PositionData& p, HealthAndManaData& h, SkillsData &s, 
      size_t level);
    virtual void rcvDamage(int &damage);
    virtual bool attack(LiveEntity &entity, int xCoord, int yCoord);
};

#endif
