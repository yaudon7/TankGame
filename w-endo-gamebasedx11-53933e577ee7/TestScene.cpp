#include "TestScene.h"
#include "Engine/Image.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"),hTitlePic_(-1)
{
}

//初期化
void TestScene::Initialize()
{
	hTitlePic_ = Image::Load("Title2.png");
	assert(hTitlePic_ >= 0);
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
	transform_.scale_ = { 1.5f,1.5f,1.0f };//画像の大きさを変更
	Image::SetTransform(hTitlePic_, transform_);//画像の位置や向きなどを設定
	Image::Draw(hTitlePic_);//画像を表示
}

//開放
void TestScene::Release()
{
}
