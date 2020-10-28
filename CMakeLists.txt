cmake_minimum_required(VERSION 3.11)
project(blurhash-qt VERSION 1.0.0)

option(ENABLE_EXPORT "Enable exporting of targets" ON)

find_package(Qt5 COMPONENTS Core Qml Quick REQUIRED)
include(GNUInstallDirs)
set(CMAKE_AUTOMOC ON)

set(blurhash-qt_SOURCES
	src/blurhash_plugin.cpp
	src/blurhash.cpp)

set(blurhash-qt_HEADERS
	src/blurhash_plugin.h
	src/blurhash.h)

add_library(blurhash-qt ${blurhash-qt_SOURCES} ${blurhash-qt_HEADERS})
target_link_libraries(blurhash-qt PRIVATE Qt5::Core Qt5::Qml Qt5::Quick)

install(TARGETS blurhash-qt EXPORT "BlurhashQt" 
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_custom_command(
    TARGET blurhash-qt
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/qmldir $<TARGET_FILE_DIR:blurhash-qt>/qmldir
)
install(FILES $<TARGET_FILE_DIR:blurhash-qt>/qmldir
	DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(${ENABLE_EXPORT})
	install(EXPORT "BlurhashQt" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
endif()
