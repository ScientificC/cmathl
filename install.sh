#!/bin/bash

pushd `pwd`

rm -rf build
mkdir build
cd build

cmake -G "Unix Makefiles" .. -DCML_BUILD_STATIC=ON -DCML_BUILD_SHARED=ON && \
	make && \
	ctest && \
	sudo make install

popd
