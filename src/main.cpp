#include <Arduino.h>
#include <M5Stack.h>
#define LOAD_FONT4

void showText()
{
	// 色の指定
	// M5Stackは、Rが5bit、Gが6ビット、Bが5ビットの16ビットなんだって
	// なので、普通のRGB それぞれが8ビットで考えるきの変換式は
	int R = 255;
	int G = 255;
	int B = 255;
	int RGB565 = ((R>>3)<<11) || ((G>>2)<<5) || ((B>>3));

	// 文字列を画面中央に配置
	int32_t dX = 160;
	int32_t poY = 120;

	// 0~8 をとる。していなければ０で一番小さいフォント
	// ただし、７はセブンセグメント風フォントで数字だけとなる
	uint8_t fontNo = 4;

	// 画面中央に文字を置く
	M5.Lcd.drawCentreString("0123456789", dX, poY, fontNo);

	dX = 300;
	poY = 146;
	fontNo = 7;
	M5.Lcd.drawCentreString("0123456789", dX, poY, fontNo);

}

void setup() {
	// put your setup code here, to run once:

	// M5Stackの初期化
	M5.begin();

	// LCDの明るさを変更
	M5.Lcd.setBrightness(128);

	// ディスプレイに表示
	M5.Lcd.print("Hello world!");

	M5.Lcd.fillRect(100,100,50,60,TFT_GREEN);

	// シリアルを使った print デバッグ
	Serial.println("done.");

	// 色、位置を指定した文字表示
	showText();
}

void loop() {
	// put your main code here, to run repeatedly:
}