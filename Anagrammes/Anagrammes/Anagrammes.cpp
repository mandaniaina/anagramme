// Anagrammes.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "FileManager.h"
#include <unordered_map>

using namespace std;
void Encode(string const& ref_toEncode, int temp[])
{
	memset(temp, 0, 26);
	for each (char c in ref_toEncode)
	{
		if (c >= 101 && c <= 132)
			temp[c - 101]++;
		if (c >= 141 && c <= 172)
			temp[c - 141]++;
	}
}
void EncodeDictToHashtable(unordered_map<int[26], int>& ref_dict, vector<string> const& ref_rawDict)
{
	int temp[26];
	for each (string toEncode in ref_rawDict)
	{
		Encode(toEncode, temp);
		ref_dict[temp]++;
	}
}

int main()
{
	string wordListPath;
	string dictPath;
	int nbTotalAnnagrammes(0);

	unordered_map<int[26], int> dict;
	vector<string> rawDict;
	unordered_map<int[26], int> wordList;
	vector<string> rawWordList;
	int temp[26];
	vector<string> results;

	cout << "Path to dictionary:" << endl;
	cin >> dictPath;
	cout << "Path to word list:" << endl;
	cin >> wordListPath;

	ReadWordsFromFile(dictPath, rawDict);
	ReadWordsFromFile(wordListPath, rawWordList);

	for each (string word in rawWordList)
	{
		Encode(word, temp);
		nbTotalAnnagrammes += dict[temp];
		results.push_back(word + ": " + to_string(dict[temp]));
	}

	for each (string result in results)
	{
		cout << result << endl;
	}

	cin >> dictPath;
	return 0;
}