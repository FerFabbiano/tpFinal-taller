#include "CronInstructions.h"

#include <iostream>

PlayerSetCoordsInstruction::PlayerSetCoordsInstruction(size_t id,
  int x, int y) :
  playerId(id),
  x(x),
  y(y) {}

void PlayerSetCoordsInstruction::run(GameModel& game) {
  game.playerSetCoords(playerId, x, y);
}

NPCSetCoordsInstruction::NPCSetCoordsInstruction(size_t id,
  int xPos, int yPos) :
  npcId(id),
  xPos(xPos),
  yPos(yPos) {}

void NPCSetCoordsInstruction::run(GameModel& game) {
  game.npcSetCoords(npcId, xPos, yPos);
}