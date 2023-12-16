//
// Created by Павел on 14.12.2023.
//

#include <map>
#include "TaskProgressType.h"
#include "TaskType.h"

std::string GetTaskProgressTypeString(TaskProgressType entityType){
    std::map<TaskProgressType, std::string> entityTypeStrings{
            {TaskProgressType::TNone, "None"},
            {TaskProgressType::TFree, "TFree"},
            {TaskProgressType::TWork, "TWork"},
            {TaskProgressType::TComplete, "TComplete"}
    };

    return entityTypeStrings.at(entityType);
}