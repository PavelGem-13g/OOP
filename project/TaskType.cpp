//
// Created by Павел on 14.12.2023.
//

#include <map>
#include "TaskType.h"

std::string GetTaskTypeString(TaskType entityType){
    std::map<TaskType, std::string> entityTypeStrings{
            {TaskType::TNone, "None"},
            {TaskType::TTask, "TTask"},
            {TaskType::TSubTask, "TSubTask"},
            {TaskType::TComplexTask, "TComplexTask"}
    };

    return entityTypeStrings.at(entityType);
}