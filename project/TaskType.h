//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_TASKTYPE_H
#define PROJECT_TASKTYPE_H


#include <string>

enum class TaskType {
    TNone,
    TTask,
    TSubTask,
    TComplexTask
};

std::string GetTypeString(TaskType entityType);


#endif //PROJECT_TASKTYPE_H
