//
// Created by dev on 2020/8/18.
//

#ifndef PUPPY_POLICYANIMAL_H
#define PUPPY_POLICYANIMAL_H

#include "glog/logging.h"
#include "string"

struct BaseAnimal {
    std::string name;
    int weight;
    int type;

    BaseAnimal(const std::string &name, int weight, int type);

    BaseAnimal(const std::string &name, int weight);

    BaseAnimal();
};

template<class Food>
struct Eat {
    double eat(Food f) {
        return f.getQuantity();
    };
};

template<class T>
struct Breathe {
    double breathe(T t) {
        return t.getOxygen();
    }
};

template<class T>
struct Swin {
    Swin(T t) {
        t = t;
    };

    void swin(int deep) {
        t.swin(deep);
    }

    T t;
};

template<class T>
struct Fly {
    Fly(T t) {
        t = t;
    };

    void fly(int height) {
        t.fly(height);
    }

    T t;
};

struct Air {
    virtual double getOxygen() {
        if (number > 1) {
            number = number - 1;
            LOG(INFO) << " supply oxygen  from air " << 1;
            return 1;
        }
        LOG(INFO) << "  oxygen anoxia ";
        return 0;
    }

    virtual void fly(int height) {
        LOG(INFO) << "fly int the air " << height;
    }

    double number;
};

struct Water {
    double getOxygen() {
        LOG(INFO) << " supply oxygen  from water ";
        return 0.02;
    }

    void swin(int deep) {
        LOG(INFO) << " swin in Water " << deep;
    }
};

struct Meat {
    int getQuantity() {
        LOG(INFO) << " meat food  return 100K";
        return 100000;
    }
};

struct Grass {
    int getQuantity() {
        LOG(INFO) << " Grass food  return 1K";
        return 100;
    }
};

struct Bird : public BaseAnimal, public Breathe<Air>, public Fly<Air> {
    Bird(const Air &t);

    Bird(const std::string &name, int weight, const Air &t);
};

struct Eagle : public Bird, public Eat<Meat> {
    Eagle();
};

struct Fish : public BaseAnimal, public Breathe<Water>, public Swin<Water>, public Eat<Grass> {
    Fish(const std::string &name, int weight, const Water &t);


    virtual int getQuantity() {
        LOG(INFO) << " Fish food  return 200K";
        return 200000;
    }
};

struct FlyFish : public BaseAnimal, public Breathe<Water>, public Swin<Water>, public Fly<Air> {

    FlyFish(const std::string &name, int weight, const Water &t, const Air &t1);
};

struct Penguin : public BaseAnimal, public Breathe<Air>, public Swin<Water>, public Eat<Fish> {
    Penguin(const std::string &name, int weight, const Water &t);

    Penguin();
};

#endif //PUPPY_POLICYANIMAL_H
