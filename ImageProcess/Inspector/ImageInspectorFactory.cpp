#include <QString>

#include <ImageProcess/ImageProcessMetadata.hpp>
#include "ImageInspectorFactory.hpp"
#include "ImageInspectorWidget.hpp"
#include <ImageProcess/ImageModel.hpp>
class InspectorWidgetBase;
class QObject;
class QWidget;
namespace iscore {
class Document;
}

namespace Image
{
ProcessInspectorWidgetDelegate* InspectorFactory::make(
        const Process::ProcessModel& process,
        const iscore::DocumentContext& doc,
        QWidget* parent) const
{
    return new InspectorWidget{
        static_cast<const ProcessModel&>(process), doc, parent};
}

bool InspectorFactory::matches(const Process::ProcessModel& process) const
{
    return dynamic_cast<const ProcessModel*>(&process);
}
}
