#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
class Player {
public:
	// 左右
	enum class LRDirection {
		kRight,
		kLeft,
	};
	//typedef struct AABB {
	//	Vector3 min;
	//	Vector3 max;
	//	/*GetAABBはエネミーとプレイヤーに定義する
	//	IsCollision関数もつくる関数の中身retun(
	//	aabb1.min.x<=aabb2.max.x&&aabb1.max.x<=aabb2.min.x
	//	&&aabb1.min.y<=aabb2/max.y&&aabb1.min.y>=aabb2.max.y
	//	&&aabb1.min.z<=aabb2.max.z&&aabb1.max.z>aabb2.min.z);*/ 
	//    
	//};
	/// <summary>
	/// 初期化
	/// </summary>
		void Initialize(ViewProjection* viewProjection,Vector3 position);
	//void Initialize(const Vector3& position, ViewProjection* viewProjection);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	//AABB GetAABB() { WorldPos.x - kWidth / 2, WorldPos.y - kHeight / 2, worldPos.z - kWidth / 2; }

	WorldTransform& GetWorldTransform();
	const Vector3& GetVerosity();
private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;

	Vector3 velocity_ = {};

	static inline const float kAcceleration = 0.01f;
	static inline const float kAttenuation = 0.01f;
	static inline const float kLimitRunSpeed = 2.0f;

	LRDirection lrDirection_ = LRDirection::kRight;

	// 旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	// 旋回タイマー
	float turnTimer_ = 0.0f;

	// 旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;

	// 接地状態フラグ
	bool onGround_ = true;
	// 着地フラグ
	bool landing = false;

	// 重力加速度（下方向）
	static inline const float kGravityAcceleration = 0.05f;
	// 最大落下速度（下方向）
	static inline const float kLimitFallSpeed = 0.2f;
	// ジャンプ初速（上方向）
	static inline const float kJumpAcceleration = 0.7f;
};