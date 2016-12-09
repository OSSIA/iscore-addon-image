#pragma once
#include <ImageProcess/Commands/ImageCommandFactory.hpp>
#include <iscore/command/Command.hpp>
#include <iscore/tools/ModelPath.hpp>

#include <ImageProcess/ScaleMode.hpp>


struct DataStreamInput;
struct DataStreamOutput;
namespace Image
{
class ProcessModel;

class SetImage final : public iscore::Command
{
        ISCORE_COMMAND_DECL(Image::CommandFactoryName(), SetImage, "Set an image")
    public:
        SetImage(
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


// MOVEME

class SetImageScaleMode final : public iscore::Command
{
        ISCORE_COMMAND_DECL(Image::CommandFactoryName(), SetImageScaleMode, "Set image scale")
    public:
        SetImageScaleMode(
                Path<ProcessModel>&& model,
                ScaleMode sm);

        void undo() const override;
        void redo() const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;
        ScaleMode m_old, m_new;
};
}
