//
// Created by dev on 2020/8/18.
//

#include "PolicyAnimal.h"

BaseAnimal::BaseAnimal(const std::string &name, int weight, int type) : name(name), weight(weight), type(type) {}

BaseAnimal::BaseAnimal(const std::string &name, int weight) : name(name), weight(weight) {

}

BaseAnimal::BaseAnimal() {

}

Bird::Bird(const Air &t) : Fly(t) {}

Bird::Bird(const std::string &name, int weight, const Air &t) : BaseAnimal(name, weight), Fly(t) {}


Fish::Fish(const std::string &name, int weight, const Water &t) : BaseAnimal(name, weight), Swin(t) {}

FlyFish::FlyFish(const std::string &name, int weight, const Water &t, const Air &t1) : BaseAnimal(name, weight),
                                                                                       Swin(t), Fly(t1) {}

Penguin::Penguin(const std::string &name, int weight, const Water &t) : BaseAnimal(name, weight), Swin(t) {}

Penguin::Penguin() : BaseAnimal("Penguin", 1), Swin(t) {}

Eagle::Eagle() : Bird(Air()) {}
