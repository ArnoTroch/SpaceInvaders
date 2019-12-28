
cmake -Bcmake-build-debug -H.
# build
cmake --build cmake-build-debug --target SpaceInvaders -- -j 2
# run
cd cmake-build-debug && ./SpaceInvaders
