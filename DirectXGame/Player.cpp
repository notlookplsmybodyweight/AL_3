#include"Player.h"
#include<cassert>

void Player::Initialize(Model* model,uint32_t textureHandle,ViewProjection *viewprojection) {
	assert(model); // assert(model)ではなくassert(model)が入っていた
	model_ = model;
	textureHandle_ = textureHandle;
	worldTransform_.Initialize(); // そもそもworldTransform.Initializeが抜けていた
	viewProjection_ = viewprojection;


}

void Player::Update() { 
	worldTransform_.TransferMatrix();

}
void Player::Draw() { 
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);

}