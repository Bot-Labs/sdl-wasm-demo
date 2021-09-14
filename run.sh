# Change here
EMSDK_HOME=/home/sajith/wasm/emsdk

source ${EMSDK_HOME}/emsdk_env.sh

EMSCRIPTEN_CMAKE="${EMSDK_HOME}/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"
cmake ../ -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN_CMAKE

make

emrun index.html