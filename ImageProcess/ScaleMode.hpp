#pragma once
#include <cinttypes>
namespace Image
{
enum class ScaleMode : int32_t
{
    NoScale, ScaleDisregard, ScaleSmaller, ScaleBigger
};
}
