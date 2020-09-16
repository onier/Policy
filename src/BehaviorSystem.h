//#include <boost/shared_ptr.hpp>
//#include <boost/type_traits/is_pointer.hpp>
//#include <boost/mpl/bool.hpp>
//#include <iostream>
//#include <boost/core/enable_if.hpp>
//#include <logger/Logger.h>
//#include "rw/common/Ptr.hpp"
//#include "rw/math/Transform3D.hpp"
//
//template<class T>
//struct is_shared_ptr
//        : boost::mpl::false_ {
//};
//
//template<class T>
//struct is_shared_ptr<boost::shared_ptr<T> >
//        : boost::mpl::true_ {
//};
//
//template<class T>
//struct is_shared_ptr<rw::common::Ptr<T> >
//        : boost::mpl::true_ {
//};
//
//class Dummy {
//};
//
//template<typename _T,
//        typename std::enable_if<is_shared_ptr<_T>::value || std::is_same<_T, Dummy>::value, int>::type = 0
//>
//void check(_T) {
//    LOG_INFO << "type pass";
//}
//
//int main() {
//    Dummy dummy;
//    Dummy *dummy_ptr = &dummy;
//    boost::shared_ptr<Dummy> shared_dummy(new Dummy);
//
//    check(dummy);        // false
////    check(dummy_ptr);    // false
//    check(shared_dummy); // true
//    check(rw::common::ownedPtr(new rw::math::Transform3D<>()));
//    return 0;
//}
//
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
