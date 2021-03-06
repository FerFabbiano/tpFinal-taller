#include "Instruction.h"

#include <iostream>
#include <string>

MoveInstruction::MoveInstruction(size_t id, std::string xDir, 
  std::string yDir) :
    playerId(id),
    xDir(xDir),
    yDir(yDir) {}

void MoveInstruction::run(GameModel& game) {
  int x = stoi(xDir);
  int y = stoi(yDir);
  game.move(playerId, x, y);
}

AuthInstruction::AuthInstruction(
  ClientProxy& client, 
  std::string nick, 
  std::string password) :
    client(client), nick(nick), password(password) {}

void AuthInstruction::run(GameModel& game) {
  size_t playerId;

  bool success = game.authenticate(password, nick, 
    client.getUpdateBQ(), playerId);

  if (success) {
    client.setPlayerId(playerId);
    return;
  }
}

CreatePlayerInstruction::CreatePlayerInstruction(
  ClientProxy& client,
  std::string nick, 
  std::string password,
  std::string race, 
  std::string classType) : 
    client(client),
    nick(nick),
    password(password),
    race(static_cast<PlayerRace> (race[0])),
    classType(static_cast<PlayerClass> (classType[0])){}

void CreatePlayerInstruction::run(GameModel& game) {
  size_t playerId;
  
  bool success = game.createPlayer(
    client.getUpdateBQ(), playerId, nick, password, classType, race);

  if (success){
    client.setPlayerId(playerId);
    return;
  }
}

CloseInstruction::CloseInstruction(size_t id) :
  playerId(id) {}

void CloseInstruction::run(GameModel& game) {
  game.eraseClient(playerId);
}

StopMovementInstruction::StopMovementInstruction(size_t id) :
  playerId(id) {}

void StopMovementInstruction::run(GameModel& game) {
  game.stopMovement(playerId);
}

AttackInstrucion::AttackInstrucion(size_t id, std::string xPos, 
  std::string yPos) :
  playerId(id),
  xPos(stoi(xPos)),
  yPos(stoi(yPos)){}
  
void AttackInstrucion::run(GameModel& game) {
  game.attack(playerId, xPos, yPos);
}

EquipInstruction::EquipInstruction(size_t id, std::string inventoryPosition) :
  playerId(id),
  inventoryPosition(stoi(inventoryPosition)){}
  
void EquipInstruction::run(GameModel& game) {
  game.equipPlayer(playerId, inventoryPosition);
}

ResurrectInstrucion::ResurrectInstrucion(size_t id) :
  playerId(id){}

void ResurrectInstrucion::run(GameModel& game) {
  game.resurrect(playerId);
}

MeditateInstruction::MeditateInstruction(size_t id) :
  playerId(id){}

void MeditateInstruction::run(GameModel& game) {
  game.meditate(playerId);
}

ThrowObjInstruction::ThrowObjInstruction(size_t id, std::string inventoryPos) :
  playerId(id) {
    valid = isValid(inventoryPos);
    if (valid) inventoryPosition = (std::stoi(inventoryPos)-1);
}

void ThrowObjInstruction::run(GameModel& game) {
  if (valid){
    game.throwInventoryObj(playerId, inventoryPosition);
    return;
  }

  game.commandError(playerId);
}

PickUpInstruction::PickUpInstruction(size_t id) :
  playerId(id) {}

void PickUpInstruction::run(GameModel& game) {
  game.pickUpObj(playerId);
}

ListInstruction::ListInstruction(size_t id) :
  playerId(id) {}

void ListInstruction::run(GameModel& game) {
  game.list(playerId);
}

SellInstruction::SellInstruction(
  size_t id, std::string itemNumber) : playerId(id) {
    valid = isValid(itemNumber);
    if (valid) this->itemNumber = std::stoi(itemNumber);
}

void SellInstruction::run(GameModel& game) {
  if (valid){
    game.sell(playerId, itemNumber);
    return;
  }

  game.commandError(playerId);
}

BuyInstruction::BuyInstruction(
  size_t id, std::string itemNumber) : playerId(id) {
    valid = isValid(itemNumber);
    if (valid) this->itemNumber = std::stoi(itemNumber);
}

void BuyInstruction::run(GameModel& game) {
  if (valid){
    game.buy(playerId, itemNumber);
    return;
  }

  game.commandError(playerId);
}

HealInstruction::HealInstruction(size_t id) : playerId(id) {}

void HealInstruction::run(GameModel& game) {
  game.heal(playerId);
}

DepositGoldInstruction::DepositGoldInstruction(
  size_t id, std::string amount) : playerId(id) {
    valid = isValid(amount);
    if (valid) this->amount = std::stoi(amount);
}

void DepositGoldInstruction::run(GameModel& game) {
  if (valid){
    game.depositGold(playerId, amount);
    return;
  }

  game.commandError(playerId);
}

DepositItemInstruction::DepositItemInstruction(size_t id, 
  std::string inventoryPos) :
    playerId(id) {
      valid = isValid(inventoryPos);
      if (valid) inventoryPosition = (std::stoi(inventoryPos)-1);
}

void DepositItemInstruction::run(GameModel& game) {
  if (valid){
    game.depositItem(playerId, inventoryPosition);
    return;
  }

  game.commandError(playerId);
}

WithdrawGoldInstruction::WithdrawGoldInstruction(size_t id, 
  std::string amount) :
    playerId(id) {
      valid = isValid(amount);
      if (valid) this->amount = (std::stoi(amount));
}

void WithdrawGoldInstruction::run(GameModel& game) {
  if (valid){
    game.withdrawGold(playerId, amount);
    return;
  }

  game.commandError(playerId);
}

WithdrawItemInstruction::WithdrawItemInstruction(size_t id, 
  std::string inventoryPos) :
    playerId(id) {
      valid = isValid(inventoryPos);
      if (valid) inventoryPosition = (std::stoi(inventoryPos)-1);
}

void WithdrawItemInstruction::run(GameModel& game) {
  if (valid){
    game.withdrawItem(playerId, inventoryPosition);
    return;
  }

  game.commandError(playerId);
}

SendMessageInstruction::SendMessageInstruction(
  size_t id, 
  std::string nick,
  std::string message) :
    playerId(id), 
    nick(nick),
    message(message) {}

void SendMessageInstruction::run(GameModel& game) {
  game.sendMessageToPlayer(playerId, nick, message);
}
