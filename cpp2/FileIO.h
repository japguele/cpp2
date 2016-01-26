#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

class FileIO
{
public:
	FileIO();
	~FileIO();

	vector<string> LoadRoles();
	vector<vector<string>> LoadBuildings();

private:
	vector<string> ParseBuilding(string buildingString);
};

