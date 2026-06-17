#pragma once
#include "Engine/GameObject.h"
#include "Tank.h"


class TankHead :public GameObject
{
public:
	TankHead(GameObject* parent);
	~TankHead();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hModel_;//タンクモデルのハンドル
	float speed_;//移動速度
	float rotateSpeed_;//回転速度
	Tank tank = FindObject("Tank");
};

