// #include "MapChipField.h"
// #include "WorldTransform.h"
#include <cassert>
#include <map>
#include "MyMath.h"
#include "TextureManager.h"
#include "GameScene.h"

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete player_, delete model_, delete modelBlock_, delete debugCamera_, delete mapChipField_;
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_)
		for (WorldTransform* worldTrandformBlock : worldTransformBlockLine) {
			delete worldTrandformBlock;
		}
}
//	worldTransformBlocks_.clear();

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	textureHandle_ = TextureManager::Load("mario.jpg");
	model_ = Model::Create();
	modelBlock_ = Model::Create();
	modelSkydome_ = Model::CreateFromOBJ("sphere", true);
	worldTransform_.Initialize();
	viewProjection_.Initialize();
	player_ = new Player();
	player_->Initialize(model_, textureHandle_, &viewProjection_);
	mapChipField_ = new MapChipField;
	mapChipField_->LoadMapChipCsv("Resource/map.csv");

	//<<<<<<< Updated upstream
	//=======
	skydome_ = new Skydome();
	//<<<<<<< Updated upstream
	skydome_->Initialize(modelSkydome_, textureHandle_, &viewProjection_);

	//>>>>>>> Stashed changes

	/*const uint32_t kNumBlockHorizontal = 20;
	const uint32_t kNumBlockVirtical = 10;
	const float kBlockWidth = 2.0f;
	const float kBlockHeight = 2.0f;*/
	//=======

	/*Vector3 playerPosition_;

	playerPosition_ = mapChipField_->GetMapChipPositionTypeByIndex(20,1);
	player_->Initialize(model_, &viewProjection_, playerPosition_);*/

	//<<<<<<< Updated upstream
	//=======
	skydome_->Initialize(modelSkydome_, textureHandle_, &viewProjection_);
	//>>>>>>> Stashed changes]
	mapChipField_->LoadMapChipCsv("Resource/map.csv ");
	debugCamera_ = new DebugCamera(1280, 720);
}
void GameScene::GenerateBlocks() {
	uint32_t numBlockVirtical = mapChipField_->GetkNumBlockVirtical();
	uint32_t numBlockHorizontal = mapChipField_->GetkNumBlockHorizontal();

	worldTransformBlocks_.resize(numBlockVirtical);
	for (uint32_t i = 0; i < numBlockVirtical; ++i) {

		worldTransformBlocks_[i].resize(numBlockHorizontal);
	}
	for (uint32_t i = 0; i < numBlockVirtical; ++i) {

		for (uint32_t j = 0; j < numBlockHorizontal; ++j) {
			if (mapChipField_->GetMapChipTypeByIndex(j, i) == MapChipType::kBlock) {
				WorldTransform* worldTransform = new WorldTransform();
				worldTransform->Initialize();
				worldTransformBlocks_[i][j] = worldTransform;
				worldTransformBlocks_[i][j]->translation_ =
				    mapChipField_->GetMapChipPositionTypeByIndex(j, i);

				//} else {
				// worldTransformBlocks_[i][j] = nullptr;
			}
		}
	}
}
void GameScene::Update() {

#ifdef _DEBUG
	if (input_->TriggerKey(DIK_SPACE)) {
		if (isDebugCameraActive_ == true)
			isDebugCameraActive_ = false;
		else
			isDebugCameraActive_ = true;
	}
#endif

	if (isDebugCameraActive_) {
		// デバッグカメラの更新
		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;
		// ビュープロジェクション行列の転送
		viewProjection_.TransferMatrix();
	} else {
		// ビュープロジェクション行列の更新と転送
		viewProjection_.UpdateMatrix();
	}

	debugCamera_->Update();
	player_->Update();

	// ブロックの更新

	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {

		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			if (!worldTransformBlock)
				continue;

			worldTransformBlock->UpdetaMatrix();
		}
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
	// player_->Draw();
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {

		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			if (!worldTransformBlock)
				continue;
			modelBlock_->Draw(*worldTransformBlock, viewProjection_);
		}
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
