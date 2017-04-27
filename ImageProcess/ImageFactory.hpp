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
    Process::GenericProcessModelFactory<
        Image::ProcessModel>;
using LayerFactory = Process::GenericLayerFactory<
    Image::ProcessModel,
    Image::ImagePresenter,
    Image::ImageView,
    Process::GraphicsViewLayerPanelProxy>;
}


