#include <Arduino.h>
#include <M5Stack.h>

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