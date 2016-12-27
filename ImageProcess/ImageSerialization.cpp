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

template <>
void DataStreamReader::read(const Image::ProcessModel& image)
{
    m_stream << image.imagePath();

    insertDelimiter();
}

template <>
void DataStreamWriter::writeTo(Image::ProcessModel& image)
{
    QString path;
    m_stream >> path;

    image.loadImage(path);

    checkDelimiter();
}

template <>
void JSONObjectReader::read(const Image::ProcessModel& image)
{
    obj[strings.Path] = image.imagePath();
}

template <>
void JSONObjectWriter::writeTo(Image::ProcessModel& image)
{
    image.loadImage(obj[strings.Path].toString());
}
