#include"GameMain.h"

//������
void GameMain::Initialize() {
	//�摜�ǂݍ���
	playerGraph = LoadGraph("white.png");
	_player.Start();
}
//���s
void GameMain::MainLoop() {
	_player.Update();
	_player.Draw();
	//���͏���
	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);//�L�[���͎擾
	if (key & KEY_INPUT_UP)
		playerY -= 3;
	if (key & PAD_INPUT_DOWN)
		playerY += 3;
	if (key & PAD_INPUT_RIGHT)
		playerX += 3;
	if (key & PAD_INPUT_LEFT)
		playerX -= 3;

	//DrawPixel(320, 240, GetColor(255, 255, 255));//�_��ł�
	DrawGraph(300, 200, playerGraph, TRUE);//�摜��`��
}
//���
void GameMain::Release() {

}