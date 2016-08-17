#pragma once
#include <ImageProcess/ImageModel.hpp>
#include <Process/LayerModel.hpp>

namespace Image
{
using Layer = Process::LayerModel_T<ProcessModel>;
}

DEFAULT_MODEL_METADATA(Image::Layer, "Image Layer")
