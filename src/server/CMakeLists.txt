cmake_minimum_required(VERSION 3.19.2)

file(GLOB HDRS "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/3rdparty/*.h" "${PROJECT_SOURCE_DIR}/src/titleui/*.h")
file(GLOB SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/3rdparty/*.cpp" "${PROJECT_SOURCE_DIR}/src/titleui/*.cpp")
qt5_wrap_cpp(MOCFILES qtscriptdebug.h)
file(GLOB PROTO_SRCS "${PROJECT_SOURCE_DIR}/protos/*.pb.cc")
file(GLOB PROTO_HDRS "${PROJECT_SOURCE_DIR}/protos/*.pb.h")

add_executable(server ${HDRS} ${SRCS} ${MOCFILES} ${PROTO_SRCS} ${PROTO_HDRS})

target_link_libraries(server CURL::libcurl)
target_link_libraries(server re2::re2)
target_link_libraries(server protobuf::libprotobuf)
target_link_libraries(server gRPC::grpc++_reflection)
target_link_libraries(server exception-handler gamelib ivis-opengl netplay sdl-server framework sequence sound widget)
target_link_libraries(server launchinfo EmbeddedJSONSignature)
target_link_libraries(server Qt5::Core Qt5::Script Qt5::Gui Qt5::Widgets)

target_compile_definitions(server PRIVATE SERVER)