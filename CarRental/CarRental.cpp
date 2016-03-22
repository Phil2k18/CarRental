#include "CarRental.h"


CarRental::CarRental()
{
}


CarRental::~CarRental()
{
	DeleteAvaiList();
	DeleteUnavaiList();
}

bool CarRental::AddVehicle(Vehicle &v)
{
	bool res = false;
	//Add Vehicle only if its license plate doesn't exsit.
	if (!IsVehicleExist(v))
	{
		m_available[v.GetLicensePlate()] = &v;
		res = true;
	}
	return res;	
}
bool CarRental::RemoveVehicle(Vehicle &v)
{
	Vehicle *tmp = &v;
	bool res = false;
	//return false if no such vehicle exsit.
	if (IsAvaiVehicleExist(v))
	{
		m_available.erase(v.GetLicensePlate());
		res = true;
	}
	else if (IsUnavaiVehicleExist(v))
	{
		m_unavailable.erase(v.GetLicensePlate());
		res = true;
	}	
	delete tmp;
	return res;
}

bool CarRental::RentVehicle(Vehicle &v)
{
	bool res = false;
	//if the requested vehicle is available.
	if (IsAvaiVehicleExist(v))
	{
		m_available.erase(v.GetLicensePlate());
		m_unavailable[v.GetLicensePlate()] = &v;
		res = true;
	}
	return res;
}

bool CarRental::ReturnVehicle(Vehicle &v)
{
	bool res = false;
	//if the returned vehicle is rented from the company.
	if (IsUnavaiVehicleExist(v))
	{
		m_available[v.GetLicensePlate()] = &v;
		m_unavailable.erase(v.GetLicensePlate());
		res = true;
	}
	return res;
}

// return -1 if the inquired vehicle doesn't belong to the company.
int CarRental::GetPassengerCapcity(Vehicle &v) const
{
	if (!IsVehicleExist(v)) return -1;
	else return v.GetMaxSeats();	
}


bool CarRental::RemoveVehicle(string lp)
{
	return RemoveVehicle(*GetVehicleByLP(lp));
}



bool CarRental::RentVehicle(string lp)
{
	return RentVehicle(*GetVehicleByLP(lp));
}

bool CarRental::ReturnVehicle(string lp)
{
	return ReturnVehicle(*GetVehicleByLP(lp));
}

int CarRental::GetPassengerCapcity(string lp) const
{
	return GetPassengerCapcity(*GetVehicleByLP(lp));
}


unordered_map<string,Vehicle*> CarRental::GetAvailableVehicle() const
{
	return m_available;
}

unordered_map<string, Vehicle*> CarRental::GetUnavailableVehicle() const
{
	return m_unavailable;
}


Vehicle*  CarRental::GetAvailVehicleByLP(string lp) const
{
	auto it = m_available.find(lp);
	if (it != m_available.end()) return it->second;
	else return nullptr;
}

Vehicle* CarRental::GetUnavailVehicleByLP(string lp) const
{
	auto it = m_unavailable.find(lp);
	if (it != m_unavailable.end()) return it->second;
	else return nullptr;
}

Vehicle* CarRental::GetVehicleByLP(string lp) const
{
	//search in the avaialbe vehicle list
	Vehicle *v = GetAvailVehicleByLP(lp);
	if (v)  return v;

	//search in the unavaialbe vehicle list if not found in avaialbe list
	v = GetUnavailVehicleByLP(lp);
	//return vehicle in the unavailable list 
	//or return nullptr to indicate no found.
	return v;
}


void CarRental::DeleteAvaiList()
{
	for (auto it : m_available)
	{
		delete it.second;
	}
}
void CarRental::DeleteUnavaiList()
{
	for (auto it : m_unavailable)
	{
		if(it.second) delete it.second;
	}
}

bool CarRental::IsVehicleExist(Vehicle &v) const
{
	bool res = false;
	if (&v && GetVehicleByLP(v.GetLicensePlate())!= nullptr)
	{
		res = true;
	}
	return res;
}

bool CarRental::IsAvaiVehicleExist(Vehicle &v) const
{
	bool res = false;
	if (&v && GetAvailVehicleByLP(v.GetLicensePlate()))
	{
		res = true;
	}
	return res;
}

bool CarRental::IsUnavaiVehicleExist(Vehicle &v) const
{
	bool res = false;
	if (&v && GetUnavailVehicleByLP(v.GetLicensePlate()))
	{
		res = true;
	}
	return res;
}

bool CarRental::isLicensePlateDuplicate(string lp) const
{
	if (GetVehicleByLP(lp)) return true;
	return false;
}