//#include "PolicyAnimal.h"
//#include "boost/shared_ptr.hpp"
//#include "BehaviorSystem.h"
//#include "iostream"
//
//
//int main() {
//    BehaviorSystem behaviorSystem;
//    Air air;
//    air.number = 1;
//    Water water;
//    boost::shared_ptr<Bird> bird = boost::shared_ptr<Bird>(new Bird("Bird", 1, air));
//    boost::shared_ptr<Fish> fish = boost::shared_ptr<Fish>(new Fish("Fish", 1, water));
//
//    behaviorSystem.beathe(bird, air);
////    behaviorSystem.beathe(bird, air);
////    behaviorSystem.beathe(bird, air);
////    behaviorSystem.beathe(finsh, water);
////    behaviorSystem.beathe(finsh, water);
////    behaviorSystem.beathe(finsh, water);
//    behaviorSystem.swin(fish, water);
//    behaviorSystem.fly(bird, air);
//
//    Meat meat;
//    Grass grass;
//    behaviorSystem.eat(fish, grass);
////    behaviorSystem.eat(bird,grass);
//    boost::shared_ptr<Eagle> eagle = boost::shared_ptr<Eagle>(new Eagle);
//    behaviorSystem.eat(eagle, meat);
//
//    boost::shared_ptr<Penguin> penguin = boost::shared_ptr<Penguin>(new Penguin);
//    Fish f("Fish", 1, water);
//    f.getQuantity();
//    behaviorSystem.eat(penguin, f);
//
////    behaviorSystem.eat(penguin, f);
////    energyTranceSystem.beathe(finsh);
//}

#import "ZooKeeper.h"
#include <boost/make_shared.hpp>

int main() {
    typedef TemplateAnimal<Pool, MeatSupply> Tiger;
    typedef TemplateAnimal<Pool, GlassSupply> Rabbit;
    typedef TemplateAnimal<Pool, FishSupply> Seal;
    boost::shared_ptr<FoodSupply> supply = boost::make_shared<FoodSupply>();
    Tiger tiger;
    Zookeeper zookeeper;
    zookeeper.foodSupply = supply;
    zookeeper.eat(tiger);
    Rabbit rabbit;
    zookeeper.eat(rabbit);
    Seal seal;
    zookeeper.eat(seal);
//    zookeeper.eat()
}