#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/serialization/JSONVisitor.hpp>
template <typename T> class Reader;
template <typename T> class Writer;

namespace Image
{
class LayerModel;
}
/////// ViewModel
template<>
void Visitor<Reader<DataStream>>::readFrom(const Image::LayerModel& lm)
{
}

template<>
void Visitor<Writer<DataStream>>::writeTo(Image::LayerModel& lm)
{
}



template<>
void Visitor<Reader<JSONObject>>::readFrom(const Image::LayerModel& lm)
{
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(Image::LayerModel& lm)
{
}
