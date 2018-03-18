#include <ImageProcess/ImageLayerModel.hpp>
#include <ImageProcess/ImageModel.hpp>
#include <unordered_map>

#include <ImageProcess/Inspector/ImageInspectorFactory.hpp>
#include <ImageProcess/ImageProcessMetadata.hpp>
#include <ImageProcess/Commands/ImageCommandFactory.hpp>
#include <Inspector/InspectorWidgetFactoryInterface.hpp>
#include <Process/ProcessFactory.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <score/plugins/customfactory/StringFactoryKey.hpp>
#include <score/plugins/customfactory/FactorySetup.hpp>
#include "score_addon_image.hpp"

#include <score_addon_image_commands_files.hpp>
#include <ImageProcess/ImageFactory.hpp>

score_addon_image::score_addon_image() :
    QObject {}
{
}

score_addon_image::~score_addon_image()
{

}


std::vector<std::unique_ptr<score::InterfaceBase>> score_addon_image::factories(
        const score::ApplicationContext& ctx,
        const score::InterfaceKey& key) const
{
    return instantiate_factories<
            score::ApplicationContext,
        FW<Process::ProcessModelFactory,
           Image::ProcessFactory>,
        FW<Process::LayerFactory,
          Image::LayerFactory>,
        FW<Inspector::InspectorWidgetFactory,
             Image::InspectorFactory>
    >(ctx, key);
}

std::pair<const CommandGroupKey, CommandGeneratorMap> score_addon_image::make_commands()
{
    using namespace Image;
    std::pair<const CommandGroupKey, CommandGeneratorMap> cmds{CommandFactoryName(), CommandGeneratorMap{}};

    using Types = TypeList<
#include <score_addon_image_commands.hpp>
      >;
    for_each_type<Types>(score::commands::FactoryInserter{cmds.second});

    return cmds;
}
