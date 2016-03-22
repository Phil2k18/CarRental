#include "OptionalDecrator.h"

OptionalDecrator::OptionalDecrator(Vehicle &vc) :m_vc(vc)
{
	SetBrand(m_vc.GetBrand());
	SetLicensePlate(m_vc.GetLicensePlate());
}

OptionalDecrator::~OptionalDecrator()
{
	if(&m_vc) delete &m_vc;
}
