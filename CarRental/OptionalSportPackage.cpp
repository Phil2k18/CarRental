#include "OptionalSportPackage.h"


OptionalSportPackage::~OptionalSportPackage()
{
}


string OptionalSportPackage::GetPackage() const
{
	return m_vc.GetPackage() + " + " + m_additionalSportPackage;
}