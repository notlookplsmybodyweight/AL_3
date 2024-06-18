#include "MapChipField.h"
#include <fstream>
#include <map>
#include <sstream>
#include<assert.h>
namespace {
std::map<std::string, MapChipType> MapChipTable = {
    {"0", MapChipType::kBlank},
    {"1", MapChipType::kBlock},
};
}

void ResetMapChipData() {
	mapChipData_.data_.clear();
	mapChipData_.data_.resize(kNumBlockVirtical);

	for (std::vector<MapChipType>& mapChipDataLine : mapChipData_.data) {

		mapChipDataLine.resize(kNumBlockHorizontal);
	}
}
void LoadMapChipCsv() {
	ResetMapChipData();
	

	std::ifstream file;
	file.open("map.csv");
	assert(file.is_open);
	std::istream mapChipCsv;
	mapChipCsv;
	mapChipCsv << file.rdbuf;
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