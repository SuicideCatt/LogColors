#!/bin/bash

set -e

cd build
VERSION=$(cmake --system-information | awk -F= '$1~/PROJECT_VERSION:STATIC/{print$2}')
cd ..

printf "// $1 $VERSION\n// $2\n\n" > "$3" && cat "$3"

~/.local/bin/quom "./include/$1.hpp" "/tmp/$1.hpp" && cat "/tmp/$1.hpp" >> "$3"

g++ -std=c++2a -I./build tests/main.cpp -o "$3.test"
