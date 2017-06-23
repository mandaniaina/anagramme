#include "stdafx.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

void ReadLinesFromFile(string const& path, vector<string>& ref_lines)
{
	ifstream flux(path);
	if (flux)
	{
		string line;
		while (getline(flux, line))
		{
			ref_lines.push_back(line);
		}
	}
	else
	{
		cout << "il y a eu une erreur lors de la lecture du fichier" << endl;
	}
}
void ReadWordsFromFile(string const& path, vector<string>& ref_Words)
{
	ifstream flux(path);
	if (flux)
	{
		string line;
		while (flux >> line)
		{
			ref_Words.push_back(line);
		}
	}
	else
	{
		cout << "il y a eu une erreur lors de la lecture du fichier" << endl;
	}
}