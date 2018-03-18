#include <score/serialization/DataStreamVisitor.hpp>
#include <score/serialization/JSONVisitor.hpp>
#include <QJsonObject>
#include <QJsonValue>
#include <algorithm>

#include "ImageLayerModel.hpp"
#include "ImageModel.hpp"
#include <State/Address.hpp>
#include <score/serialization/JSONValueVisitor.hpp>
#include <score/serialization/VisitorCommon.hpp>

template <>
void DataStreamReader::read(const Image::ProcessModel& image)
{
    m_stream << image.imagePath();

    insertDelimiter();
}

template <>
void DataStreamWriter::write(Image::ProcessModel& image)
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
void JSONObjectWriter::write(Image::ProcessModel& image)
{
    image.loadImage(obj[strings.Path].toString());
}
