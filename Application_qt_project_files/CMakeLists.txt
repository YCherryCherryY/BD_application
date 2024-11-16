cmake_minimum_required(VERSION 3.5)

project(Application_for_BD VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS AxContainer)

include_directories(
    ${Qt5AxContainer_INCLUDE_DIRS}
)
add_definitions(${Qt5AxContainer_DEFINITIONS})
include_directories(${Qt5Widgets_INCLUDES}  ${Qt5AxContainer_INCLUDE_DIRS})

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        login.cpp
        login.h
        login.ui
        updatedata.cpp
        updatedata.h
        updatedata.ui
        adddeal.h
        adddeal.ui
        adddeal.cpp
        deletedeal.cpp
        deletedeal.ui
        deletedeal.h
        report.cpp
        report.h
        report.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Application_for_BD
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Application_for_BD APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Application_for_BD SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Application_for_BD
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Application_for_BD PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Application_for_BD PRIVATE Qt6::Sql)
target_link_libraries(Application_for_BD PRIVATE Qt6::AxContainer)

set_target_properties(Application_for_BD PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Application_for_BD
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Application_for_BD)
endif()
