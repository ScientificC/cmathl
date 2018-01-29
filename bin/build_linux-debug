#!/bin/bash

pushd `pwd`

cd ..
rm -rf build
mkdir build
cd build

cmake -G "Unix Makefiles" .. -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Debug && \
	make && \
	ctest && \
	make install

popd
