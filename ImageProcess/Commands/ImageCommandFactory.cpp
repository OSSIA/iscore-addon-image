#include "ImageCommandFactory.hpp"
#include <iscore/command/SerializableCommand.hpp>

namespace Image
{
const CommandParentFactoryKey& CommandFactoryName() {
    static const CommandParentFactoryKey key{"Image"};
    return key;
}
}
