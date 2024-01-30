#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "RapidXML-master/RapidXML-master/RapidXML/rapidxml.hpp"


struct LevelData
{
	std::string rowCount,
	columnCount,
	rowSpacing,
	columnSpacing,
	backgroundTexture;
	std::vector<LevelData> Brick_type;
};

struct BrickData
{
	std::string Id,
	Texture,
	HitPoints,
	HitSound,BreakSound,
	BreakScore;
};


class ParseData
{
public:

	LevelData parseLevel(const std::string& filename);
	LevelData leveldata;

private:

};

