#pragma once
#include "Engine//GameObject.h"
#include "TankBullet.h"
//前方宣言
class PlayScene;

class Enemy :
    public GameObject
{
public:
	Enemy(GameObject* parent);
	~Enemy() {}
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget);
private:
	int hModel_;//タンクモデルのハンドル
	TankBullet* pbullet = (TankBullet*)FindObject("TankBullet");//TankBulletのアドレスを保持する変数
	PlayScene* scene;//PlaySceneのアドレスを保持する変数
};

