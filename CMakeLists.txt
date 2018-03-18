cmake_minimum_required(VERSION 3.1)
project(score_addon_image LANGUAGES CXX)

###  General initialization of always necessary stuff (AUTOMOC, etc) ###
score_common_setup()

### Files & main target ###
set(HDRS
  "ImageProcess/Commands/ImageCommandFactory.hpp"
  "ImageProcess/Commands/SetImage.hpp"
  "ImageProcess/ImageLayerModel.hpp"
  "ImageProcess/ImagePanelProxy.hpp"
  "ImageProcess/ImageView.hpp"
  "ImageProcess/Inspector/ImageInspectorWidget.hpp"
  "ImageProcess/Inspector/ImageInspectorFactory.hpp"
  "ImageProcess/ScaleMode.hpp"
  "ImageProcess/ImagePresenter.hpp"
  "ImageProcess/ImageProcessMetadata.hpp"
  "ImageProcess/ImageModel.hpp"
  "ImageProcess/ImageFactory.hpp"
  "score_addon_image.hpp"
)
set(SRCS
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImageSerialization.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImageModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImagePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImageView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/ImagePanelProxy.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/Commands/SetImage.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/Commands/ImageCommandFactory.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/ImageProcess/Inspector/ImageInspectorWidget.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/score_addon_image.cpp"
)

add_library(${PROJECT_NAME} ${SRCS} ${HDRS} ${QRCS})
score_moc_headers(${PROJECT_NAME} "${HDRS}")

### If there are commands this will generate the files showcased in score_plugin_image.cpp ###
score_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

target_link_libraries(${PROJECT_NAME} PUBLIC score_lib_process score_lib_inspector)

### Setup of the target ###
setup_score_plugin(${PROJECT_NAME})
