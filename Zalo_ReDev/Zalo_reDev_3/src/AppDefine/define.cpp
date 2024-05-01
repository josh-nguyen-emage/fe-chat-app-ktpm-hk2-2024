// define.cpp

#include "define.h"

Define& Define::getInstance()
{
    static Define instance; // Static instance created only once
    return instance;
}

Define::Define() {
    backendPath  = "D:\\1 - Study\\4 - KTPM_2024\\Zalo_ReDev\\Backend";
}
