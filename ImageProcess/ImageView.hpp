#pragma once
#include <Process/LayerView.hpp>
#include <QString>


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

    private:
        void paint_impl(QPainter*) const override;
        QImage m_image;
};
}
