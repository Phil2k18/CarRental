#pragma once
#include "OptionalDecrator.h"
class OptionalThirdRow :
	public OptionalDecrator
{
public:
	OptionalThirdRow(Vehicle &vc) :OptionalDecrator(vc), m_additionalSeatsNo(2){};
	~OptionalThirdRow();
	virtual int GetMaxSeats() const;
private:
	int m_additionalSeatsNo;
};

