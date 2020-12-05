#include <Arduino.h>
#include <M5Stack.h>

void setup() {
	// put your setup code here, to run once:

	// M5Stackの初期化
	M5.begin();

	// ディスプレイに表示
	M5.Lcd.print("Hello world!");
}

void loop() {
	// put your main code here, to run repeatedly:
}