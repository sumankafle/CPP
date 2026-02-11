#!/usr/bin/env bash
set -euo pipefail


echo "Installing build dependencies on Ubuntu/Debian..."
sudo apt-get update
sudo apt-get install -y build-essential pkg-config cmake qtbase5-dev libqt5widgets5 doxygen


echo "Done. You can now build with CMake:"
echo "  mkdir -p qt_coffee/build && cd qt_coffee/build"cd ..
echo "  cmake .. && make -j$(nproc)"
