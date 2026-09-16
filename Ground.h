#pragma once
#include "Engine/GameObject.h"

class Ground :
	public GameObject
{
public:
	Ground(GameObject* parent);
	~Ground();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	int GetModelHandle() { return hModel_; }
private:
	//地面モデルのハンドル
	int hModel_;
};

