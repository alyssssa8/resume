#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle()
{
    
}
Vehicle::Vehicle(vehicleType inputVehicleType)
{
    myVehicleType = inputVehicleType;
}
Truck::Truck():Vehicle()
{

}
Car::Car():Vehicle()
{

}
SUV:: SUV(): Vehicle()
{

}

void Vehicle:: setHorssePower(int inputHorse) 
{
    horsePower = inputHorse;
}
void Vehicle::setSeatNumber(int inputSeatNumber)
{
    seatNumber = inputSeatNumber;
}
void Vehicle::setMPG(int inputMPG)
{
    MPG = inputMPG;
}
void Vehicle::setMake(string inputMake)
{
    make = inputMake;
}
void Vehicle::setModel(string inputModel)
{
    model = inputModel;
}

int Vehicle::getHorssePower()
{
    return horsePower;
}
int Vehicle::getSeatNumber()
{
    return seatNumber;
}
int Vehicle::getMPG()
{
    return MPG;
}
string Vehicle::getMake()
{
    return make;
}
string Vehicle::getModel()
{
    return model;
}
void Vehicle::setVehicleType(vehicleType inputVehicleType)
{
    myVehicleType = inputVehicleType;
}

vehicleType Vehicle::getVehicleType()
{
    return myVehicleType;
}
int Vehicle::getMonthlyCost()
{
    
    return 0;
}


void Truck::setTowingCapacity(float inputCapacity)
{
    towingCapaciy = inputCapacity;
}
float Truck::getTowingCapacity()
{
    return towingCapaciy;
}
int Truck::getMonthlyCost()
{
    
    return static_cast<int> (MPG*towingCapaciy/100);
}

void Car::setCarType(carType inputCartype)
{
    myInputCarType = inputCartype;
}
carType Car::getCarType()
{
    return myInputCarType;
}
int Car::getMonthlyCost()
{   
    if (myInputCarType == COUPE)
    {
        return MPG * 35;
    }
    else
    {
        return  MPG * 30;
    }
   
}
void SUV::setAWD(bool inputAWD)
{
    AWD = inputAWD;
}
bool SUV::getAWD()
{
    return AWD;
}

int SUV::getMonthlyCost()
{
    if (AWD == true)
    {
        return MPG * 45;
    }


    return MPG*40;
    
}