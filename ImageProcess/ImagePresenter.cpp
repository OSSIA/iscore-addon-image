#include <Process/LayerModel.hpp>
#include <Process/Process.hpp>

#include "ImagePresenter.hpp"
#include "ImageView.hpp"
#include <ImageProcess/ImageModel.hpp>
#include <ImageProcess/ImageLayerModel.hpp>
#include <Process/LayerPresenter.hpp>
#include <iscore/document/DocumentInterface.hpp>
#include <iscore/document/DocumentContext.hpp>
class QMenu;
class QObject;


namespace Image
{
ImagePresenter::ImagePresenter(
        const Layer& layer,
        ImageView* view,
        const Process::ProcessPresenterContext& ctx,
        QObject* parent):
    LayerPresenter{ctx, parent},
    m_layer{layer},
    m_view{view}
{
    putToFront();

    con(layer.processModel().metadata, &ModelMetadata::NameChanged,
            this, [&] (QString s)
    {
        putToFront();
    });

    con(layer.processModel(), &ProcessModel::imageChanged,
        this, [&] ( ) {
        m_view->setMode(m_layer.processModel().scaleMode());
        m_view->setImage(m_layer.processModel().image());
    });

    m_view->setImage(layer.processModel().image());
    m_view->setMode(layer.processModel().scaleMode());
}

void ImagePresenter::setWidth(qreal val)
{
    m_view->setWidth(val);
}

void ImagePresenter::setHeight(qreal val)
{
    m_view->setHeight(val);
}

void ImagePresenter::putToFront()
{
    m_view->setOpacity(1.);
}

void ImagePresenter::putBehind()
{
    m_view->setOpacity(0.8);
}

void ImagePresenter::on_zoomRatioChanged(ZoomRatio)
{
}

void ImagePresenter::parentGeometryChanged()
{
}

const Process::LayerModel& ImagePresenter::layerModel() const
{
    return m_layer;
}

const Id<Process::ProcessModel>& ImagePresenter::modelId() const
{
    return m_layer.processModel().id();
}

}
