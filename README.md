# M5_BasicOperation
M5Stackでの基本動作のテスト用リポジトリ

## 開発環境
* Ubuntu 20.04 LTS
* VS Code
* 拡張機能：PlatformIO IDE

## 前準備
### USBドライバーの設定
* したはずだが…。覚えてない。適当にググってね。

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

### LCDの基礎
* [公式のリンク](https://docs.m5stack.com/#/ja/api/lcd)にあります。

