#!/bin/bash

pushd `pwd`

cd ..
rm -rf build
mkdir build
cd build

cmake -G "Unix Makefiles" .. -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Release -DCML_DOUBLE_PRECISION=ON -Dmfloat_t=double && \
	make && \
	ctest && \
	make install && \
  make srpm && \
	make rpm

popd
