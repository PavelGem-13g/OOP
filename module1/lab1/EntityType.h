//
// Created by Павел on 17.10.2023.
//

#ifndef LAB1_ENTITYTYPE_H
#define LAB1_ENTITYTYPE_H


enum class EntityType{
    TNone,
    TEntity,
    TCabinet,
    TAppliance
};

std::string GetEntityTypeString(EntityType entityType);


#endif //LAB1_ENTITYTYPE_H
