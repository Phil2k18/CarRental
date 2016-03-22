#pragma once
#include <unordered_map>
#include "Vehicle.h"
class CarRental
{
public:
	CarRental();
	~CarRental();
	bool AddVehicle(Vehicle &v);
	bool RemoveVehicle(Vehicle &v);
	bool RentVehicle(Vehicle &v);
	bool ReturnVehicle(Vehicle &v);
	int GetPassengerCapcity(Vehicle &v) const;

	bool AddVehicle(string lp);
	bool RemoveVehicle(string lp);
	bool RentVehicle(string lp);
	bool ReturnVehicle(string lp);
	int GetPassengerCapcity(string lp) const;
	unordered_map<string, Vehicle*> GetAvailableVehicle() const;
	unordered_map<string, Vehicle*> GetUnavailableVehicle() const;

	bool isLicensePlateDuplicate(string lp) const;

protected:
	unordered_map<string,Vehicle*> m_available;
	unordered_map<string, Vehicle*>  m_unavailable;
	
	Vehicle* GetAvailVehicleByLP(string lp) const;
	Vehicle* GetUnavailVehicleByLP(string lp) const;
	Vehicle* GetVehicleByLP(string lp) const;

	bool IsVehicleExist(Vehicle &v) const;
	bool IsAvaiVehicleExist(Vehicle &v) const;
	bool IsUnavaiVehicleExist(Vehicle &v) const;

private:
	//Deallocate the dynamically allocated Vehicle objects.
	void DeleteAvaiList();
	void DeleteUnavaiList();
};

