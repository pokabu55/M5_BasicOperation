#include "imageshow.hpp"

// コンストラクタ
ImageShow::ImageShow() {
    showNo_ = 0;
    imageNum_ = 4;

    brightnessRatio_ = 50;
    brightStep_ = 10;

    showStatus_ = false;
}

// 表示する画像を次の画像にセットする
void ImageShow::moveNextImage() {
    
    // 画像番号んインクリメント
    showNo_++;
    if (showNo_ >= imageNum_) showNo_ = 0;

    // 更新するので下ろす
    showStatus_ = false;
}

void ImageShow::setNextImage(int imageNo) {
    
    // 画像番号んインクリメント
    showNo_ = imageNo;

    // 更新するので下ろす
    showStatus_ = false;
}

// 画像の表示
void ImageShow::show() {
    String fileName = "";

    if (showStatus_) return;

    // 1枚だけ、サイズが小さいのが含まれたので、一旦真っ黒にします。
    M5.Lcd.fillScreen(BLACK);

    // 番号に応じたサンプル画像を選ぶ
    // やり方、かっこよくないが…
    switch(showNo_) {
        case 0:
            fileName = "/umi.jpg";
            break;
        case 1:
            fileName = "/train.jpg";
            //fileName = "/hilss+270+cut.jpg";
            break;
        case 2:
            //fileName = "/train2.jpg";
            fileName = "/hills.jpg";
            //fileName = "/tokyo+90+cut.jpg";
            break;
        case 3:
            fileName = "/pict.jpg";
            //fileName = "/train+180.jpg";
            break;
        /*case 4:
            fileName = "/hills.jpg";
            break;*/
        default:
            fileName = "";
    }

    // 明るさをセット
    setBrightness();

    Serial.println(fileName.c_str());

    // ファイル名が取得できたら、表示します。
    if (fileName != "") {
    	M5.Lcd.drawJpgFile(SD, fileName.c_str(), 0, 0, 320, 240);
        showStatus_ = true;
    }
}

void ImageShow::hidden() {
    // クリア
	M5.Lcd.clear();
    showStatus_ = false;
}

// 明るさを取得して、セットする
void ImageShow::setBrightness() {

    uint8_t brit = (int)(255 * (double)brightnessRatio_/100. + 0.5);

    M5.Lcd.setBrightness(brit);
}

// 明るくする
void ImageShow::brighten() {

    brightnessRatio_ += brightStep_;
    if (brightnessRatio_ >= 100) brightnessRatio_ = 100;

    setBrightness();
}

// 暗くする
void ImageShow::darken() {

    brightnessRatio_ -= brightStep_;
    if (brightnessRatio_ <= 0) brightnessRatio_ = 0;

    setBrightness();
}

// クラスのオブジェクト
ImageShow imageShow;