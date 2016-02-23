#include "ImagePanelProxy.hpp"
#include <iscore/document/DocumentContext.hpp>
#include <iscore/document/DocumentInterface.hpp>
#include <ImageProcess/ImageModel.hpp>
namespace Image
{
PanelProxy::PanelProxy(
        const Process::LayerModel& vm,
        QObject* parent):
    Process::LayerModelPanelProxy{parent},
    m_layer{vm}
{
}

const Process::LayerModel& PanelProxy::layer()
{
    return m_layer;
}

QWidget* PanelProxy::widget() const
{
    return m_widget;
}

}
