#pragma once
#include <ImageProcess/Commands/ImageCommandFactory.hpp>
#include <iscore/command/SerializableCommand.hpp>
#include <iscore/tools/ModelPath.hpp>

class DataStreamInput;
class DataStreamOutput;
namespace Image
{
class ProcessModel;

class SetImage final : public iscore::SerializableCommand
{
        ISCORE_COMMAND_DECL(Image::CommandFactoryName(), SetImage, "Set an image")
    public:
        EditScript(
                Path<ProcessModel>&& model,
                const QString& path);

        void undo() const override;
        void redo() const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;
        QString m_old, m_new;
};
}
