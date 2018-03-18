#pragma once
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <ImageProcess/ImageModel.hpp>
#include <ImageProcess/Inspector/ImageInspectorWidget.hpp>

namespace Image
{
class InspectorFactory final :
        public Process::InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
        SCORE_CONCRETE("6c6a91ad-8267-4976-a15d-de1cfce434e6")
};
}
