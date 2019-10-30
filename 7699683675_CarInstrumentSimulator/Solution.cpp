//Car Instrument Simulator
#include<iostream>
using namespace std;
// FuelGauge Class
class FuelGauge
{
// Member variables
private:
// The amount of fuel, in gallons
int gallons;
// Member functions
public:
// Default constructor
FuelGauge()
{ gallons = 0;}
// Overloaded constructor that accepts
// an argument for gallons. It can hold
// no more than 15 gallons.
FuelGauge(int g)
{
if (g <= 15)
gallons = g;
else
gallons = 15;
}
// Accessor for the gallons
int getGallons()
{ return gallons;}
// The incrementGallons function increments
// the value of the gallons member, if it
// is less than 15. The car holds a maximum
// of 15 gallons.
void incrementGallons()
{
if (gallons < 15)
gallons++;
else
cout << "FUEL OVERFLOWING!!!\n"; } // The decrementGallons function decrements // the value of the gallons member, if it // is greater than 0.
 void decrementGallons() { if (gallons > 0)
gallons--;
else
cout << "OUT OF GAS!!!\n";
}
};


// Odometer Class
class Odometer
{
// Member variables
private:
// The current mileage
int mileage;
// Mileage set-point to remember when the
// FuelGuage gallons were decremented.
int setPoint;
// Pointer to a FuelGauge object
FuelGauge *fuelGauge;
// Member functions
public:
// The constructor accepts arguments
// for the mileage and the fuel guage.
Odometer(int m, FuelGauge *fp)
{ mileage = m; setPoint = m; fuelGauge = fp; }
// Accessor for the mileage
int getMileage()
{ return mileage;}
// The incrementMiles function increments
// the value of the mileage member.
void incrementMiles()
{
// Increment the mileage, but rollover
// if we go past 999,999.
if(mileage < 999999) 
   mileage++; 
else 
   mileage = 0; 
    // See if we have burned a gallon of gas. This // happens every 24 miles. // // If setPoint is greater than mileage, then // the odometer has rolled over. if (setPoint > mileage)
    // Add 1 million to get the actual mileage.
    int falseMileage = mileage + 1000000;
    if ( (falseMileage - setPoint) >= 24 ) {
        fuelGauge->decrementGallons();
        setPoint = mileage;
    }
 else
{
    if ( (mileage - setPoint) >= 24 ) {
        fuelGauge->decrementGallons();
        setPoint = mileage;
    }
}

}
};

// Function prototypes
int main()
{
// Create a FuelGuage object.
FuelGauge fuel;
// Create an Odometer object to work with the FuelGauge object.
Odometer odometer(0, &fuel);
// Fill the car up with gas.
for (int i = 0; i < 15; i++) fuel.incrementGallons(); // Drive the car until it runs out of gas. while (fuel.getGallons() > 0)
{
// Drive a mile.
odometer.incrementMiles();
// Display the mileage.
cout << "Mileage: " << odometer.getMileage() << endl;
// Display the amount of fuel.
cout << "Fuel level: " << fuel.getGallons() << " gallons\n";
cout << "------------------------------\n";
}
return 0;
}