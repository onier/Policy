//
// Created by cobot on 20-8-27.
//

#pragma once

#include <boost/exception/detail/shared_ptr.hpp>
#include "PolicyAnimal.h"
#include <boost/enable_shared_from_this.hpp>

struct Pool {
    double getOxygen() {
        LOG(INFO) << " supply oxygen  from water ";
        return 0.02;
    }

    void swin(int deep) {
        LOG(INFO) << " swin in Water " << deep;
    }

    int maxCount;
    int maxOxygen;
    int count;
};

class FoodSupply;

struct MeatSupply {
    int getQuantity() {
        LOG(INFO) << " meat food  return 100K";
        return 100000;
    }

    boost::shared_ptr<FoodSupply> foodSupply;
};

struct GlassSupply {
    int getQuantity() {
        LOG(INFO) << " GlassSupply food  return 100K";
        return 100000;
    }

    boost::shared_ptr<FoodSupply> foodSupply;
};

struct FishSupply {
    int getQuantity() {
        LOG(INFO) << " FishSupply food  return 100K";
        return 100000;
    }

    boost::shared_ptr<FoodSupply> foodSupply;
};

struct FoodSupply {
    int meat;
    int glass;
};

struct Zookeeper : public boost::enable_shared_from_this<Zookeeper> {
    template<typename Animal,
            typename std::enable_if<std::is_base_of<Eat<MeatSupply>, Animal>::value, int>::type = 0
    >
    void eat(Animal animal) {
        MeatSupply meatSupply;
        animal.eat(meatSupply);
    }


    template<typename Animal,
            typename std::enable_if<std::is_base_of<Eat<GlassSupply>, Animal>::value, int>::type = 0
    >
    void eat(Animal animal) {
        GlassSupply glassSupply;
        animal.eat(glassSupply);
    }

    template<typename Animal,
            typename std::enable_if<std::is_base_of<Eat<FishSupply>, Animal>::value, int>::type = 0
    >
    void eat(Animal animal) {
        FishSupply glassSupply;
        animal.eat(glassSupply);
    }


    boost::shared_ptr<FoodSupply> foodSupply;
};
