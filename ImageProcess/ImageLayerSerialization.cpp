#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/serialization/JSONVisitor.hpp>
template <typename T> class Reader;
template <typename T> class Writer;

namespace Image
{
class Layer;
}
/////// ViewModel
template<>
void Visitor<Reader<DataStream>>::readFrom(const Image::Layer& lm)
{
}

template<>
void Visitor<Writer<DataStream>>::writeTo(Image::Layer& lm)
{
}



template<>
void Visitor<Reader<JSONObject>>::readFrom(const Image::Layer& lm)
{
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(Image::Layer& lm)
{
}
