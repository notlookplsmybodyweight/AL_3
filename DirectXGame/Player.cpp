#include<cassert>
#include<numbers>
#include<>
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
	} else if (lrDirection_!=LRDirection::kRight) {
		lrDrection_ = LRDirection::kRight;
		turnFirstRotationY_ = worldTransform_.rotation_.y;
		turnTimer_ = kTimeTurn;

	} else if (lrDirection_ != LRDirection::kLeft) {
		lrDrection_ = LRDirection::kLeft;
		turnFirstRotationY_ = worldTransform_.rotation_.y;
		turnTimer_ = kTimeTurn;
	}
		if (turnTimer_ > 0.0f) {
		turnTimer_ -= (1 / 60.0f);
		float destinationRotationYtable[] = {
		    std::numbers::pi_v<float> / 2.0f, std::numbers::pi_v<float> * 3.0f / 2.0f};
		float destinationRotationY = destinationRotationYtable[static_cast<uint32_t>(lrDirection_)];
		wolrdTransform_.rotation_.y = float Easeinout = (turnFirstRotationY_, destinationRotationY, float turnTimer) {
			return (1.0 - time) * start + end * time;
		}:


	}



}
void Player::Draw() { 
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);

}