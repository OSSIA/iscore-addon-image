#pragma once
#include <ImageProcess/Commands/ImageCommandFactory.hpp>
#include <score/command/Command.hpp>
#include <score/model/path/Path.hpp>

#include <ImageProcess/ScaleMode.hpp>


struct DataStreamInput;
struct DataStreamOutput;
namespace Image
{
class ProcessModel;

class SetImage final : public score::Command
{
        SCORE_COMMAND_DECL(Image::CommandFactoryName(), SetImage, "Set an image")
    public:
        SetImage(
                const ProcessModel& model,
                const QString& path);

        void undo(const score::DocumentContext& ctx) const override;
        void redo(const score::DocumentContext& ctx) const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;
        QString m_old, m_new;
};


// MOVEME

class SetImageScaleMode final : public score::Command
{
        SCORE_COMMAND_DECL(Image::CommandFactoryName(), SetImageScaleMode, "Set image scale")
    public:
        SetImageScaleMode(
            const ProcessModel& model,
                ScaleMode sm);

        void undo(const score::DocumentContext& ctx) const override;
        void redo(const score::DocumentContext& ctx) const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;
        ScaleMode m_old, m_new;
};
}
