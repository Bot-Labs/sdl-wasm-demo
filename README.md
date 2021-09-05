#### Build and Running Instructions

```bash

mkdir build

cd build

# Please change the `Emscripten.cmake` path accordingly to your configurations.
EMSCRIPTEN_CMAKE="/home/sajith/wasm/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"
cmake ../ -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN_CMAKE

make

emrun index.html

```