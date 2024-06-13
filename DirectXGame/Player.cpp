#include<cassert>
#include<numbers>
#include"Player.h"

//uint32_t textureHandle 
void Player::Initialize(Model* model,ViewProjection *viewprojection,const Vector3& position) {
	assert(model); // assert(model)ではなくassert(model)が入っていた
	model_ = model;
	//textureHandle_ = textureHandle;
	worldTransform_.Initialize(); // そもそもworldTransform.Initializeが抜けていた
	viewProjection_ = viewprojection;
	worldTransform_. translation_ = position;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;


}

void Player::Update() { 
	if (Input::GetInstance()->PushKey(DIK_RIGHT) || Input::GetInstance()->PushKey(DIK_LEFT)) {
		worldTransform_.translation_.x += verosity_.x;
		worldTransform_.translation_.y += verosity_.y;
		worldTransform_.translation_.z += verosity_.z;
		worldTransform_.TransferMatrix();
	}

}
void Player::Draw() { 
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);

}