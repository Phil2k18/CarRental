#pragma once
#include <string>
#include<iostream>
#include "StringHandler.h"
using namespace std;

class Vehicle
{
public:
	Vehicle();
	virtual ~Vehicle();
	virtual int GetMaxSeats() const = 0;
	inline virtual string GetPackage() const{ return "Default Package"; };
	virtual void SetLicensePlate(string id) = 0;
	virtual string GetLicensePlate() const = 0;
	virtual void SetBrand(string bd) = 0;
	virtual string GetBrand() const = 0;
	friend ostream& operator<<(ostream& out, const Vehicle& f);
protected:
	string m_licensePlate;
	string m_brand;

};

ostream& operator<<(ostream& out, const Vehicle& f);
