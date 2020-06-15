#include "LoginController.h"

LoginController::LoginController(
  ClientProxy& model,
  SdlAssetsManager& manager) :
  model(model),
  manager(manager) {}

void LoginController::init() {
  manager.addTexture("user-input", LOGIN_SCREEN_PATH);
  LTexture* baseScreen = manager.getTexture("login-screen-path");
  LTexture* userInput = manager.getTexture("user-input");
  TTF_Font* font = manager.getFont("main");

  screens.emplace_back(new BackgroundEntity(baseScreen));

  screens.emplace_back(new TextInputEntity(userInput, font, 1 , 345, 262));
}


EntityList& LoginController::getEntities() {
  return screens;
}
