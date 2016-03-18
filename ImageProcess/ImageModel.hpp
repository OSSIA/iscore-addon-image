#pragma once
#include <Process/Process.hpp>
#include <State/Address.hpp>
#include <QByteArray>
#include <QString>
#include <QImage>

#include <ImageProcess/ScaleMode.hpp>
#include <Process/TimeValue.hpp>
#include <iscore/serialization/VisitorInterface.hpp>

class DataStream;
class JSONObject;
namespace Process { class LayerModel; }
namespace Process { class ProcessModel; }
class QObject;
#include <iscore/tools/SettableIdentifier.hpp>
#include <iscore_addon_image_export.h>


namespace Image
{
struct ImageFile
{
        QString path;
        QImage image;
};

class ISCORE_ADDON_IMAGE_EXPORT ProcessModel final : public Process::ProcessModel
{
        ISCORE_SERIALIZE_FRIENDS(ProcessModel, DataStream)
        ISCORE_SERIALIZE_FRIENDS(ProcessModel, JSONObject)

        Q_OBJECT

    public:
        ProcessModel(const TimeValue& duration,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);
        Process::ProcessModel* clone(const Id<Process::ProcessModel>& newId,
                            QObject* newParent) const override;

        template<typename Impl>
        ProcessModel(Deserializer<Impl>& vis, QObject* parent) :
            Process::ProcessModel{vis, parent}
        {
            vis.writeTo(*this);
        }

        //// ProcessModel ////
        UuidKey<Process::ProcessFactory> concreteFactoryKey() const override;

        QString prettyName() const override;

        Process::LayerModel* makeLayer_impl(
                const Id<Process::LayerModel>& viewModelId,
                const QByteArray& constructionData,
                QObject* parent) override;
        Process::LayerModel* loadLayer_impl(
                const VisitorVariant&,
                QObject* parent) override;

        void setDurationAndScale(const TimeValue& newDuration) override;
        void setDurationAndGrow(const TimeValue& newDuration) override;
        void setDurationAndShrink(const TimeValue& newDuration) override;

        void serialize_impl(const VisitorVariant& vis) const override;

        /// States
        ProcessStateDataInterface* startStateData() const override;
        ProcessStateDataInterface* endStateData() const override;

        //// ImageModel specifics ////
        const QString& imagePath() const
        {
            return m_image.path;
        }
        const QImage& image() const
        {
            return m_image.image;
        }

        void setImage(const QImage& img);
        void loadImage(const QString& img);

        ScaleMode scaleMode() const
        { return m_mode; }
        void setScaleMode(ScaleMode m)
        {
            m_mode = m;
            emit imageChanged();
        }

    signals:
        void imageChanged();

    protected:
        ProcessModel(const ProcessModel& source,
                        const Id<Process::ProcessModel>& id,
                        QObject* parent);
        Process::LayerModel* cloneLayer_impl(
                const Id<Process::LayerModel>& newId,
                const Process::LayerModel& source,
                QObject* parent) override;

    private:
        void startExecution() override;
        void stopExecution() override;
        void reset() override;

        Selection selectableChildren() const override;
        Selection selectedChildren() const override;
        void setSelection(const Selection& s) const override;

        ImageFile m_image;
        ScaleMode m_mode{};

};
}

