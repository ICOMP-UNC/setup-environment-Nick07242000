#include "greetings.h"

#include "static.h"
#include "dynamic.h"

void main(int argc, char* argv[])
{
    greet();
    dynamic_salute();
    static_salute();
    return 0;
}