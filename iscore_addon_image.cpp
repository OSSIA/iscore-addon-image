#include <ImageProcess/ImageLayerModel.hpp>
#include <ImageProcess/ImageModel.hpp>
#include <unordered_map>

#include <ImageProcess/ImageProcessMetadata.hpp>
#include <ImageProcess/Commands/ImageCommandFactory.hpp>
#include <Inspector/InspectorWidgetFactoryInterface.hpp>
#include <Process/ProcessFactory.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <iscore/plugins/customfactory/StringFactoryKey.hpp>
#include <iscore/plugins/customfactory/FactorySetup.hpp>
#include "iscore_addon_image.hpp"

#if defined(ISCORE_LIB_INSPECTOR)
#include <ImageProcess/Inspector/ImageInspectorFactory.hpp>
#endif

#include <iscore_plugin_image_commands_files.hpp>
#include <ImageProcess/ImageFactory.hpp>

iscore_addon_image::iscore_addon_image() :
    QObject {}
{
}

iscore_addon_image::~iscore_addon_image()
{

}


std::vector<std::unique_ptr<iscore::FactoryInterfaceBase>> iscore_addon_image::factories(
        const iscore::ApplicationContext& ctx,
        const iscore::AbstractFactoryKey& key) const
{
    return instantiate_factories<
            iscore::ApplicationContext,
    TL<
        FW<Process::ProcessFactory,
             Image::ProcessFactory>,
        FW<ProcessInspectorWidgetDelegateFactory,
             Image::InspectorFactory>
    >>(ctx, key);
}

std::pair<const CommandParentFactoryKey, CommandGeneratorMap> iscore_addon_image::make_commands()
{
    using namespace Image;
    std::pair<const CommandParentFactoryKey, CommandGeneratorMap> cmds{CommandFactoryName(), CommandGeneratorMap{}};

    using Types = TypeList<
#include <iscore_plugin_image_commands.hpp>
      >;
    for_each_type<Types>(iscore::commands::FactoryInserter{cmds.second});

    return cmds;
}

iscore::Version iscore_addon_image::version() const
{
    return iscore::Version{1};
}

UuidKey<iscore::Plugin> iscore_addon_image::key() const
{
    return "10edb840-28fa-4bba-8027-3eca2896180e";
}

