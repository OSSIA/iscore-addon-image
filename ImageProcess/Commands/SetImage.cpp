#include <ImageProcess/ImageModel.hpp>

#include "SetImage.hpp"
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/model/path/PathSerialization.hpp>
namespace Image
{
SetImage::SetImage(
    const ProcessModel& model,
    const QString& text)
  : m_model{model}
  , m_old{model.imagePath()}
  , m_new{text}
{
}

void SetImage::undo(const iscore::DocumentContext& ctx) const
{
    m_model.find(ctx).loadImage(m_old);
}

void SetImage::redo(const iscore::DocumentContext& ctx) const
{
    m_model.find(ctx).loadImage(m_new);
}

void SetImage::serializeImpl(DataStreamInput& s) const
{
    s << m_model << m_old << m_new;
}

void SetImage::deserializeImpl(DataStreamOutput& s)
{
    s >> m_model >> m_old >> m_new;
}




SetImageScaleMode::SetImageScaleMode(
    const ProcessModel& model,
    ScaleMode mode):
  m_model{model},
  m_old{model.scaleMode()},
  m_new{mode}
{
}

void SetImageScaleMode::undo(const iscore::DocumentContext& ctx) const
{
    m_model.find(ctx).setScaleMode(m_old);
}

void SetImageScaleMode::redo(const iscore::DocumentContext& ctx) const
{
    m_model.find(ctx).setScaleMode(m_new);

}

void SetImageScaleMode::serializeImpl(DataStreamInput& s) const
{
    s << m_model << (int32_t)m_old << (int32_t)m_new;
}

void SetImageScaleMode::deserializeImpl(DataStreamOutput& s)
{
    s >> m_model >> (int32_t&)m_old >> (int32_t&)m_new;
}
}
