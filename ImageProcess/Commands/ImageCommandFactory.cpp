#include "ImageCommandFactory.hpp"
#include <iscore/command/Command.hpp>

namespace Image
{
const CommandParentFactoryKey& CommandFactoryName() {
    static const CommandParentFactoryKey key{"Image"};
    return key;
}
}
