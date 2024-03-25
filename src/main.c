#include "greetings.h"

#include "static.h"
#include "dynamic.h"

int main(int argc, char* argv[])
{
    greet();
    dynamic_salute();
    static_salute();
    return 0;
}