#include "Items.h"
#include <string>

Item::Item(int id, Equipable type, std::string &name) :
  id(id),
  type(type),
  name(name) {}

BodyItem::BodyItem(
  int id,
  Equipable type,
  std::string &name,
  int minDefense,
  int maxDefense) :
  Item(id, type, name),
  minDefense(minDefense),
  maxDefense(maxDefense) {}

HeadItem::HeadItem(
  int id,
  Equipable type,
  std::string &name,
  int minDefense,
  int maxDefense) :
  Item(id, type, name),
  minDefense(minDefense),
  maxDefense(maxDefense) {}

LeftHandItem::LeftHandItem(
  int id,
  Equipable type,
  std::string &name,
  int minDefense,
  int maxDefense) :
  Item(id, type, name),
  minDefense(minDefense),
  maxDefense(maxDefense) {}

RightHandItem::RightHandItem(
    int id,
    Equipable type,
    std::string &name,
    int minDamage,
    int maxDamage,
    int mana,
    int range) :
  Item(id, type, name),
  minDamage(minDamage),
  maxDamage(maxDamage),
  range(range),
  mana(mana) {}

HealthPotion::HealthPotion(
    int id,
    Equipable type,
    std::string &name) :
  Item(id, type, name) {}

ManaPotion::ManaPotion(
    int id,
    Equipable type,
    std::string &name) :
  Item(id, type, name) {}

void RightHandItem::equip(Player& p) const {
  p.equipment.rightHand = id;
  p.rightSkills.maxDamage = maxDamage;
  p.rightSkills.minDamage = minDamage;
  p.rightSkills.range = range;
  p.rightSkills.mana = mana;
}

void RightHandItem::unEquip(Player& p) const{
  p.equipment.rightHand = 0;
  p.rightSkills.maxDamage = 0;
  p.rightSkills.minDamage = 0;
  p.rightSkills.range = 0;
  p.rightSkills.mana = 0;
}

void LeftHandItem::equip(Player& p) const {
  p.equipment.leftHand = id;
  p.leftSkills.maxDefense = maxDefense;
  p.leftSkills.minDefense = maxDefense;
}

void LeftHandItem::unEquip(Player &p) const{
  p.equipment.leftHand = 0;
  p.leftSkills.maxDefense = 0;
  p.leftSkills.minDefense = 0;
}

void BodyItem::equip(Player& p) const {
  p.equipment.body = id;
  p.bodySkills.maxDefense = maxDefense;
  p.bodySkills.minDefense = minDefense;
}

void BodyItem::unEquip(Player &p) const{
  p.equipment.body = 0;
  p.bodySkills.maxDefense = 0;
  p.bodySkills.minDefense = 0;
}

void HeadItem::equip(Player& p) const {
  p.equipment.head = id;
  p.headSkills.maxDefense = maxDefense;
  p.headSkills.minDefense = maxDefense;
}

void HeadItem::unEquip(Player &p) const{
  p.equipment.head = 0;
  p.headSkills.maxDefense = 0;
  p.headSkills.minDefense = 0;
}

void HealthPotion::equip(Player& p) const {
  p.health.currentHP = p.health.totalHP;
}

void ManaPotion::equip(Player& p) const {
  p.health.currentMP = p.health.totalMP;
}
