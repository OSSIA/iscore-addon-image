#include <Process/Style/ProcessFonts.hpp>
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
    painter->drawImage(0, 0, m_image);
}

}
