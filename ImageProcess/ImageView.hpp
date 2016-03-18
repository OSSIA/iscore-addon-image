#pragma once
#include <Process/LayerView.hpp>
#include <QString>
#include <ImageProcess/ScaleMode.hpp>


class QGraphicsItem;
class QPainter;
//class QQuickWidget;

namespace Image
{
class ImageView final : public Process::LayerView
{
        Q_OBJECT
    public:
        explicit ImageView(QGraphicsItem* parent);

        void setImage(const QImage& image);
        void setMode(ScaleMode s)
        {
            m_mode = s;
            update();
        }

    private:
        void paint_impl(QPainter*) const override;
        QImage m_image;
        ScaleMode m_mode;
};
}
