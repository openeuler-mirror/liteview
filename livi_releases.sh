#!/bin/sh

python3 build_liteview.py --build-thread=-j8

cd shell
rm -rf build
rm -rf bin
mkdir build
cd build
cmake ..
cd ..
make -C build

cd launcher
g++ LiteViewLauncher.cpp -std=c++17 -O2 -o LiteViewLauncher

cd ..
cd ..
rm -rf livi-browser
mkdir livi-browser
cp ./livicore/livicore.so ./livi-browser
cp -r ./shell/images ./livi-browser

cp ./shell/bin/LiteView ./livi-browser
cp ./shell/launcher/LiteViewLauncher ./livi-browser

