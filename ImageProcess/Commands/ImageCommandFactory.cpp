#include "ImageCommandFactory.hpp"
#include <iscore/command/Command.hpp>

namespace Image
{
const CommandGroupKey& CommandFactoryName() {
    static const CommandGroupKey key{"Image"};
    return key;
}
}
