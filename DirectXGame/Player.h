#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include"ViewProjection.h"
class Player {
public:
	Player();
	~Player();
	void initialize(Model*model_,uint32_t textuerHanndle,ViewProjection * viewprojection);
	void Update();
	void Draw(worldTransform_,*viewProjection,textureHandle_);

private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;

}