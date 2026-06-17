#include "TankHead.h"
#include "Engine/Model.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent, "TankHead"), hModel_(-1)
{
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ > 0);
}
TankHead::~TankHead()
{
}

void TankHead::Initialize()
{;
}

void TankHead::Update()
{
	XMFLOAT3 TankPos = tank.GetPosition();
	transform_.position_ = TankPos;
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
