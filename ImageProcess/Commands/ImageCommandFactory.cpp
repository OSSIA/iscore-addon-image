#include "ImageCommandFactory.hpp"
#include <score/command/Command.hpp>

namespace Image
{
const CommandGroupKey& CommandFactoryName() {
    static const CommandGroupKey key{"Image"};
    return key;
}
}
