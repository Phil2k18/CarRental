#pragma once
#include "Vehicle.h"
class OptionalDecrator :
	public Vehicle
{
public:
	OptionalDecrator(Vehicle &vc);
	~OptionalDecrator();
	inline virtual int GetMaxSeats() const{ return m_vc.GetMaxSeats(); };
	inline virtual string GetPackage() const{ return m_vc.GetPackage(); };
	inline virtual void SetLicensePlate(string id){ m_licensePlate = m_vc.GetLicensePlate(); }
	inline virtual string GetLicensePlate() const{ return m_licensePlate; }
	inline virtual void SetBrand(string bd){ m_brand = m_vc.GetBrand(); }
	inline virtual string GetBrand() const{ return m_brand; }
protected:
	Vehicle &m_vc;
};

