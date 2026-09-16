#pragma once
#include "Engine/GameObject.h"

class Tank :
    public GameObject
{
public:
	Tank(GameObject* parent);
	~Tank();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void SetFixedCamera();
	void SetTPSCamera();
	void SetFPSCamera();
private:
	int hModel_;//タンクモデルのハンドル
	float speed_;//移動速度
	float rotateSpeed_;//回転速度
	int cam_type_;//カメラの種類
};

