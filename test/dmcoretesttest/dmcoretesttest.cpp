
#include "dmcoretest.h"

int main( int argc, char* argv[] ) {

    Idmcoretest* module = dmcoretestGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
