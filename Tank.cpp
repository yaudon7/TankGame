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
}

void Tank::Update()
{
	float dt = 1.0f / 60.0f;

	//回転
	if (Input::IsKey(DIK_RIGHT)) {
		transform_.rotate_.y += 1.0f;
	}
	if (Input::IsKey(DIK_LEFT)) {
		transform_.rotate_.y -= 1.0f;
	}
	//移動
	if (Input::IsKey(DIK_W)) {
		transform_.position_.z += 1.0f * dt ;
	}
	if (Input::IsKey(DIK_A)) {
		transform_.position_.x -= 1.0f * dt;
	}
	if (Input::IsKey(DIK_S)) {
		transform_.position_.z -= 1.0f * dt;
	}
	if (Input::IsKey(DIK_D)) {
		transform_.position_.x += 1.0f * dt;
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
