#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/serialization/JSONVisitor.hpp>
#include <QJsonObject>
#include <QJsonValue>
#include <algorithm>

#include "ImageLayerModel.hpp"
#include "ImageModel.hpp"
#include <State/Address.hpp>
#include <iscore/serialization/JSONValueVisitor.hpp>
#include <iscore/serialization/VisitorCommon.hpp>

template<>
void Visitor<Reader<DataStream>>::readFrom_impl(const Image::ProcessModel& image)
{
    m_stream << image.imagePath();

    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(Image::ProcessModel& image)
{
    QString path;
    m_stream >> path;

    image.loadImage(path);

    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(const Image::ProcessModel& image)
{
    m_obj[strings.Path] = image.imagePath();
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(Image::ProcessModel& image)
{
    image.loadImage(m_obj[strings.Path].toString());
}
