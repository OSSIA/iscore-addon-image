#pragma once
#include <iscore/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/GUIApplicationContextPlugin_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/CommandFactory_QtInterface.hpp>
#include <QObject>
#include <utility>
#include <vector>

#include <iscore/application/ApplicationContext.hpp>
#include <iscore/command/CommandGeneratorMap.hpp>
#include <iscore/command/Command.hpp>
#include <iscore/plugins/customfactory/FactoryInterface.hpp>

class iscore_addon_image final :
        public QObject,
        public iscore::Plugin_QtInterface,
        public iscore::FactoryInterface_QtInterface,
        public iscore::CommandFactory_QtInterface
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID FactoryInterface_QtInterface_iid)

        Q_INTERFACES(
                iscore::Plugin_QtInterface
                iscore::FactoryInterface_QtInterface
                iscore::CommandFactory_QtInterface
                )

        ISCORE_PLUGIN_METADATA(1, "10edb840-28fa-4bba-8027-3eca2896180e")

    public:
        iscore_addon_image();
        virtual ~iscore_addon_image();

    private:
        // Process & inspector
        std::vector<std::unique_ptr<iscore::InterfaceBase>> factories(
                const iscore::ApplicationContext& ctx,
                const iscore::InterfaceKey& factoryName) const override;

        // CommandFactory_QtInterface interface
        std::pair<const CommandGroupKey, CommandGeneratorMap> make_commands() override;
};
