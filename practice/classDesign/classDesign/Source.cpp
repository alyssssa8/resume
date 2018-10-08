


#include <iostream>
#include "Vehicle.h"

using namespace std;

int main()
{
   
    Car car1, car2;
    Truck truck1, truck2;    
    SUV suv1, suv2;

    Vehicle *v = nullptr;
    //v->setVehicleType(ENUMTRUCK);
    car1.setMPG(30);
   
    carType firstCartype=SEDAN;
    car1.setCarType(firstCartype); // this will work after you add the enum
    
    
    car2.setMPG(30);
    carType secondCartype=COUPE;
    car2.setCarType(secondCartype); // this will work after you add the enum

    truck1.setMPG(20);
    truck1.setTowingCapacity(6000);
    truck2.setMPG(20);
    truck2.setTowingCapacity(5000);

    suv1.setMPG(25);
    suv1.setAWD(true);
    suv2.setMPG(25);
    suv2.setAWD(false);

    v = &car1;

    // this line SHOULD cause a BUILD FAILE. 
    // After you cause the build fail, you can comment it out.
    // if you cannot cause build fail. Your code is wrong.
    //std::cout << v->MPG << std::endl; 


    // This will work after you add the 
    v->setVehicleType(ENUMTRUCK);
    if (v->getVehicleType() == ENUMTRUCK) {
        std::cout << "test 1 passed\n";
    }
    else {
        std::cout << "test 1 failed\n";
    }

    v = &car1;
    if (v->getMonthlyCost() == 900) {
        std::cout << "test 2 passed\n";
    }
    else {
        std::cout << "test 2 failed\n";
    }

    v = &truck2;
    if (v->getMonthlyCost() == 1000) {
        std::cout << "test 3 passed\n";
    }
    else {
        std::cout << "test 3 failed\n";
    }

}
