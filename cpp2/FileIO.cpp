#include "FileIO.h"
#include <iostream>
#include <unordered_map>

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

vector<string> FileIO::LoadRoles()
{
	vector<string> roles;

	string line;
	ifstream file("../Assets/roles.csv");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			roles.push_back(line);
		}
		file.close();
	}

	return roles;
}

vector<vector<string>> FileIO::LoadBuildings()
{
	vector<vector<string>> buildings;

	string line;
	ifstream file("../Assets/buildings.csv");
	if (file.is_open())
	{
		while (getline(file, line))
		{			
			buildings.push_back(ParseBuilding(line));
		}
		file.close();
	}

	return buildings;
}

vector<string> FileIO::ParseBuilding(string buildingString)
{
	vector<string> building;

	if (buildingString.find(';') != string::npos)
	{
		string segment;

		stringstream ss(buildingString);

		while (getline(ss, segment, ';'))
		{
			building.push_back(segment);
		}
	}

	return building;
}