#include "GameScene.h"
#include "TextureManager.h"
#include "WorldTransform.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() { delete player_,
delete model_,
delete modelBlock_,
delete debugCamera_;
	for (WorldTransform* worldTrandformBlock: worldTransformBlocks_) {
		delete worldTrandformBlock;
		worldTransformBlocks_.clear();
		
	}
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	textureHandle_ = TextureManager::Load("mario.jpg");
    model_ =  Model::Create();
	modelBlock_ = Model::Create();
	worldTransform_.Initialize();
	viewProjection_.Initialize();
	player_ = new Player();
	player_ ->Initialize(model_,textureHandle_,&viewProjection_);




}

void GameScene::Update() {
	player_->Update(); 
//ブロックの更新
	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
	
		worldTransformBlock->matWorld_ = MakeAffineMatrix(worldTransformBlock->scale_,worldTransformBlock->rotation_,worldTransformBlock->translation_);
		
		
		worldTransformBlock->TransferMatrix();




	}



}

void GameScene::Draw() {


	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	//player_->Draw();
	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
		modelBlock_->Draw(*worldTransformBlock, viewProjection_);
	}
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

}
