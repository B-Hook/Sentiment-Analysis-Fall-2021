#include <fstream>
#include "Control.h"
#include "DSString.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

void runCatch();

int main(int argc, char** argv) {
    if (argc == 1){ runCatch(); } // Runs catch test if argc == 1
    else { Control starterObj(argv[1], argv[2], argv[3], argv[4]); } // else it sends the files to the control object
    return 0;
}
void runCatch(){ Catch::Session().run(); } // Running catch test