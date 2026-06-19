#include "TankHead.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "TankBullet.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent, "TankHead"), hModel_(-1)
{	
}


void TankHead::Initialize()
{
	rotate_speed_ = 0.5f;
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ > 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_RIGHT))
	{
		//タンクヘッドの回転
		transform_.rotate_.y += rotate_speed_;
	}

	if (Input::IsKey(DIK_LEFT))
	{
		//タンクヘッドの回転
		transform_.rotate_.y -= rotate_speed_;
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{
		XMFLOAT3 cannonTop =  Model::GetBonePosition(hModel_, "Top");
		XMFLOAT3 cannonRoot = Model::GetBonePosition(hModel_, "Root");
		XMVECTOR top =  XMLoadFloat3(&cannonTop);
		XMVECTOR root = XMLoadFloat3(&cannonRoot);
		XMVECTOR vMove = top - root;
		XMVector3Normalize(vMove);
		const float BULLET_SPEED = 0.2f;
		vMove *= BULLET_SPEED;
		XMFLOAT3 move;
		XMStoreFloat3(&move, vMove);

		TankBullet* bullets = Instantiate<TankBullet>(GetParent()->GetParent());
		bullets->SetMoveVector(move);
		bullets->SetPosition(cannonTop);//弾の位置を砲台の先端に移動する
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
