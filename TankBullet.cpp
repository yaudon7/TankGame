#include "TankBullet.h"
#include "Engine/Model.h"

TankBullet::TankBullet(GameObject* parent)
	:GameObject(parent,"TankBullet"),hModel_(-1)
{
}

void TankBullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	move_ = XMFLOAT3{ 0,0,0 };
	radius = 1.0f;
}


void TankBullet::Update()
{
	
	const float gravity = 0.01f;
	move_.y -= gravity;

	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
	XMVECTOR vMove = XMLoadFloat3(&move_);

	vPos += vMove;

	XMStoreFloat3(&transform_.position_, vPos);

	if (transform_.position_.z > 50.0f || transform_.position_.z < -50.0f ||
		transform_.position_.x > 50.0f || transform_.position_.x < -50.0f)
	{
		KillMe();
	}
}

void TankBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankBullet::Release()
{
}
