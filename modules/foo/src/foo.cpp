/*
  Template class
 */

#include "foo.h"
#define LOG_TAG "Foo"
#include "logger.h"


namespace threemonkeybits
{
    bool Foo::foo(int fooInt)
    {
        LOGD("Foo variable int is: %d", fooInt);
        return true;
    }
}
