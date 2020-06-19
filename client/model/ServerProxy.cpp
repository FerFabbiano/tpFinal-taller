#include "ServerProxy.h"
#include <iostream>
#include <string>
#include <vector>

ServerProxy::ServerProxy(std::string& host, std::string& port) {
  std::cout << "Connected to: " << host << ":" << port << std::endl;
}

void ServerProxy::authentificate(std::string& alias) {
  std::cout << "Player " << alias << " authentificated" << std::endl;
}

void ServerProxy::init() {
  MapParser m;
  m.loadMap("client/assets/map/pindonga3.json");
  map = m.getMapData();

  struct EnemyData data;
  data.position.x = 100;
  data.position.y = 100;
  data.movement.xDir = 0;
  data.movement.yDir = 1;
  data.movement.isMoving = false;
  data.type = GOBLIN;
  data.movement.speed = 1;
  npcs.emplace_back(data);

  data.position.x = 200;
  data.position.y = 100;
  data.type = SKELETON;
  data.movement.speed = 2;
  npcs.emplace_back(data);

  data.position.x = 300;
  data.position.y = 100;
  data.type = SPIDER;
  data.movement.speed = 3;
  npcs.emplace_back(data);
  // ------ TEST CODE FOR ENEMIES

  mainPlayer.rootd.prace = DWARF;
  mainPlayer.position.x = (542 - 11) / 2;
  mainPlayer.position.y = (413 - 154) / 2;
  mainPlayer.movement.xDir = 0;
  mainPlayer.movement.yDir = 1;
  mainPlayer.movement.isMoving = false;
  mainPlayer.points.totalHP = 100;
  mainPlayer.points.totalMP = 100;
  mainPlayer.points.currentHP = 100;
  mainPlayer.points.currentMP = 100;
  mainPlayer.movement.speed = 5;
  mainPlayer.gold = 0;
}

void ServerProxy::move(int xDir, int yDir){
  if(xDir == 0 && yDir == 0){
    mainPlayer.movement.isMoving = false;
  } else {
    mainPlayer.movement.isMoving = true;
    mainPlayer.movement.xDir = xDir;
    mainPlayer.movement.yDir = yDir;
    mainPlayer.position.x += xDir * mainPlayer.movement.speed;
    mainPlayer.position.y += yDir * mainPlayer.movement.speed;
  }
}

void ServerProxy::moveNPC(int index, int xDir, int yDir){
  // for(unsigned int i = 0; i < npcs.size(); i++){
  //   if(xDir == 0 && yDir == 0){
  //     npcs[i].movement.isMoving = false;
  //   } else {
  //     npcs[i].movement.isMoving = true;
  //     npcs[i].movement.xDir = xDir;
  //     npcs[i].movement.yDir = yDir;
  //     npcs[i].position.x += xDir * npcs[i].movement.speed;
  //     npcs[i].position.y += yDir * npcs[i].movement.speed;
  //   }
  // }

  npcs[index].movement.isMoving = true;
  npcs[index].movement.xDir = xDir;
  npcs[index].movement.yDir = yDir;
  npcs[index].position.x += xDir * npcs[index].movement.speed;
  npcs[index].position.y += yDir * npcs[index].movement.speed;
}

void ServerProxy::attack(int xPos, int yPos) {
  std::cout << xPos << std::endl;
  std::cout << yPos << std::endl;
  std::cout << std::endl;
}

MainPlayerData ServerProxy::getMainPlayerData() const {
  return mainPlayer;
}

MapData ServerProxy::getMapData() const {
  return map;
}

std::vector<EnemyData> ServerProxy::getNPCData() const {
  return npcs;
}

bool ServerProxy::isAuthenticated() const {
  return authentificated;
}
