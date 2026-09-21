# CPP Modules

42 Tokyo の C++ カリキュラムで作成した課題です。C++98を使用し、クラス、継承、多態性、抽象クラスなど、オブジェクト指向プログラミングの基礎を段階的に学習します。

## Modules

### CPP Module 00

C++の基本構文、標準入出力、クラス、カプセル化を扱います。

- `ex00`: Megaphone
- `ex01`: My Awesome PhoneBook

### CPP Module 01

メモリ確保、ポインタ、参照、メンバ関数へのポインタを扱います。

- `ex00`: BraiiiiiiinnnzzzZ
- `ex01`: Moar brainz!
- `ex02`: HI THIS IS BRAIN
- `ex03`: Unnecessary violence
- `ex04`: Sed is for losers
- `ex05`: Harl 2.0
- `ex06`: Harl filter

### CPP Module 02

Orthodox Canonical Form、演算子オーバーロード、固定小数点数を扱います。

- `ex00`: My First Class in Orthodox Canonical Form
- `ex01`: Towards a more useful fixed-point number class
- `ex02`: Now we're talking

### CPP Module 03

継承、多重継承、仮想継承を扱います。

- `ex00`: Aaaaand... OPEN!
- `ex01`: Serena, my love!
- `ex02`: Repetitive work
- `ex03`: Now it's weird!

### CPP Module 04

サブタイプ多相、抽象クラス、インターフェースを扱います。

- `ex00`: Polymorphism
- `ex01`: I don't want to set the world on fire
- `ex02`: Abstract class
- `ex03`: Interface & recap

## Build

各演習のディレクトリでビルドします。

```sh
cd CPP-Module-00/ex00
make
./megaphone "hello world"
```

各Makefileでは以下のルールを利用できます。

- `make`: ビルド
- `make clean`: オブジェクトファイルを削除
- `make fclean`: オブジェクトファイルと実行ファイルを削除
- `make re`: クリーン後に再ビルド

## Requirements

- C++98
- `c++ -Wall -Wextra -Werror`
- `using namespace`、C形式のメモリ確保関数、許可されていないSTL機能は不使用
- bonus課題は未実装
