#include "ViewProjection.h"
#include "Player.h"
	class Player;
class CameraController {
public:
	//カメラの動ける範囲を制限するための構造体
	struct Rect {
		float left = 0.0f;
		float right = 0.0f;
		float bottom = 0.0f;
		float top = 0.0f;
	};
	//座標保管
	static inline const float kintpolationRate = 0.5f;
	void Initialize();
	void Update();
	void SetTarget(Player* target) { target_ = target; };
	void Reset();
	Vector3 targetoffset = {0, 0, -15.0f};
	Vector3 goalTarget;
	void SetMovableArea(Rect area) { movableAria_ = area; };
	viewProjection_.translation_ =
	    Lerp(viewProjection_.translation_, goalTarget, kintpolationRate);
	//{lerp(X,X2,t){return{(1.0f-time)*X+time*X2;}
	//Lerp関数Vector3 Lerp(Vector3& v1,Vector3& v2,float t){
	//return Vector3(Lerp(V1.X,V2.X,t),Vector3(Lerp(V1.Y,V2.Y,t),Vector3(Lerp(V1.X,V2.X,t));

	private:
	ViewProjection viewProjection_;
	    Player* target_ = nullptr;
	Rect movableAria_ = {0, 100, 0, 100};




};