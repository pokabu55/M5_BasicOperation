#include "imageshow.hpp"

ImageShow::ImageShow()
{
    showNo_ = 1;
    imageNum_ = 5;
}

void ImageShow::show()
{
    // 画像番号んインクリメント
    showNo_++;
    if (showNo_ >= imageNum_) showNo_ = 0;

    String fileName = "";
    M5.Lcd.fillScreen(BLACK);
    switch(showNo_) {
        case 0:
            fileName = "/umi.jpg";
            break;
        case 1:
            fileName = "/train.jpg";
            break;
        case 2:
            fileName = "/train2.jpg";
            break;
        case 3:
            fileName = "/pict.jpg";
            break;
        case 4:
            fileName = "/hills.jpg";
            break;
        default:
            fileName = "";
    }

    Serial.println(fileName.c_str());

    if (fileName != "") {
    	M5.Lcd.drawJpgFile(SD, fileName.c_str(), 0, 0);
    }
}

ImageShow imageShow;