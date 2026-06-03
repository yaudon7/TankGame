#include "Tank.h"
#include "Engine//Model.h"
#include "Engine/Input.h"
Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),hModel_(-1)
{
	hModel_ = Model::Load("Tankbody.fbx");
	assert(hModel_ > 0);
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	speed_ = 0.1f;
	rotateSpeed_ = 0.1f;
}

void Tank::Update()
{
	float dt = 1.0f / 60.0f;
	//移動ベクトルの計算
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
	//前方向に移動するベクトルを作る
	XMVECTOR vMove = { 0.0f,0.0f,speed_,0.0f };
	//回転行列を作る
	XMMATRIX mRotY = XMMatrixRotationY(transform_.rotate_.y);
	//回転行列を移動ベクトルにかける
	vMove = XMVector3TransformCoord(vMove, mRotY);

	//回転
	if (Input::IsKey(DIK_A)) {
		transform_.rotate_.y += rotateSpeed_;
	}
	if (Input::IsKey(DIK_D)) {
		transform_.rotate_.y -= rotateSpeed_;
	}
	//移動
	if (Input::IsKey(DIK_W)) {
		vPos += vMove * dt;
		XMStoreFloat3(&transform_.position_, vPos);
	}
	/*if (Input::IsKey(DIK_A)) {
		transform_.position_.x -= 1.0f * dt;
	}
	if (Input::IsKey(DIK_S)) {
		transform_.position_.z -= 1.0f * dt;
	}
	if (Input::IsKey(DIK_D)) {
		transform_.position_.x += 1.0f * dt;
	}*/
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
