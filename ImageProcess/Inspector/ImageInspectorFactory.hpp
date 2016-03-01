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
class InspectorFactory final : public Process::InspectorWidgetDelegateFactory
{
        ISCORE_CONCRETE_FACTORY_DECL("6c6a91ad-8267-4976-a15d-de1cfce434e6")
    public:
        InspectorFactory() = default;

    private:
        Process::InspectorWidgetDelegate* make(
                const Process::ProcessModel&,
                const iscore::DocumentContext& doc,
                QWidget* parent) const override;
        bool matches(const Process::ProcessModel&) const override;

};
}
