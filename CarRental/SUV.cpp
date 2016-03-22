#include "SUV.h"


SUV::SUV() :m_defaultSeatsNo(5)
{
	SetBrand("SUV");
	SetLicensePlate("*******");
}


SUV::~SUV()
{
}


int SUV::GetMaxSeats() const
{
	return m_defaultSeatsNo;
}
