#include<cassert>
#include"Player.h"

void Player::Initialize(Model* model,uint32_t textureHandle,ViewProjection *viewprojection) {
	// assert(model)ではなくassert(model)が入っていた
	assert(model); 
	model_ = model;
	textureHandle_ = textureHandle;
	// そもそもworldTransform.Initializeが抜けていた
	worldTransform_.Initialize();
	viewProjection_ = viewprojection;


}

void Player::Update() { 
	worldTransform_.TransferMatrix();

}
void Player::Draw() { 
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);

}