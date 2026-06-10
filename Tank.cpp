#include "Tank.h"
#include "Engine//Model.h"
#include "Engine/Input.h"
#include "Engine//Debug.h"	
#include "Ground.h"
namespace
{
	XMVECTOR vFront = { 0,0,1,0 };//前方向ベクトル
	enum CAM_TYPE
	{
		FIXED_CAM,//固定カメラ
		TPS_CAM,//三人称
		TPS_CAMROT,//回転付き三人称
		FPS_CAM,//一人称　
		CAM_TYPE_MAX
	};
}
//タンクのボディを表すクラス
Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),hModel_(-1),cam_type_(FIXED_CAM)
{
	hModel_ = Model::Load("Tankbody.fbx");
	assert(hModel_ > 0);
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	speed_ = 1.0f;
	rotateSpeed_ = 1.0f;
}

void Tank::Update()
{
	if (Input::IsKeyDown(DIK_C))
	{
		cam_type_ = (cam_type_ + 1) % CAM_TYPE_MAX;
	}
	switch (cam_type_)
	{
	case FIXED_CAM:
		//固定カメラの処理
		break;
	case TPS_CAM:
		//TPSカメラの処理
		break;
	case TPS_CAMROT:
		break;
	case FPS_CAM:
		break;
	}

	float dt = 1.0f / 60.0f;

	//移動ベクトルの計算
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
	//Y軸回転行列を作る
	XMMATRIX matRot = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//ベクトルを行列で変換する関数
	XMVECTOR vMove = XMVector3TransformCoord(vFront, matRot);
	Debug::Log("CAMTYPE = ");
	//後ろは改行するかどうか
	Debug::Log(cam_type_, true);

	//wキーを押している間前に進む
	if (Input::IsKey(DIK_W)) {
		vPos += vMove * speed_ * dt;
		//位置を書き込み
		XMStoreFloat3(&transform_.position_, vPos);
	}

	//回転
	if (Input::IsKey(DIK_A)) {
		transform_.rotate_.y -= rotateSpeed_;
	}
	if (Input::IsKey(DIK_D)) {
		transform_.rotate_.y += rotateSpeed_;
	}

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
		transform_.position_.y =  - data.dist;
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
