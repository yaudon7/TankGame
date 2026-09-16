#pragma once
#include "Engine/GameObject.h"

class TankHead :public GameObject
{
public:
	TankHead(GameObject* parent);
	~TankHead() {}
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hModel_;//タンクモデルのハンドル
	float rotate_speed_;//headの回転速度
};

