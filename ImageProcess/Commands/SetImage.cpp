#include <ImageProcess/ImageModel.hpp>

#include "SetImage.hpp"
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/tools/ModelPathSerialization.hpp>
namespace Image
{
SetImage::SetImage(
    Path<ProcessModel>&& model,
    const QString& text):
  m_model{std::move(model)},
  m_new{text}
{
    m_old = m_model.find().imagePath();
}

void SetImage::undo() const
{
    m_model.find().loadImage(m_old);
}

void SetImage::redo() const
{
    m_model.find().loadImage(m_new);

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
    Path<ProcessModel>&& model,
    ScaleMode mode):
  m_model{std::move(model)},
  m_new{mode}
{
    m_old = m_model.find().scaleMode();
}

void SetImageScaleMode::undo() const
{
    m_model.find().setScaleMode(m_old);
}

void SetImageScaleMode::redo() const
{
    m_model.find().setScaleMode(m_new);

}

void SetImageScaleMode::serializeImpl(DataStreamInput& s) const
{
    s << m_model << (int)m_old << (int)m_new;
}

void SetImageScaleMode::deserializeImpl(DataStreamOutput& s)
{
    s >> m_model >> (int&)m_old >> (int&)m_new;
}
}
