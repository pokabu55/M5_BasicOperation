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

public:
    ImageShow();

    void show();

};

extern ImageShow imageShow;

#endif // IMAGE_SHOW