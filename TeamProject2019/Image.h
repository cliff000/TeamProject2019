#pragma once
#include <map>
#include <string>

class Image
{
protected:
	static std::map<std::string, int> imgMap;

public:
	Image(){}
	~Image();

	static int read(const char* imgPass);
	static void clear();
};

