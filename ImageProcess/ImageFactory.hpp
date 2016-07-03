#pragma once
#include <Process/GenericProcessFactory.hpp>
#include <ImageProcess/ImageModel.hpp>
#include <ImageProcess/ImageProcessMetadata.hpp>
#include <ImageProcess/ImageLayerModel.hpp>
#include <ImageProcess/ImagePresenter.hpp>
#include <ImageProcess/ImageView.hpp>
namespace Image
{
using ProcessFactory = Process::GenericProcessFactory<
    Image::ProcessModel,
    Image::LayerModel,
    Image::ImagePresenter,
    Image::ImageView>;
}


