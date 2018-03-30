@ECHO ON
PUSHD "%~dp0"

cd ..
rmdir /s /q build
mkdir build
cd build
cmake -trace --warn-unitialized --warn-unused_vars -G "NMake Makefiles" .. -DCMAKE_INSTALL_PREFIX=../install -DCML_BUILD_STATIC=ON -DCMAKE_BUILD_TYPE=Release
nmake
ctest
cpack -G "ZIP"

POPD
