#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using namespace std;

enum vehicleType
{
    ENUMTRUCK,
    ENUMCAR,
    ENUMSUV
};

enum carType
{
    COUPE,
    SEDAN    
};


class Vehicle
{
protected:
    int horsePower;
    int seatNumber;
    int MPG;
    string make;
    string model;  
    vehicleType myVehicleType;

public:
    Vehicle();
    Vehicle(vehicleType);
    void setHorssePower(int);
    void setSeatNumber(int);
    void setMPG(int);
    void setMake(string);
    void setModel(string);
    void setVehicleType(vehicleType);

    int getHorssePower();
    int getSeatNumber();
    int getMPG();
    string getMake();
    string getModel();   
    vehicleType getVehicleType();
    virtual int getMonthlyCost();
};

class Truck : public Vehicle
{
private:
    float towingCapaciy;
public:
    Truck();
    void setTowingCapacity(float);
    float getTowingCapacity();
    virtual int getMonthlyCost();
};

class Car : public Vehicle
{
private:
    carType myInputCarType;
public:
    Car();
    void setCarType(carType);
    carType getCarType();

    int getMonthlyCost();
};

class SUV : public Vehicle
{
private:
    bool AWD;
public:
    SUV();
    void setAWD(bool);
    bool getAWD();
    int getMonthlyCost();
};

#endif // !VEHILE_H

