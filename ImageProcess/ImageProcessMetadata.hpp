#pragma once
#include <Process/ProcessMetadata.hpp>
#include <QString>
#include <score/plugins/customfactory/UuidKey.hpp>
#include <score_addon_image_export.h>

namespace Image
{
class ProcessModel;
}

PROCESS_METADATA(
    SCORE_ADDON_IMAGE_EXPORT,
    Image::ProcessModel,
    "e590fe08-312b-463b-85f7-4c722129c7a3",
    "Image",
    "Image",
    "Graphics",
    {},
    Process::ProcessFlags::SupportsTemporal |
    Process::ProcessFlags::PutInNewSlot
    )
