#include "ClientProxy.h"
#include <string>
#include <vector>
#include <iostream>

ClientProxy::ClientProxy(std::string& host, std::string& port) {
  std::cout << "Connected to: " << host << ":" << port << std::endl;
}

void ClientProxy::authentificate(std::string& alias) {
  std::cout << "Player " << alias << " authentificated" << std::endl;
}

void ClientProxy::init() {
  MapParser m;
  m.loadMap("client/assets/map/pindonga2.json");
  map = m.getMapData();

  // ------ TEST CODE FOR PARSE OBJ LAYER 
  std::vector<struct ObjectLayerData>& objectl = m.getObjectLayers();

  for (size_t i = 0; i < objectl.size(); i++){
    for (size_t j = 0; j < objectl[i].objects.size(); j++){
      std::cout << objectl[i].objects[j].x << std::endl;
      std::cout << objectl[i].objects[j].y << std::endl;
      std::cout << objectl[i].objects[j].width << std::endl;
      std::cout << objectl[i].objects[j].height << std::endl;
    }
  }
}