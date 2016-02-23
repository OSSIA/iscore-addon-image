#pragma once
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>

class InspectorWidgetBase;
class QObject;
class QString;
class QWidget;
namespace iscore {
struct DocumentContext;
}  // namespace iscore


namespace Image
{
class InspectorFactory final : public ProcessInspectorWidgetDelegateFactory
{
        ISCORE_CONCRETE_FACTORY_DECL("d312d001-b91f-42f0-8780-7e3a587c6ffc")
    public:
        InspectorFactory() = default;

    private:
        ProcessInspectorWidgetDelegate* make(
                const Process::ProcessModel&,
                const iscore::DocumentContext& doc,
                QWidget* parent) const override;
        bool matches(const Process::ProcessModel&) const override;

};
}
