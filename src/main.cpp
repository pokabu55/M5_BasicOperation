#include <Arduino.h>
#include <M5Stack.h>
#define LOAD_FONT4
#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240

// 画像表示クラス
#include "imageshow.hpp"

void showText()
{
	// ディスプレイに表示
	M5.Lcd.print("Hello world!");

	// 四角形の描画
	M5.Lcd.fillRect(100,100,50,60,TFT_GREEN);

	// 文字列を画面中央に配置
	int32_t dX = 160;
	int32_t poY = 120;

	// 0~8 をとる。していなければ０で一番小さいフォント
	// 使える番号は、０，２，４，６，８と
	// ただし、７はセブンセグメント風フォントで数字だけとなる
	uint8_t fontNo = 4;

	// 画面中央に文字を置く
	M5.Lcd.drawCentreString("0123456789", dX, poY, fontNo);

	// 試して分かったけど、dX は、値を変えても表示位置は変わらなかった
	// これ、ダミー変数だった
	dX = 300;
	poY = 146;
	fontNo = 7;
	M5.Lcd.drawCentreString("0123456789", dX, poY, fontNo);

}

void showText2()
{
	// フォントサイズを決める
	uint8_t fontSize = 2;
	M5.Lcd.setTextSize(fontSize);
	
	Serial1.printf("%d",RGB565);

}

void showImage()
{
	M5.Lcd.drawJpgFile(SD, "/umi.jpg", 0, 0);
}

void setup() {
	// put your setup code here, to run once:

	// M5Stackの初期化
	M5.begin();

	// LCDの明るさを変更
	M5.Lcd.setBrightness(128);

	// シリアルを使った print デバッグ
	Serial.println("done.");

	// メッセージ
	M5.Lcd.drawCentreString("Press any key.", 160, 120, 4);
}

void loop() {
	// put your main code here, to run repeatedly:

	if (M5.BtnA.wasPressed()) {
		// ボタンAを押したときの振る舞い
	}
	if (M5.BtnB.wasPressed()) {
		// ボタンBを押したときの振る舞い
	}
	if (M5.BtnC.wasPressed()) {
		// ボタンCを押したときの振る舞い
	}

	// ボタンが押されたかを確認するため
	M5.update();
}