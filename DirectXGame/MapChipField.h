#include<vector>
#include<iostream>
enum class MapChipType {
		kBlank,
		kBlock,
	};
	struct MapChipData {
		std::vector<std::vector<MapChipType>> data;

		void ResetMapChipData();
		void LoadMapChipCsv(const std::string& filepath);
	}M;
    class MapChipField {

	    // １ブロックのサイズ
	    static inline const float kBlockWidth = 1.0f;
	    static inline const float kBlockHeight = 1.0f;
	    // ブロックの個数
	    static inline const uint32_t kNumBlockVirtical = 20;
	    static inline const uint32_t kNumBlockHorizontal = 100;
	    MapChipData mapChipData_;

    };
   /* MapChipType GetMapChipTypeByindex(uint32_t xindex, uint32_t yindex);
    MapChipType GetMapChipPositionByindex(uint32_t xindex, uint32_t yindex);*/

