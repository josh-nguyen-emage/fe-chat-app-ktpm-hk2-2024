cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(Zalo_reDev_3App LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick WebSockets)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

qt_add_executable(Zalo_reDev_3App src/main.cpp
    src/test_only.h src/test_only.cpp
    src/Model/chatlist_model.cpp src/Model/chatlist_model.h src/Model/conversation_model.cpp src/Model/conversation_model.h src/Model/main_model.cpp src/Model/main_model.h src/Model/persionalinfor_model.cpp src/Model/persionalinfor_model.h src/ViewModel/ChatView/chatlistvm.cpp src/ViewModel/ChatView/chatlistvm.h src/ViewModel/ChatView/conversationvm.cpp src/ViewModel/ChatView/conversationvm.h src/ViewModel/PersionalInforView/persionalinforvm.cpp src/ViewModel/PersionalInforView/persionalinforvm.h
    src/AppDefine/define.h src/AppDefine/define.cpp

    src/Controller/pythoncontroller.h src/Controller/pythoncontroller.cpp
)

qt_add_resources(Zalo_reDev_3App "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

target_link_libraries(Zalo_reDev_3App PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::WebSockets
)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
set(QML_IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Import paths for Qt Creator's code model"
    FORCE
)

if (BUILD_QDS_COMPONENTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/qmlcomponents)
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/qmlmodules)

if (LINK_INSIGHT)
    include(${CMAKE_CURRENT_SOURCE_DIR}/insight)
endif ()

include(GNUInstallDirs)
install(TARGETS Zalo_reDev_3App
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# make IDEs aware of the QML import path
set(QML_IMPORT_PATH ${PROJECT_BINARY_DIR}/qml CACHE PATH
    "Path to the custom QML components defined by the project")
