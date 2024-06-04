#include "Skydome.h"
void Skydome::Initialize(Model*model,ViewProjection *viewprojection) { 
	model_ = model;
	viewProjection_ = viewprojection;
	worldTransform_.Initialize();

}
void Skydome::Update() {

}
void Skydome::Draw() { 
model_->Draw(worldTransform_, *viewProjection_);

}
