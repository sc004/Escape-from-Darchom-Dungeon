#ifndef ENCOUNTERFACTORY_H
#define ENCOUNTERFACTORY_H

#include <iostream>
#include <string>
#include "encounter.h"

using namespace std;
class EncounterFactory{
    public:
        EncounterFactory(){}
        ~EncounterFactory();
        virtual Encounter* makeEncounter() = 0;
};
#endif //ENCOUNTERFACTORY_H
