
#pragma once
// 一番上に書かない
#include <vector>
#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "MapChipField.h"
#include "Model.h"
#include "MyMath.h"
#include "Player.h"
#include "Skydome.h"
#include "CameraController.h"
#include "Sprite.h"
#include "SafeDelete.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

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
	void GenerateBlocks();
private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	//モデルデータ
	Model* model_ = nullptr;
	Model* modelBlock_ = nullptr;
	Model* modelSkydome_ = nullptr;
	Model* modelPlayer_ = nullptr;
	//自キャラ
	Player* player_ = nullptr;
	//スカイドーム
	Skydome* skydome_ = nullptr;
	//マップチップフィールド
	MapChipField* mapChipField_;
	//カメラコントローラー
	CameraController* cameraController_;
	//テクスチャー
	uint32_t textureHandle_ = 0;
	ViewProjection viewProjection_;
	WorldTransform worldTransform_;
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;
	// std::vector <std::vector<WorldTransform*>> worldTransformBlocks_;
	bool isDebugCameraActive_ = false;
	DebugCamera* debugCamera_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	
};
