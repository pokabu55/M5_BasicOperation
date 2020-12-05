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

	// 色の指定
	// M5Stackは、Rが5bit、Gが6ビット、Bが5ビットの16ビットなんだって
	// なので、普通のRGB それぞれが8ビットで考えるきの変換式は
	uint8_t R = 255;
	uint8_t G = 255;
	uint8_t B = 255;
	uint16_t RGB565 = ((R>>3)<<11) || ((G>>2)<<5) || ((B>>3));
	
	Serial1.printf("%d",RGB565);

	// 文字の色を設定
	M5.Lcd.setTextColor(RGB565);
	M5.Lcd.setTextColor(TFT_GREEN);

	// 出力位置
	int16_t x = 20, y = 20;
	M5.Lcd.setCursor(x,y);

	// おりかえしをON、デフォルトONなのか？
	// 折返しがないと、右へ書き続けて表示できなくなる
	M5.Lcd.setTextWrap(true);

	// 文字列
	M5.Lcd.println("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	M5.Lcd.println("012345678901234567890123456789012345678901234567890123456789");
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

	// 色、位置を指定した文字表示
	//showText();
	//showText2();

	// 画像を表示
	//showImage();

	// メッセージ
	M5.Lcd.drawCentreString("Press any key.", 160, 120, 4);

	// 乱数の初期化
	randomSeed(analogRead(0));
}

void loop() {
	// put your main code here, to run repeatedly:

	long x = random(0, DISPLAY_WIDTH);
	long y = random(0, DISPLAY_HEIGHT);
	long r = random(0, 200);

	if (M5.BtnA.wasPressed()) {
		// ボタンAを押したときの振る舞い
		//M5.Lcd.drawRect(x-r, y-r, x+r, y+r, TFT_BLUE);

		// ボタンを押したら画像を表示
		imageShow.show();

	}
	if (M5.BtnB.wasPressed()) {
		// ボタンBを押したときの振る舞い
		//M5.Lcd.drawCircle(x, y, r, TFT_RED);

		// 明るくする
	}
	if (M5.BtnC.wasPressed()) {
		// ボタンCを押したときの振る舞い
		//M5.Lcd.fillScreen(BLACK);

		// 暗くする
	}

	// ボタンが押されたかを確認するため
	M5.update();
}