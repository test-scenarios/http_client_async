# http_client_async
## How to build

1. cmake -S . -B build/ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=.
2. cmake --build build/
3. ./build/http_client_async

## Notes
1. The code assumes that the target url contains the files testN_20M.csv at the root of TARGET where N is 1 to 10
