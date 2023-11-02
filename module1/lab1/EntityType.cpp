//
// Created by Павел on 17.10.2023.
//

#include <map>
#include "EntityType.h"

std::string GetEntityTypeString(EntityType entityType)
{
    std::map<EntityType, std::string> entityTypeStrings{
            {EntityType::TEntity, "Entity 1"},
    };

    return entityTypeStrings.at(entityType);
}

