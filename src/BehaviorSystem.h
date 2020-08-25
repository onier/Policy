//
// Created by dev on 2020/8/20.
//

#ifndef PUPPY_ENERGYTRANCESYSTEM_H
#define PUPPY_ENERGYTRANCESYSTEM_H

#include "type_traits"
#include "PolicyAnimal.h"
#include "glog/logging.h"
#include "boost/shared_ptr.hpp"

class BehaviorSystem {
public:
    BehaviorSystem() {};

    template<typename Animal, class Supplier,
            typename std::enable_if<std::is_base_of<Breathe<Air>, Animal>::value, int>::type = 0,
            typename std::enable_if<std::is_same<Supplier, Air>::value>::type * = nullptr>
    void beathe(boost::shared_ptr<Animal> t, Supplier supplier) {
        LOG(INFO) << " " << t->name;
        t->breathe(supplier);
    };


    template<typename Animal, class Supplier,
            typename std::enable_if<std::is_base_of<Breathe<Water>, Animal>::value, int>::type = 0,
            typename std::enable_if<std::is_same<Supplier, Water>::value>::type * = nullptr>
    void beathe(boost::shared_ptr<Animal> t, Supplier supplier) {
        LOG(INFO) << " " << t->name;
        t->breathe(supplier);
    };

    template<typename Animal, class Supplier,
            typename std::enable_if<std::is_base_of<Swin<Water>, Animal>::value, int>::type = 0,
            typename std::enable_if<std::is_same<Supplier, Water>::value>::type * = nullptr>
    void swin(boost::shared_ptr<Animal> t, Supplier supplier) {
        LOG(INFO) << " " << t->name;
        t->swin(111);
    }

    template<typename Animal, class Supplier,
            typename std::enable_if<std::is_base_of<Fly<Air>, Animal>::value, int>::type = 0,
            typename std::enable_if<std::is_same<Supplier, Air>::value>::type * = nullptr>
    void fly(boost::shared_ptr<Animal> t, Supplier supplier) {
        LOG(INFO) << " " << t->name;
        t->fly(22);
    }

    template<typename Animal, class Food,
            typename std::enable_if<std::is_base_of<Eat<Grass>, Animal>::value, int>::type = 0,
            typename std::enable_if<std::is_same<Food, Grass>::value>::type * = nullptr>
    void eat(boost::shared_ptr<Animal> t, Food food) {
        t->eat(food);
    }

    template<typename Animal, class Food,
            typename std::enable_if<std::is_base_of<Eat<Meat>, Animal>::value, int>::type = 0,
            typename std::enable_if<std::is_same<Food, Meat>::value>::type * = nullptr
//            typename std::enable_if<std::is_base_of<Fish, Food>::value, int>::type = 0
    >
    void eat(boost::shared_ptr<Animal> t, Food food) {
        t->eat(food);
    }


    template<typename Animal, class Food,
            typename std::enable_if<std::is_base_of<Eat<Fish>, Animal>::value, int>::type = 0,
            typename std::enable_if<std::is_same<Food, Fish>::value>::type * = nullptr
//            typename std::enable_if<std::is_base_of<Fish, Food>::value, int>::type = 0
    >
    void eat(boost::shared_ptr<Animal> t, Food food) {
        LOG(INFO)<<food.name;
        t->eat(food);
    }

};


#endif //PUPPY_ENERGYTRANCESYSTEM_H
