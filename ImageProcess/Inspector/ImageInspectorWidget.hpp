#pragma once
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <ImageProcess/ImageModel.hpp>
#include <QString>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>

namespace iscore{
class Document;
struct DocumentContext;
}
class QLineEdit;

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
        void on_pathChange(const QString& path);

        QLineEdit* m_lineEdit{};
        CommandDispatcher<> m_dispatcher;
};
}
