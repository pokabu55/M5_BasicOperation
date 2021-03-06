# M5_BasicOperation
M5Stackでの基本動作のテスト用リポジトリ

## 開発環境
* Ubuntu 20.04 LTS
* VS Code
* 拡張機能：PlatformIO IDE

## 前準備
### USBドライバーの設定
* したはずだが…。覚えてない。適当にググってね。
* これいらない？

### PlatformIO にてプロジェクトを追加
* 任意のディレクトリにプロジェクトを作成
* プロジェウト作成後、基本となる M5Stack ライブラリを追加
* PIOのライブラリタブで、`M5Stack` を検索する
* `M5Stack by Zibin` というやつね
* Add to project で、所望のプロジェクトに追加する

## 基本操作
### プログラミング
* main.cpp にある2つの関数に機能を追記する
* setup()関数
  * 起動時に一度だけ呼ばれる関数
* loop()関数
  * setup()関数の実行後に繰り返し呼ばれる関数

### ビルドと転送
* VSCode で、PIOを入れれば、VSCodeのウィンドウ左下にあるボタンで操作可能
* チェックマークを押すとビルドされる
* 右矢印を押すと、USB接続されたM5Stackに転送され、自動実行される

* 転送にエラーが出た場合、エラーメッセージに従って下記のサイトにアクセス
* [ここ](https://docs.platformio.org/en/latest/faq.html#platformio-udev-rules)
* 指示通りに端末で下記の操作を実施
```
# Recommended
curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/master/scripts/99-platformio-udev.rules | sudo tee /etc/udev/rules.d/99-platformio-udev.rules

sudo service udev restart

sudo usermod -a -G dialout $USER
sudo usermod -a -G plugdev $USER
```
* 再起動後、転送できるようになりました

### シリアルによるprintデバッグ
* platformio.ini に `monitor_speed = 115200` と追記
* IDEで自動記載する方法があるがわからん
* 下記のように、コーディング
```
    Serial.print(”done.”);
```
* VSCode の左下のボタンの並びにプラグマークがあるので、本体実行後にクリック
* VSCode のターミナルに表示される

### 9軸センサの使い方
* main.cpp に以下のようにインクルード
```
  #include "utility/MPU9250.h"
```
* センサのオブジェクトを記述
```
  MPU9250 IMU;
```
* これだけで、使えるようになった

### 本家の参考サイト
* [github](https://github.com/m5stack/M5Core2)
* [LCDのAPI](https://docs.m5stack.com/#/ja/api/lcd)にあります。
* [API](https://docs.m5stack.com/#/ja/api)

