#include<algorithm>

#include "MyMath.h"
#include "CameraController.h"

void CameraController::Initialize() { viewProjection_.Initialize; };
void CameraController::Update() {const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
const Vector3& targetVelosity = target_->GetVelosity();
destination_= targetWorldTransform.translation_+targetVelosity*kVelosityBias+targetoffset;
viewProjection_.translation_ = Lerp(viewProjection_.translation_, goalTarget, kintpolationRate);
viewProjection_.translation_.x=std::clamp(
	viewProjection_.translation_.x,
	targetWorldTransform.translation_.x,+targetMargin.left,
	targetWorldTransform.translation_.x+targetMargin.right);
viewProjection_.translation_.y = std::clamp(
	viewProjection_.translation_.y,
	targetWorldTransform.translation_.y + targetMargin.bottom,
	targetWorldTransform.translation_.y + targetMargin.top);

viewProjection_.translation_.x = std::clamp(viewProjection_.translation_.x,movableAria_.left,movableAria_.right);
viewProjection_.translation_.y = std::clamp(viewProjection_.translation_.y,movableAria_.bottom,movableAria_.top);

viewProjection_.UpdateMatrix();


}
void CameraController::Reset() {
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	viewProjection_.translation_ = targetWorldTransform.translation_ + targetoffset;

}