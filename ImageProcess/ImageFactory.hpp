#pragma once

#include <Process/ProcessFactory.hpp>
#include <iscore/serialization/VisitorCommon.hpp>
#include <ImageProcess/ImageModel.hpp>
#include <ImageProcess/ImageProcessMetadata.hpp>
#include <ImageProcess/ImageLayerModel.hpp>
#include <ImageProcess/ImagePresenter.hpp>
#include <ImageProcess/ImageView.hpp>
namespace Image
{
class ProcessFactory final : public Process::ProcessFactory
{
    public:
        QString prettyName() const override
        { // In factory list
            return Metadata<PrettyName_k, ProcessModel>::get();
        }

        const UuidKey<Process::ProcessFactory>& concreteFactoryKey() const override
        {
            return Metadata<ConcreteFactoryKey_k, ProcessModel>::get();
        }


        Process::ProcessModel* makeModel(
                const TimeValue& duration,
                const Id<Process::ProcessModel>& id,
                QObject* parent) override
        {
            return new Image::ProcessModel{duration, id, parent};
        }

        QByteArray makeStaticLayerConstructionData() const override
        {
            return {};
        }

        Process::ProcessModel* load(const VisitorVariant& vis, QObject* parent) override
        {
            return deserialize_dyn(vis, [&] (auto&& deserializer)
            { return new Image::ProcessModel{deserializer, parent};});
        }

        Process::LayerPresenter* makeLayerPresenter(
                const Process::LayerModel& model,
                Process::LayerView* v,
                QObject* parent) override
        {
            return new Image::ImagePresenter{
                dynamic_cast<const LayerModel&>(model),
                dynamic_cast<Image::ImageView*>(v),
                parent};
        }

        Process::LayerView* makeLayerView(
                const Process::LayerModel&,
                QGraphicsItem* parent) override
        {
            return new Image::ImageView{parent};
        }
};

}


