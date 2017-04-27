
#include <QFont>
#include <qnamespace.h>
#include <QPainter>

#include "ImageView.hpp"
#include <Process/LayerView.hpp>

namespace Image
{
ImageView::ImageView(QGraphicsItem* parent):
    LayerView{parent}
{

}

void ImageView::setImage(const QImage& image)
{
    m_image = image;
}

void ImageView::paint_impl(QPainter* painter) const
{
    if(!m_image.isNull())
    {
        auto rect = boundingRect();
        switch(m_mode)
        {
            case ScaleMode::NoScale:
            {
                painter->drawImage(m_image.rect(), m_image, m_image.rect());
                break;
            }
            case ScaleMode::ScaleDisregard:
            {
                auto scaled = m_image.scaled(
                                  rect.size().toSize(),
                                  Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                painter->drawImage(boundingRect(), scaled, scaled.rect());
                break;
            }
            case ScaleMode::ScaleBigger:
            {
                auto scaled = m_image.scaled(
                                  rect.size().toSize(),
                                  Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
                painter->drawImage(scaled.rect(), scaled, scaled.rect());
                break;
            }
            case ScaleMode::ScaleSmaller:
            {
                auto scaled = m_image.scaled(
                                  rect.size().toSize(),
                                  Qt::KeepAspectRatio, Qt::SmoothTransformation);
                painter->drawImage(scaled.rect(), scaled, scaled.rect());
                break;
            }
        }
    }
}

}
