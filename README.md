```bash

mkdir build

cd build

EMSCRIPTEN_CMAKE="/home/sajith/wasm/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"
cmake ../ -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN_CMAKE

make

emrun index.html

```