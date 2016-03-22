#pragma once
#include "OptionalDecrator.h"
class OptionalSportPackage :
	public OptionalDecrator
{
public:
	OptionalSportPackage(Vehicle &vc) : OptionalDecrator(vc), m_additionalSportPackage("Sport Package"){};
	~OptionalSportPackage();
	virtual string GetPackage() const;
private:
	string m_additionalSportPackage;
};

