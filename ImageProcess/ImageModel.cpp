#include <iscore/tools/std/Optional.hpp>
#include <iscore/document/DocumentInterface.hpp>
#include <QDebug>
#include <QPoint>

#include "ImageLayerModel.hpp"
#include "ImageModel.hpp"
#include <iscore/model/ModelMetadata.hpp>
#include <iscore/tools/IdentifiedObjectMap.hpp>
#include <iscore/tools/SettableIdentifier.hpp>

namespace Process { class LayerModel; }
namespace Process { class ProcessModel; }
class QObject;
namespace Image
{
ProcessModel::ProcessModel(
        const TimeValue& duration,
        const Id<Process::ProcessModel>& id,
        QObject* parent) :
    Process::ProcessModel {duration, id, Metadata<ObjectKey_k, ProcessModel>::get(), parent}
{
    metadata().setName(QString("Image.%1").arg(this->id().val()));
    loadImage("test.png");
}

ProcessModel::ProcessModel(
        const ProcessModel& source,
        const Id<Process::ProcessModel>& id,
        QObject* parent):
    Process::ProcessModel {source, id, Metadata<ObjectKey_k, ProcessModel>::get(), parent},
    m_image(source.m_image)
{
    metadata().setName(QString("Image.%1").arg(this->id().val()));
}

void ProcessModel::loadImage(const QString& img)
{
    m_image.path = img;
    m_image.image.load(img);

    emit imageChanged();
}

}
