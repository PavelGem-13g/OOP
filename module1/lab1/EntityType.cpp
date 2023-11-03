//
// Created by Павел on 17.10.2023.
//

#include <map>
#include "EntityType.h"

#include <string>

std::string GetEntityTypeString(EntityType entityType)
{
    std::map<EntityType, std::string> entityTypeStrings{
            {EntityType::TNone, "None"},
            {EntityType::TEntity, "Entity"},
            {EntityType::TCabinet, "Cabinet"},
            {EntityType::TAppliance, "Appliance"}
    };

    return entityTypeStrings.at(entityType);
}


