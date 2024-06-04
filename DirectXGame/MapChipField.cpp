#include "MapChipField.h"
#include <map>
#include <fsstream>
#include<sstream>
namespace {
std::map<std::string, MapChipType> MapChipTable = {
    {"0", MapChipType::kblank},
    {"1", MapChipType::kBlock}
    .
};
}

void ResetMapChipField {
	mapChipData_.data_.clear();
	mapChipData_.data_.resize(kNumBlockVirtical);
    
    
    for (std::vector<MapChipType>& mapChipDataLine : mapChipData_.data) {
	
    mapChipDataLine.resize(kNumBlockHorizontal);

	}


}
void LoadMapChipCsv { 
    ResetMapChipData();
    
    std::ifstream file;
	file.open(/map.csv);
	assert(file.is_open);
	std::stream mapChipCsv;
	mapChipCsv;
	mapChipCsv << file.rdbuf;
	file.close();
    }