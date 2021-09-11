#include <iostream>
#include <fstream>
#include "Control.h"
#include "DSString.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

void runCatch();

int main(int argc, char** argv) {
    for(int i = 0; i < argc; i++){
        std::cout <<"argv["<< i << "]: " << argv[i] << std::endl;
    }
    if (argc == 1){ runCatch(); }
    else { Control starterObj(argv[1], argv[2], argv[3], argv[4]); }

    return 0;
}
void runCatch(){ Catch::Session().run(); }