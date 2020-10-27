cmake_minimum_required(VERSION 3.11)
project(blurhash-qt VERSION 1.0.0)

find_package(Qt5 COMPONENTS Core Qml Quick REQUIRED)
set(CMAKE_AUTOMOC ON)
include(GNUInstallDirs)

set(blurhash-qt_SOURCES
	blurhash_plugin.cpp
	blurhash.cpp)

set(qblurhash-qt_HEADERS
	blurhash_plugin.h
	blurhash.h)

add_library(blurhash-qt ${qt-blurhash_SOURCES})
target_link_libraries(blurhash-qt Qt5::Core Qt5::Qml Qt5::Quick)

install(TARGETS blurhash-qt EXPORT "BlurhashQt" ARCHIVE LIBRARY)

install(EXPORT "BlurhashQt" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
