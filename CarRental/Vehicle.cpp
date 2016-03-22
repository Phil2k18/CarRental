#include "Vehicle.h"

Vehicle::Vehicle()
{
}


Vehicle::~Vehicle()
{
}


ostream& operator<<(ostream& out, const Vehicle& f)
{
	string str = "License Plate: " + f.GetLicensePlate() + "\n";
	str.append("Brand: ").append(f.GetBrand()).append("\n");
	str.append("Max Number of Seats: ").append(patch::to_string(f.GetMaxSeats())).append("\n");
	str.append("Pakcage Info: ").append(f.GetPackage()).append("\n");
	return out << str;
}