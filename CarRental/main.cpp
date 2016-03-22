#include <unordered_set>
#include "SUV.h"
#include "Sedan.h"
#include "OptionalThirdRow.h"
#include "OptionalSportPackage.h"
#include "CarRental.h"


using namespace std;


//Automatically generate unique License plate number, 
//starting from 0000000 with increment of 1.
string GenerateLPlate();

//Create a concrete Vehicle
//type: Vehicle type(SUV, Sedan or future extended types)
//optional: the option switch (e.g. optional 3rd row added to a SUV)
Vehicle* CreateVehicle(string type, bool optional);

//Show Welcome message
void ShowWelcom();

//Show Command Instructions
void ShowCommandInstructions();

//Automatically add some sample vehicle into Car Rental System
void AddSampleVehicle();

//Display list info
void DisplayVehicleListInfo(const unordered_map<string, Vehicle*> &map);

void ExecuteCommand();

//Initiate the  global CarRental instance.
CarRental cr;
//Avaialbe vehicle type collection
const unordered_set<string> TYPES = { "SUV", "Sedan" };
//Availabe system commands
const unordered_set<string> COMMANDS = { "listavil", "listunavil", "add", "rmv", "rent", "return", "quit" };


int main()
{
	ShowWelcom();

	//Get command from the stdin
	char input;
	cin >> input;

	if (input == 'a')
	{
		AddSampleVehicle();
	}
	
	ExecuteCommand();

	return 0;
}

string GenerateLPlate()
{
	static int id = 0;
	return "000000" + patch::to_string(id++);
}

Vehicle* CreateVehicle(string type, bool optional)
{
	Vehicle *v = nullptr;
	if (type == "SUV")
	{
		v = new SUV();
		v->SetLicensePlate(GenerateLPlate()); //why cannot be at the bottom?
		if (optional)
		{
			v = new OptionalThirdRow(*v);
		}
	}
	else if (type == "Sedan")
	{
		v = new Sedan();
		v->SetLicensePlate(GenerateLPlate());
		if (optional)
		{
			v = new OptionalSportPackage(*v);
		}
	}
	
	return v;
}

void ShowWelcom()
{
	cout << "************Welcome to the Car Rental System*************\n\n"
		<< "Please enter 'a' to automaticlly add some sample vehicle,\n"
		<< "otherwise press any other key to add vehicle on your own\n";
}

void AddSampleVehicle()
{

	//Add 2 SUVs without optional third row into CarRental System
	for (int i = 0; i < 2; ++i)
	{
		cr.AddVehicle(*CreateVehicle("SUV", false));
	}

	//Add 2 Sedans without optional sport package into CarRental System
	for (int i = 0; i < 2; ++i)
	{
		cr.AddVehicle(*CreateVehicle("Sedan", false));
	}

	//Add 2 SUVs with optional third row into CarRental System
	for (int i = 0; i < 2; ++i)
	{
		cr.AddVehicle(*CreateVehicle("SUV", true));
	}

	//Add 2 Sedans with optional sport package into CarRental System
	for (int i = 0; i < 2; ++i)
	{
		cr.AddVehicle(*CreateVehicle("Sedan", true));
	}
}

void DisplayVehicleListInfo(const unordered_map<string,Vehicle*> &map)
{
	for (auto it : map)
	{
		cout << "--------------\n";
		cout << *it.second;
	}
}

void ShowCommandInstructions()
{
	cout << "\n*********************************************\n"
		<<"Enter following command to execute:\n"
		<< "listavil - list available vehicle to rent.\n"
		<< "listunavil - list vehicle have already been rented out.\n"
		<< "add - add new vehicle.\n"
		<< "rmv - remove an existing vehicle.\n"
		<< "rent - rent vehicle.\n"
		<< "return - return vehicle.\n"
		<< "quit - exit the system.\n"
		<< "*********************************************\n";
}

void ExecuteCommand()
{
	while (1)
	{
		ShowCommandInstructions();
		string cmd;
		cin >> cmd;
		cout << "\n";
		if (cmd == "listavil") DisplayVehicleListInfo(cr.GetAvailableVehicle());
		else if (cmd == "listunavil") DisplayVehicleListInfo(cr.GetUnavailableVehicle());
		else
		{
			if (cmd == "quit") return;			
			if (cmd == "add")
			{
				//Get the new vehicle information.
				string type, lp, optional;
				Vehicle *v = nullptr;

				cout << "please input Vehicle type(SUV or Sedan):\n";
				//create a specific type vehicle.
				cin >> type;
				while (TYPES.find(type) == TYPES.end())
				{
					cout << "Sorry," + type + " isn't supported by the current system! Please create a SUV or Sedan.\n";
					cin >> type;
				}
				if (type == "SUV")
				{
					v = new SUV();
				}
				else if (type == "Sedan")
				{
					v = new Sedan();
				}

				cout << "Please input the license plate number\n";
				cin >> lp;
				//Guarantee that the input License Plate is unique.
				if (cr.isLicensePlateDuplicate(lp))
				{
					cout << "This license plate " + lp + " has already existed. Please input a unique one.\n";
					cin >> lp;
				}
				v->SetLicensePlate(lp);

				if (type == "SUV")
				{
					cout << "Do you wanna add optional third row to this SUV?(Press Y or N)\n";
					cin >> optional;
					if (optional == "Y") v = new OptionalThirdRow(*v);
				}
				else if (type == "Sedan")
				{
					cout << "Do you wanna add optional sport package to this Sedan?(Press Y or N)\n";
					cin >> optional;
					if (optional == "Y") v = new OptionalSportPackage(*v);
				}	
				cout << "\n----------------Report---------------\n";
				//Add the new Vehicle
				if (cr.AddVehicle(*v))
				{
					cout << "This new vehicle "+ lp + " is added successfully!\n";
				}
				else
				{
					cout << "Fail to add Vehicle " + lp + "\n";
				}
			}
			else if (COMMANDS.find(cmd) == COMMANDS.end())
			{
				cout << cmd + " is not a valid command!\n";
			}
			else
			{
				cout << "please input the license plate of the vehicle you would like to operate on.\n";
			    string lp;
				cin >> lp;
				cout << "\n----------------Report---------------\n";
				if (cmd == "rmv")
				{
					if (cr.RemoveVehicle(lp))
					{
						cout << "This vehicle " + lp + " has been successfully removed!\n";
					}
					else
					{
						cout << "Failed to remove " + lp +"! Please check whether this vehicle does exsit!\n";
					}
				}
				else if (cmd == "rent")
				{
					if (cr.RentVehicle(lp))
					{
						cout << "This vehicle " + lp + " has been successfully rented!\n";
					}
					else
					{
						cout << "Failed to rent " + lp + "! Please check whether this vehicle does exsit and is avaialbe for rent!\n";
					}
				}
				else if (cmd == "return")
				{
					if (cr.ReturnVehicle(lp))
					{
						cout << "This vehicle " + lp + " has been successfully returned!\n";
					}
					else
					{
						cout << "Failed to return! " + lp + "  Please make sure this vehcile belongs to our company and has been rented!\n";
					}
				}
			}
		}

	}

}
