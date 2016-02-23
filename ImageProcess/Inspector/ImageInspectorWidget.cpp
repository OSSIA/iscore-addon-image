#include <QBoxLayout>
#include <QFormLayout>

#include <QPushButton>
#include <QSpinBox>
#include <QStringList>
#include <QWidget>
#include <algorithm>
#include <list>
#include <vector>
#include <ImageProcess/ImageModel.hpp>
#include "ImageInspectorWidget.hpp"
#include <Inspector/InspectorWidgetBase.hpp>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>
#include <iscore/document/DocumentInterface.hpp>
#include <iscore/tools/ModelPath.hpp>
#include <iscore/tools/Todo.hpp>
#include <iscore/document/DocumentContext.hpp>


namespace Image
{
InspectorWidget::InspectorWidget(
        const ProcessModel& model,
        const iscore::DocumentContext& doc,
        QWidget* parent) :
    ProcessInspectorWidgetDelegate_T {model, parent},
    m_dispatcher{doc.commandStack}
{
    setObjectName("ImageInspectorWidget");
    setParent(parent);

    auto vlay = new QVBoxLayout;
    vlay->setSpacing(0);
    vlay->setContentsMargins(0,0,0,0);
/*
    // LineEdit
    // If there is a DeviceExplorer in the current document, use it
    // to make a widget.
    // TODO instead of doing this, just make an address line edit factory.
    auto plug = doc.findPlugin<Explorer::DeviceDocumentPlugin>();
    DeviceExplorerModel* explorer{};
    if(plug)
        explorer = plug->updateProxy.deviceExplorer;
    m_lineEdit = new AddressEditWidget{explorer, this};

    m_lineEdit->setAddress(process().address());
    con(process(), &ProcessModel::addressChanged,
            m_lineEdit, &AddressEditWidget::setAddress);

    connect(m_lineEdit, &AddressEditWidget::addressChanged,
            this, &InspectorWidget::on_addressChange);

    vlay->addWidget(m_lineEdit);
*/
    // Min / max
    this->setLayout(vlay);
}

void InspectorWidget::on_pathChange(const QString& path)
{
    /*
    // Various checks
    if(newAddr == process().address())
        return;

    if(newAddr.path.isEmpty())
        return;

    auto cmd = new ChangeAddress{process(), newAddr};

    m_dispatcher.submitCommand(cmd);
    */
}
}
