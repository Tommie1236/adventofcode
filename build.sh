set -e

PROJECT_NAME=${1:-AoC-Default}

mkdir -p build

cd build
cmake -DEXTERNAL_PROJECT_NAME=${PROJECT_NAME} ..
make -j $(($(nproc) * 2))

echo "------------------------------"
echo "Running Project: ${PROJECT_NAME}"
echo "------------------------------"
./src/${PROJECT_NAME}