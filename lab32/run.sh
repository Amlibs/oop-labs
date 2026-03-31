rm -rf ./build
mkdir build
cmake . -B build/ -G "MinGW Makefiles" -DQt6_ROOT="D:\Qt\6.10.2\mingw_64"
cmake --build build
"D:\Qt\6.10.2\mingw_64\bin\windeployqt.exe" ".\build\qtlab32.exe"
