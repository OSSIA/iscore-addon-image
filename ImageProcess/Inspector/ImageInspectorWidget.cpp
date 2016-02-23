#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <ImageProcess/ImageModel.hpp>
#include "ImageInspectorWidget.hpp"
#include <ImageProcess/Commands/SetImage.hpp>
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

    m_label = new QLabel{model.imagePath(), this};

    // TODO this calls for a reactive binding
    con(process(), &ProcessModel::imageChanged,
        this, [&] () {
        m_label->setText(process().imagePath());
    });
    m_label->setText(process().imagePath());

    m_loadButton = new QPushButton{tr("Load an image")};
    connect(m_loadButton, &QPushButton::pressed,
            this, [=] () {
        auto res = QFileDialog::getOpenFileName(
                    this,
                    tr("Load an image"),
                    "",
                    "Images (*.png *.jpg)");

        if(res == process().imagePath())
            return;

        if(!QFile::exists(res))
            return;

        m_dispatcher.submitCommand(new SetImage{process(), res});
    });

    vlay->addWidget(m_label);
    vlay->addWidget(m_loadButton);
    this->setLayout(vlay);
}
}
