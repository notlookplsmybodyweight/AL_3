#include "MapChipField.h"
#include <assert.h>
#include <fstream>
#include <map>
#include <sstream>
#include"Vector3.h"
namespace {
std::map<std::string, MapChipType> MapChipTable = {
    {"0", MapChipType::kBlank},
    {"1", MapChipType::kBlock},
};
}

void MapChipField::ResetMapChipData() {
	mapChipData_.data.clear();
	mapChipData_.data.resize(kNumBlockVirtical);

	for (std::vector<MapChipType>& mapChipDataLine : mapChipData_.data) {

		mapChipDataLine.resize(kNumBlockHorizontal);
	}
}
void LoadMapChipCsv() {
	ResetMapChipData();

	std::ifstream file;
	file.open("map.csv");
	assert(file.is_open);
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
			if (mapChipTable.contains(word)) {
				mapChipData_.data[i][j] = mapChipTable[word];
			}
		}
	}
}

 MapChipType GetMapChipTypeByindex(uint32_t xindex, uint32_t yindex) {

	return MapChipData_.data[yindex][xindex];
 };
 MapChipType GetMapChipPositionByindex(uint32_t xindex, uint32_t yindex) {
	return Vector3(kBlockWidth*xindex,kBlockHeight)
 };
