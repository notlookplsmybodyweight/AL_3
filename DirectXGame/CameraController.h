#include"Player.h"
#include"ViewProjection.h"
class Player;class CameraController {
public:
	// カメラの動ける範囲を制限するための構造体
	struct Rect {
		float left = 0.0f;
		float right = 0.0f;
		float bottom = 0.0f;
		float top = 0.0f;
	};
	void Initialize();
	void Update();
	//セッター
	void SetTarget(Player* target) { target_ = target; };
	void Reset();
	void SetMovableArea(Rect area) { movableAria_ = area; };
	Vector3 goalTarget;

	
	//{lerp(X,X2,t){return{(1.0f-time)*X+time*X2;}
	// Lerp関数Vector3 Lerp(Vector3& v1,Vector3& v2,float t){
	// return Vector3(Lerp(V1.X,V2.X,t),Vector3(Lerp(V1.Y,V2.Y,t),Vector3(Lerp(V1.X,V2.X,t));
	//ゲッター
const ViewProjection& GetViewProjcetion()const {return viewProjection_;};
private:
	Vector3 targetoffset = {0, 0, -15.0f};
	ViewProjection viewProjection_;
	Player* target_ = nullptr;
	Rect movableAria_ = {0, 100, 0, 100};
	static inline const Rect targetMargin = {-9.0f,9.0f,-5.0f,5.0f};
	// 座標保管
	static inline const float kintpolationRate = 0.5f;
	static inline const float kVelosityBias = 30.0f;
};