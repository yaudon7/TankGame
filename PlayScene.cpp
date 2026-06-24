#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
#include <iostream>

namespace {
	const int ENEMY_MAX = 10;
}

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);//親をPlaySceneにして地面を生成
	Instantiate<Tank>(this);
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		Instantiate<Enemy>(this);
	}
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
	std::cout << "SCORE:" << score_;
}

void PlayScene::Release()
{
}
