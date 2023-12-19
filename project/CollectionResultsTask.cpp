//
// Created by Павел on 19.12.2023.
//

#include "CollectionResultsTask.h"

void CollectionResultsTask::complete(std::shared_ptr<Actor> actor) {
    Subtask::complete(actor);
    complexTask->assign(actor);
}

void CollectionResultsTask::work(std::shared_ptr<Actor> actor) {
    Subtask::work(actor);
    complexTask->assign(actor);
}

std::shared_ptr<Task> CollectionResultsTask::getComplexTask() {
    return complexTask;
}

CollectionResultsTask::CollectionResultsTask(std::string &name, int hours, int priority,
                                             std::shared_ptr<ComplexTask> complexTask):
        Subtask(name, hours, priority, complexTask){

}

