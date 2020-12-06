#ifndef IMAGE_SHOW
#define IMAGE_SHOW

#include <M5Stack.h>
#include <string.h>

class ImageShow {
private:
    // 表示画像番号
    int32_t showNo_;
    // 表示可能枚数
    int32_t imageNum_;

    // 状態
    bool showStatus_;


public:
    ImageShow();

    void moveNextImage();
    void setNextImage(int imageNo);
    void show();
    void hidden();
    void brighten();
    void darken();
    void setBrightness();

    // 表示している画像の明るさの割合
    int32_t brightnessRatio_;
    int32_t brightStep_;

};

extern ImageShow imageShow;

#endif // IMAGE_SHOW