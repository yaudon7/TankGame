#include "Enemy.h"
#include "Engine/Model.h"
#include "Ground.h"
#include <random>

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");

	static std::mt19937 mt(std::random_device{}());
	std::uniform_real_distribution<float> dist(-25.0f, 25.0f);

	transform_.position_ = { dist(mt),0,dist(mt) };
}

void Enemy::Update()
{
	//レイキャストして、浮いたら、地面まで落とす
	RayCastData data;
	data.start = transform_.position_;
	//地面はゼロより下に彫られて作られている。そうじゃないときはもっと上から
	data.start.y = 0.0f;
	//真下
	data.dir = { 0,-1,0 };
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGroundModel = 0;
	//レイキャストして、地面にあったかどうか、当たった時の距離や法線ベクトルを返す
	Model::RayCast(hGroundModel, &data);

	if (data.hit)
	{
		transform_.position_.y = -data.dist;
	}

	
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
