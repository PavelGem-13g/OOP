//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_TASKPROGRESSTYPE_H
#define PROJECT_TASKPROGRESSTYPE_H


#include <string>

enum class TaskProgressType {
    TNone,
    TFree,
    TWork,
    TComplete
};

std::string GetTaskProgressTypeString(TaskProgressType entityType);


#endif //PROJECT_TASKPROGRESSTYPE_H
