#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>
#include <ImageProcess/ImageModel.hpp>
#include "ImageInspectorWidget.hpp"
#include <ImageProcess/Commands/SetImage.hpp>
#include <Inspector/InspectorWidgetBase.hpp>
#include <score/command/Dispatchers/CommandDispatcher.hpp>
#include <score/document/DocumentInterface.hpp>
#include <score/model/path/Path.hpp>
#include <score/tools/Todo.hpp>
#include <score/document/DocumentContext.hpp>
#include <score/widgets/SignalUtils.hpp>


namespace Image
{
InspectorWidget::InspectorWidget(
        const ProcessModel& model,
        const score::DocumentContext& doc,
        QWidget* parent) :
    InspectorWidgetDelegate_T {model, parent},
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

    m_scale = new QComboBox;
    m_scale->addItems(QStringList{
                          tr("No scale"),
                          tr("Scale"),
                          tr("Keep aspect (small)"),
                          tr("Keep aspect (large)")});
    connect(m_scale, SignalUtils::QComboBox_currentIndexChanged_int(),
            this, [=] (int idx) {
        m_dispatcher.submitCommand(new SetImageScaleMode{process(), static_cast<ScaleMode>(idx)});
    });

    vlay->addWidget(m_label);
    vlay->addWidget(m_loadButton);
    vlay->addWidget(m_scale);
    this->setLayout(vlay);
}
}
