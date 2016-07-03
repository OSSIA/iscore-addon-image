#include <iscore/tools/std/Optional.hpp>
#include <iscore/document/DocumentInterface.hpp>
#include <QDebug>
#include <QPoint>

#include <ImageProcess/ImageProcessMetadata.hpp>
#include "ImageLayerModel.hpp"
#include "ImageModel.hpp"
#include <Process/ModelMetadata.hpp>
#include <iscore/plugins/documentdelegate/plugin/ElementPluginModelList.hpp>
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
    pluginModelList = new iscore::ElementPluginModelList{iscore::IDocument::documentContext(*parent), this};

    metadata.setName(QString("Image.%1").arg(*this->id().val()));
    loadImage("test.png");
}

ProcessModel::ProcessModel(
        const ProcessModel& source,
        const Id<Process::ProcessModel>& id,
        QObject* parent):
    Process::ProcessModel {source, id, Metadata<ObjectKey_k, ProcessModel>::get(), parent},
    m_image(source.m_image)
{
    pluginModelList = new iscore::ElementPluginModelList(*source.pluginModelList, this);

    metadata.setName(QString("Image.%1").arg(*this->id().val()));
}

Process::ProcessModel* ProcessModel::clone(
        const Id<Process::ProcessModel>& newId,
        QObject* newParent) const
{
    return new ProcessModel {*this, newId, newParent};
}

UuidKey<Process::ProcessFactory>ProcessModel::concreteFactoryKey() const
{
    return Metadata<ConcreteFactoryKey_k, ProcessModel>::get();
}

QString ProcessModel::prettyName() const
{
    return metadata.name();
}

void ProcessModel::loadImage(const QString& img)
{
    m_image.path = img;
    m_image.image.load(img);

    emit imageChanged();
}

}
