#include <Arduino.h>
#include <M5Stack.h>
#define LOAD_FONT4
#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240

// 画像表示クラス
#include "imageshow.hpp"

// MPU関係
#include "utility/MPU9250.h"
// MPU9250（9軸センサ）のオブジェクト
MPU9250 IMU;
bool initShow = true;
int32_t directionNo = -1;
int32_t oldDirNo = 0;

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


int32_t getDirectionNo(float fx, float fy) {

	// 向きを判定
	if (abs(fx) > 0.5) {
		if (fx < 0.f)
			return 2;
		else
			return 3;
	}
	if (abs(fy) > 0.5) {
		if (fy < 0.f)
			return 4;
		else
			return 1;
	}

	// 当てはまらない
	return -1;
}


void setup() {
	// put your setup code here, to run once:

	// M5Stackの初期化
	M5.begin();

	// LCDの明るさを変更
	M5.Lcd.setBrightness(128);

	// シリアルを使った print デバッグ
	//Serial.println("done.");

	// 色、位置を指定した文字表示
	//showText();
	//showText2();

	// 画像を表示
	//showImage();

	// メッセージ
	M5.Lcd.drawCentreString("Press any key.", 160, 120, 4);

	// 乱数の初期化
	//randomSeed(analogRead(0));

	// MPUに必要な初期化
	{
		// I2C初期化
		Wire.begin();
		// MPU9250初期化
		IMU.initMPU9250();
	}
}

void loop() {
	// put your main code here, to run repeatedly:

	/*long x = random(0, DISPLAY_WIDTH);
	long y = random(0, DISPLAY_HEIGHT);
	long r = random(0, 200);*/
	float fx,fy, fz;
	String msg;

#if 0
	if (M5.BtnA.wasPressed()) {
		// ボタンAを押したときの振る舞い
		//M5.Lcd.drawRect(x-r, y-r, x+r, y+r, TFT_BLUE);

		// 画像送り機能
		imageShow.moveNextImage();

		// ボタンを押したら画像を表示
		imageShow.show();

	}
	if (M5.BtnB.wasPressed()) {
		// ボタンBを押したときの振る舞い
		//M5.Lcd.drawCircle(x, y, r, TFT_RED);

		Serial.println("BtnB Pressed-1.");
		// 明るくする
		imageShow.brighten();

		Serial.println("BtnB Pressed-2.");
		Serial.printf("ratio = %d\n", imageShow.brightnessRatio_);

		// ボタンを押したら画像を表示
		imageShow.show();

		Serial.println("BtnB Pressed-3.");
	}
	if (M5.BtnC.wasPressed()) {
		// ボタンCを押したときの振る舞い
		//M5.Lcd.fillScreen(BLACK);

		Serial.println("BtnC Pressed.");

		// 暗くする
		imageShow.darken();

		Serial1.printf("ratio = %d\n", imageShow.brightnessRatio_);

		// ボタンを押したら画像を表示
		imageShow.show();
	}

	// ボタンが押されたかを確認するため
	M5.update();
#endif

#if 0
	{
		// 9軸センサの読み取りまで待つ
		if  (IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {
			msg = "-";

			// 加速度の取得
			IMU.readAccelData(IMU.accelCount);

			// aResの値を撮る
			IMU.getAres();
			fx = IMU.accelCount[0] * IMU.aRes;
			fy = IMU.accelCount[1] * IMU.aRes;
			fz = IMU.accelCount[2] * IMU.aRes;

			Serial.printf("(%f, %f, %f\n", fx, fy, fz);

			// 向きを判定
			if (abs(fx) > 0.5) {
				msg  = (fx < 0.f) ? "RIGHT":"LEFT";
			}
			if (abs(fy) > 0.5) {
				msg  = (fy < 0.f) ? "BACK":"FRONT";
			}
			if (abs(fz) > 0.5) {
				msg  = (fz < 0.f) ? "DOWN":"UP";
			}

			M5.Lcd.clear();

			M5.Lcd.drawCentreString(msg, 160, 120, 4);

			// すぐの更新は意味がないので
			delay(500);
		}

	}
#endif

	{
		// 9軸センサの読み取りまで待つ
		if  (IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {

			// 加速度の取得
			IMU.readAccelData(IMU.accelCount);

			// aResの値を取る
			IMU.getAres();
			fx = IMU.accelCount[0] * IMU.aRes;
			fy = IMU.accelCount[1] * IMU.aRes;
			fz = fabs(IMU.accelCount[2] * IMU.aRes);

			Serial.printf("(%f, %f, %f\n", fx, fy, fz);

			if (fz > 0.5) {
				// 画面OFF
				imageShow.hidden();
				initShow = true;
			}
			else {
				// 初期の向きを取る
				directionNo = getDirectionNo(fx, fy);

				Serial.printf("dirNo = %d\n", directionNo);

				if (initShow) {
					// 画面ON
					imageShow.setNextImage(directionNo-1);
					imageShow.show();
					initShow = false;

					oldDirNo = directionNo;
				}
				else {
					// 前の向きと違う
					if (oldDirNo != directionNo) {

						// 画像番号をインクリメント
						//imageShow.moveNextImage();
						imageShow.setNextImage(directionNo-1);

						// 表示
						imageShow.show();
						oldDirNo = directionNo;
					}
				}
			}


			// すぐの更新は意味がないので
			delay(500);
		}
	}

}