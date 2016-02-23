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
}
