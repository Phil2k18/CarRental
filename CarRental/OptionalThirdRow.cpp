#include "OptionalThirdRow.h"

OptionalThirdRow::~OptionalThirdRow()
{
}


int OptionalThirdRow::GetMaxSeats() const
{
	return m_vc.GetMaxSeats() + m_additionalSeatsNo;
}
