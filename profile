#!/bin/sh

export PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# build with clang segfaults (clang++ 8.0.0)
# export CC="/usr/bin/clang"
# export CXX="/usr/bin/clang++"
export CXX="/usr/bin/g++"

export PROJECT_NAME=$(basename ${PROJECT_ROOT})
export PROJECT_BUILD_DIR="/build/${PROJECT_NAME}"
export PROJECT_BIN_DIR="/build/${PROJECT_NAME}"
export PROJECT_SRC_DIR="${PROJECT_ROOT}/src"

COMPILER_BANNER=$(${CXX} --version)

echo ""
echo ""
echo "==============================================================="
echo "${COMPILER_BANNER}"
echo ""
echo -e "Building \e[32m${PROJECT_NAME}..\e[39m"
echo ""
echo "==============================================================="


# 3rd party libraries live in /artifacts/
# it's your job to acquire and build them..for now
export ARTIFACT_ROOT="${HOME}/src/3rdp"
export BOOST_ROOT="${ARTIFACT_ROOT}/boost/"

export OPENSSL_ROOT_DIR="${ARTIFACT_ROOT}/openssl"
export OPENSSL_USE_STATIC_LIBS="TRUE"
