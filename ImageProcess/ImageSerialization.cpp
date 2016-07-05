#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/serialization/JSONVisitor.hpp>
#include <QJsonObject>
#include <QJsonValue>
#include <algorithm>

#include "ImageLayerModel.hpp"
#include "ImageModel.hpp"
#include <State/Address.hpp>
#include <iscore/plugins/documentdelegate/plugin/ElementPluginModelList.hpp>
#include <iscore/serialization/JSONValueVisitor.hpp>
#include <iscore/serialization/VisitorCommon.hpp>
#include <iscore/tools/std/StdlibWrapper.hpp>

template<>
void Visitor<Reader<DataStream>>::readFrom_impl(const Image::ProcessModel& image)
{
    readFrom(*image.pluginModelList);

    m_stream << image.imagePath();

    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(Image::ProcessModel& image)
{
    image.pluginModelList = new iscore::ElementPluginModelList{*this, &image};

    QString path;
    m_stream >> path;

    image.loadImage(path);

    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(const Image::ProcessModel& image)
{
    m_obj["PluginsMetadata"] = toJsonValue(*image.pluginModelList);

    m_obj["Path"] = image.imagePath();
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(Image::ProcessModel& image)
{
    Deserializer<JSONValue> elementPluginDeserializer(m_obj["PluginsMetadata"]);
    image.pluginModelList = new iscore::ElementPluginModelList{elementPluginDeserializer, &image};

    image.loadImage(m_obj["Path"].toString());
}
