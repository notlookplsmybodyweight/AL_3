#include"Model.h"
#include "WorldTransform.h"

class Skydome{
public:
	void Initialize(Model* model,ViewProjection* viewProjection);
	void Update();
void Draw();

private:

WorldTransform worldTransform_ ;
	ViewProjection* viewProjection_ = nullptr;
	Model* model_ = nullptr ;
};