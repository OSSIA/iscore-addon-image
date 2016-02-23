#pragma once
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <ImageProcess/ImageModel.hpp>
#include <QString>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>

namespace iscore{
class Document;
struct DocumentContext;
}
class QLabel;
class QPushButton;

namespace Image
{
class ProcessModel;
class InspectorWidget final :
        public ProcessInspectorWidgetDelegate_T<Image::ProcessModel>
{
    public:
        explicit InspectorWidget(
                const ProcessModel& object,
                const iscore::DocumentContext& context,
                QWidget* parent);

    private:
        QLabel* m_label{};
        QPushButton* m_loadButton{};
        CommandDispatcher<> m_dispatcher;
};
}
