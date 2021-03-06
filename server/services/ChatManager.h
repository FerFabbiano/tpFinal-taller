#ifndef CHAT_MANAGER_H
#define CHAT_MANAGER_H

#include "../../definitions/ChatDefinitions.h"
#include <string>

class ChatManager{
  public:
    ChatManager() = delete;
    ~ChatManager() = delete;
    ChatManager(const ChatManager&) = delete;
    ChatManager& operator=(const ChatManager&) = delete;
    static void initialMessage(ChatData &chat);
    static void insufficientFunds(ChatData &chat);
    static void invalidOption(ChatData &chat);
    static void noInventorySpace(ChatData &chat);
    static void damageReceived(ChatData &chat, int damage);
    static void enemyDodgedTheAttack(ChatData &chat);
    static void attackDodged(ChatData &chat);
    static void damageCaused(ChatData &data, int damage);
    static void meditating(ChatData &chat);
    static void stopMeditating(ChatData &chat);
    static void inventoryIsFull(ChatData &chat);
    static void otherMessages(
      ChatData &chat,
      std::string &msg, 
      MessageType &type);
    static void successfullSell(ChatData &chat, size_t itemValue);
    static void resurrecting(ChatData &chat, size_t estimateTime);
    static void traderDontBuyThatITem(ChatData &chat);
    static void successfullBuy(ChatData &chat, size_t itemValue);
    static void maxGold(ChatData &chat);
    static void depositGoldSuccess(ChatData &chat, size_t bankGold);
    static void depositItemSuccess(ChatData &chat);
    static void successfullGoldExtraction(ChatData &chat, size_t bankGold);
    static void successfullItemExtraction(ChatData &chat);

  private:
};

#endif
