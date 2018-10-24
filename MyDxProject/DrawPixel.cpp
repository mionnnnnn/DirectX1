#include"DxLib.h"
#include"FPS.h"
#include"GameMain.h"

//�v���O������WinMain����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow) {
	
	GameMain gamemain;
	FPS fps;

	ChangeWindowMode(true);//�E�B���h�E���[�h�ɕύX
	SetGraphMode(640, 480, 16);//��ʉ𑜓x��ύX
	//����if���͐�Ώ����I
	if (DxLib_Init() == -1)//DX���C�u��������������
		return -1;//�G���[���N�����璼���ɏI��

	SetDrawScreen(DX_SCREEN_BACK);
	gamemain.Initialize();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//��ʏ�����
		gamemain.MainLoop();

		//fps�֌W
		fps.Update();
		fps.Draw();
		ScreenFlip();//����ʂ̓��e��\��ʂɔ��f������
		fps.Wait();
	}

	//WaitKey();//�L�[���͑҂�

	gamemain.Release();
	DxLib_End();//DX���C�u�����g�p�̏I������

	return 0;//�\�t�g�̏I��
}
