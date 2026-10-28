# CPP Module 04

サブタイプ多相、抽象クラス、深いコピーを学ぶModuleです。

## Exercises

- `ex00: Polymorphism` — 仮想関数を持つ`Animal`階層と、仮想関数を持たない`WrongAnimal`階層の動作を比較します。
- `ex01: I don't want to set the world on fire` — `Dog`と`Cat`が動的確保した`Brain`を持ち、コピー時に深いコピーを行います。
- `ex02: Abstract class` — `Animal::makeSound`を純粋仮想関数にし、基底クラスを直接インスタンス化できないようにします。

## Build

```sh
cd ex00 # ex00〜ex02
make
```
