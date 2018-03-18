#include <score/tools/std/Optional.hpp>
#include <score/document/DocumentInterface.hpp>
#include <QDebug>
#include <QPoint>

#include "ImageLayerModel.hpp"
#include "ImageModel.hpp"
#include <score/model/ModelMetadata.hpp>
#include <score/model/IdentifiedObjectMap.hpp>
#include <score/model/Identifier.hpp>

namespace Process { class LayerModel; }
namespace Process { class ProcessModel; }
class QObject;
namespace Image
{
ProcessModel::ProcessModel(
        const TimeVal& duration,
        const Id<Process::ProcessModel>& id,
        QObject* parent) :
    Process::ProcessModel {duration, id, Metadata<ObjectKey_k, ProcessModel>::get(), parent}
{
    metadata().setInstanceName(*this);
    loadImage("test.png");
}

void ProcessModel::loadImage(const QString& img)
{
    m_image.path = img;
    m_image.image.load(img);

    imageChanged();
}

}
