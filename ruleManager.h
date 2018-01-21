//
// Created by Andrew Eeckman on 1/12/18.
//

#ifndef HOARDING_RULEMANAGER_H
#define HOARDING_RULEMANAGER_H

#include <stdbool.h>
#include "structs.h"


void readInRules(char *argv, struct rulesProperties *rules);

bool changeToBool(char* string);

#endif //HOARDING_RULEMANAGER_H
