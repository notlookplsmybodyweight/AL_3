
#include"GameScene.h"
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Matrix4x4 MakeRotateXMatrix(float radian);	

Matrix4x4 MakeRotateYMatrix(float radian);

Matrix4x4 MakeRotateZMatrix(float radian);

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
//スライド23、24座標補間（線形補間）
//{lerp(X,X2,t){return{(1.0f-time)*X+time*X2;}
// Lerp関数Vector3 Lerp(Vector3& v1,Vector3& v2,float t){
// return Vector3(Lerp(V1.X,V2.X,t),Vector3(Lerp(V1.Y,V2.Y,t),Vector3(Lerp(V1.X,V2.X,t));
