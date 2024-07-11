
#include<assert.h>
#include <cassert>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include "MapChipField.h"

    namespace {
	std::map<std::string, MapChipType> MapChipTable = {
	    {"0", MapChipType::kBlank},
	    {"1", MapChipType::kBlock},
	};
}
uint32_t MapChipField::GetkNumBlockVirtical() { return kNumBlockVirtical; }
uint32_t MapChipField::GetkNumBlockHorizontal() { return kNumBlockHorizontal; }

void MapChipField::ResetMapChipData() {
	mapChipData_.data.clear();
	mapChipData_.data.resize(kNumBlockVirtical);

	for (std::vector<MapChipType>& mapChipDataLine : mapChipData_.data) {

		mapChipDataLine.resize(MapChipField::kNumBlockHorizontal);
	}
}
void MapChipField::LoadMapChipCsv(const std::string& filepath) {
	ResetMapChipData();

	std::ifstream file;
	file.open(filepath);
	assert(file.is_open());

	std::stringstream mapChipCsv;
	mapChipCsv << file.rdbuf();
	file.close();

	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {
		std::string line;
		getline(mapChipCsv, line);
		std::istringstream line_stream(line);
		for (uint32_t j = 0; j < kNumBlockHorizontal; ++j) {
			std::string word;
			getline(line_stream, word, ',');
			if (MapChipTable.contains(word)) {
				mapChipData_.data[i][j] = MapChipTable[word];
			}
		}
	}
}
MapChipType MapChipField::GetMapChipTypeByIndex(uint32_t xindex, uint32_t yindex) {
	if (xindex < 0 || kNumBlockHorizontal - 1 < xindex) {
		return MapChipType::kBlank;
	}
	if (yindex < 0 || kNumBlockVirtical - 1 < yindex) {
		return MapChipType::kBlank;
	}
	return mapChipData_.data[yindex][xindex];
}
Vector3 MapChipField::GetMapChipPositionTypeByIndex(uint32_t xindex, uint32_t yindex) {
	return Vector3(kBlockWidth * xindex, kBlockHeight * (kNumBlockVirtical - 1 - yindex), 0);
}
