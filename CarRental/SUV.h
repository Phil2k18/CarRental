#pragma once
#include "Vehicle.h"
class SUV :
	public Vehicle
{
public:
	SUV();
	~SUV();

	inline virtual void SetLicensePlate(string id){ m_licensePlate = id; }
	inline virtual string GetLicensePlate() const{ return m_licensePlate; }
	inline virtual void SetBrand(string bd){ m_brand = bd; }
	inline virtual string GetBrand() const{ return m_brand; }
	virtual int GetMaxSeats() const;

private:
	const int m_defaultSeatsNo;
};

