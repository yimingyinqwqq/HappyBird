//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                  MP : Happy Bird : Test Cases                            //
//                                                                          //
// Written By : Edison                 Environment : MacOSx86               //
// Date from 7/21/2021:                         Compiler : clang++          //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up                             //
//////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

//////////////////////////////////////////////////////////////////////////////
//                                 Includes                                 //
//////////////////////////////////////////////////////////////////////////////
#include "../game.hpp"
#include "../bird.hpp"

//////////////////////////////////////////////////////////////////////////////
//                                Test Cases                                //
//////////////////////////////////////////////////////////////////////////////
TEST_CASE("Default Constructor", "[Default]") {
    Game game;
    //game.running();
}

TEST_CASE("Single val Constructor", "") {

}