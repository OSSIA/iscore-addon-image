#include <boost/optional/optional.hpp>
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

void ProcessModel::setDurationAndScale(const TimeValue& newDuration)
{
    // We only need to change the duration.
    setDuration(newDuration);
}

void ProcessModel::setDurationAndGrow(const TimeValue& newDuration)
{
    setDuration(newDuration);
}

void ProcessModel::setDurationAndShrink(const TimeValue& newDuration)
{
    setDuration(newDuration);
}

Process::LayerModel* ProcessModel::makeLayer_impl(
        const Id<Process::LayerModel>& viewModelId,
        const QByteArray& constructionData,
        QObject* parent)
{
    auto vm = new LayerModel{*this, viewModelId, parent};
    return vm;
}

Process::LayerModel* ProcessModel::cloneLayer_impl(
        const Id<Process::LayerModel>& newId,
        const Process::LayerModel& source,
        QObject* parent)
{
    auto vm = new LayerModel {
              static_cast<const LayerModel&>(source), *this, newId, parent};
    return vm;
}

ProcessStateDataInterface* ProcessModel::startStateData() const
{
    return nullptr;
}

ProcessStateDataInterface* ProcessModel::endStateData() const
{
    return nullptr;
}

void ProcessModel::loadImage(const QString& img)
{
    m_image.path = img;
    m_image.image.load(img);

    emit imageChanged();
}

void ProcessModel::startExecution()
{
}

void ProcessModel::stopExecution()
{
}

void ProcessModel::reset()
{
}

Selection ProcessModel::selectableChildren() const
{
    return {};
}

Selection ProcessModel::selectedChildren() const
{
    return {};
}

void ProcessModel::setSelection(const Selection& s) const
{
}
}
