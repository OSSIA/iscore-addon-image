cmake_minimum_required(VERSION 3.1)
project(iscore_plugin_image LANGUAGES CXX)

###  General initialization of always necessary stuff (AUTOMOC, etc) ###
iscore_common_setup()

### Files & main target ###
file(GLOB_RECURSE HDRS
    "${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/*.hpp"
)
set(SRCS
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImageSerialization.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImageLayerSerialization.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImageModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImagePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImageView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImageLayerModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImagePanelProxy.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/Commands/SetImage.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/Commands/ImageCommandFactory.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/iscore_addon_image.cpp"
)

if(TARGET iscore_lib_inspector)
    set(INSPECTOR_SRCS
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/Inspector/ImageInspectorFactory.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/Inspector/ImageInspectorWidget.cpp"
    )

    set(SRCS ${SRCS} ${INSPECTOR_SRCS})

    file(GLOB_RECURSE INSPECTOR_HDRS
        "${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/Inspector/*.hpp")

    set(HDRS ${HDRS} ${INSPECTOR_HDRS})
endif()

add_library(${PROJECT_NAME} ${SRCS} ${HDRS} ${QRCS})

### If there are commands this will generate the files showcased in iscore_plugin_image.cpp ###
iscore_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

target_link_libraries(${PROJECT_NAME} PUBLIC iscore_lib_process)

if(TARGET iscore_lib_inspector)
    target_link_libraries(${PROJECT_NAME} PUBLIC iscore_lib_inspector)
endif()

### Setup of the target ###
setup_iscore_plugin(${PROJECT_NAME})
