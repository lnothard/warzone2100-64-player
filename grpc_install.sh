cd 3rdparty/grpc &&
    mkdir -p cmake/build &&
    cd cmake/build &&
    cmake ../.. &&
    make &&
    cmake ../.. -DgRPC_INSTALL=ON                \
              -DCMAKE_BUILD_TYPE=Release       \
              -DgRPC_ABSL_PROVIDER=module     \
              -DgRPC_CARES_PROVIDER=module    \
              -DgRPC_PROTOBUF_PROVIDER=module \
              -DgRPC_RE2_PROVIDER=module      \
              -DgRPC_SSL_PROVIDER=module      \
              -DgRPC_ZLIB_PROVIDER=module &&
    make &&
    make install;
