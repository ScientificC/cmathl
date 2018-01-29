#!/bin/bash

pushd `pwd`

cd ..
rm -rf build
mkdir build
cd build

cmake -G "Unix Makefiles" .. -DCMAKE_INSTALL_PREFIX=../install -DCML_BUILD_STATIC=ON -DCML_BUILD_SHARED=ON && \
	make && \
	ctest && \
	make install && \
  make srpm && \
	make rpm

popd
