/*
  Template class
 */

#include "var.h"
#define LOG_TAG "Var"
#include "logger.h"


namespace threemonkeybits
{
    bool Var::foo(int fooInt)
    {
        LOGD("Var variable int is: %d", fooInt);
        return true;
    }
}
