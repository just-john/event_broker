#!/bin/bash

source ./profile

mkdir -p ${PROJECT_BUILD_DIR}/lib

cd "${PROJECT_BUILD_DIR}"

cmake -G Ninja \
    -DCMAKE_INSTALL_PREFIX=${PROJECT_BIN_DIR} \
    ../

ninja
ninja install

cd "${PROJECT_ROOT}"
