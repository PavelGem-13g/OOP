//
// Created by Павел on 19.12.2023.
//

#include "CollectionResultsTask.h"

void CollectionResultsTask::complete(std::shared_ptr<Actor> actor) {
    Task::complete(actor);
    complexTask->assign(actor);
}

void CollectionResultsTask::work(std::shared_ptr<Actor> actor) {
    Task::work(actor);
}

CollectionResultsTask::CollectionResultsTask() {

}

std::shared_ptr<Task> CollectionResultsTask::getComplexTask() {
    return complexTask;
}
