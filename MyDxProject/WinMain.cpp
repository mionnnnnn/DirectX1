#include"DxLib.h"
#include"SceneManager.h"
#include "Logo.h"

//�v���O������WinMain����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow) {
	
	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(true);
	//��ʉ𑜓x��ύX
	SetGraphMode(640, 480, 16);
	//����if���͐�Ώ����I
	//DX���C�u��������������
	if (DxLib_Init() == -1)
		//�G���[���N�����璼���ɏI��
		return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	//1212�ǉ�
	SceneManager::GetInstance()->LoadScene(new Logo());
	SceneManager::GetInstance()->Update();

	/*
	//1212�폜
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
	*/

	//DX���C�u�����g�p�̏I������
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}