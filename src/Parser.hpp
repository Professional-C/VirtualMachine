#pragma once
#include <string>
#include <vector>
#include <tuple>

inline std::vector<std::string> Split(const std::string& str)
{
	const char delim = ',';
	std::vector<std::string> retVal;

	size_t start = 0;
	size_t delimLoc = str.find_first_of(delim, start);
	while (delimLoc != std::string::npos)
	{
		retVal.emplace_back(str.substr(start, delimLoc - start));

		start = delimLoc + 1;
		delimLoc = str.find_first_of(delim, start);
	}

	retVal.emplace_back(str.substr(start));
	return retVal;
}

// TODO: ParseStr template metaprogram