#pragma once
#include "Engine/GameObject.h"

class TankBullet :
    public GameObject
{
public:
	TankBullet(GameObject* parent);
	~TankBullet() {}
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void SetMoveVector(XMFLOAT3 move) { move_ = move; }
private:
	XMFLOAT3 move_;;//弾の進行方向
	int hModel_;//タンクモデルのハンドル
};

