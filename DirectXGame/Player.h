#include "Model.h"
#include "WorldTransform.h"

class Player{
public:
	
	
	//初期化
	void Initialize(Model *model,ViewProjection* viewProjection,const Vector3& position);
	//更新
	void Update();
	//描画
	void Draw();


private:
	Model* model_ = nullptr;
	Vector3 verosity_ = {}; 
	WorldTransform worldTransform_;
	ViewProjection* viewProjection_ = nullptr;
	uint32_t textureHandle_ = 0u;
	float turnFirstRotationY_ = 0.0f;
	float turnTimer_ = 0.0f;
	static inline const float kTimeTurn = 0.3f;
	On


	



};