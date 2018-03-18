#pragma once
#include <Process/GenericProcessFactory.hpp>
#include <ImageProcess/ImageModel.hpp>
#include <ImageProcess/ImageProcessMetadata.hpp>
#include <ImageProcess/ImageLayerModel.hpp>
#include <ImageProcess/ImagePresenter.hpp>
#include <ImageProcess/ImageView.hpp>
#include <Process/LayerModelPanelProxy.hpp>

namespace Image
{
using ProcessFactory =
    Process::ProcessFactory_T<
        Image::ProcessModel>;
using LayerFactory = Process::LayerFactory_T<
    Image::ProcessModel,
    Image::ImagePresenter,
    Image::ImageView,
    Process::GraphicsViewLayerPanelProxy>;
}


