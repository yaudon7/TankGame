#pragma once
#include "Engine/GameObject.h"
class Tank :
    public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Tank(GameObject* parent);
	~Tank();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
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

