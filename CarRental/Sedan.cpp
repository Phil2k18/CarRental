#include "Sedan.h"


Sedan::Sedan() :m_defaultSeatsNo(4)
{
	SetBrand("Sedan");
	SetLicensePlate("*******");
}


Sedan::~Sedan()
{
}


int Sedan::GetMaxSeats() const
{
	return m_defaultSeatsNo;
}
