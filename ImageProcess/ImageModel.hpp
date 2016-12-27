#pragma once
#include <ImageProcess/ScaleMode.hpp>
#include <ImageProcess/ImageProcessMetadata.hpp>
#include <Process/Process.hpp>
#include <State/Address.hpp>
#include <QByteArray>
#include <QImage>

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
        ISCORE_SERIALIZE_FRIENDS
        MODEL_METADATA_IMPL(Image::ProcessModel)

        Q_OBJECT

    public:
        ProcessModel(const TimeValue& duration,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);

        template<typename Impl>
        ProcessModel(Impl& vis, QObject* parent) :
            Process::ProcessModel{vis, parent}
        {
            vis.writeTo(*this);
        }

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

    private:
        ImageFile m_image;
        ScaleMode m_mode{};

};
}

