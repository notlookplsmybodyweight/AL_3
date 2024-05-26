#pragma once
//一番上に書かない
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h"
#include "MyMath.h"
#include"DebugCamera.h"

#include<vector>


/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	Model* model_ = nullptr;
	Model* modelBlock_ = nullptr;
	Player* player_ = nullptr;
	uint32_t textureHandle_ =0;
	ViewProjection viewProjection_;
	WorldTransform worldTransform_;
	std::vector <WorldTransform*> worldTransformBlocks_;
	//std::vector <std::vector<WorldTransform*>> worldTransformBlocks_;
	bool isDebugCameraActive = false;
	DebugCamera* debugCamera_ = nullptr;





	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
