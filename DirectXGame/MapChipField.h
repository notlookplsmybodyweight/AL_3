#include <stdint.h>
#include <vector>
#include "Vector3.h"

enum class MapChipType {
	kBlank,
	kBlock,
};
struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};
class MapChipField {
public:
	void ResetMapChipData();
	void LoadMapChipCsv(const std::string& filepath);
	MapChipType GetMapChipTypeByIndex(uint32_t xindex, uint32_t yindex);
	Vector3 GetMapChipPositionTypeByIndex(uint32_t xindex, uint32_t yindex);
	uint32_t GetkNumBlockVirtical();
	uint32_t GetkNumBlockHorizontal();

private:
	// １ブロックのサイズ
	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;
	// ブロックの個数
	static inline const uint32_t kNumBlockVirtical = 20;
	static inline const uint32_t kNumBlockHorizontal = 100;
	MapChipData mapChipData_;
};
