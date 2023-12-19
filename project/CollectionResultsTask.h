//
// Created by Павел on 19.12.2023.
//

#ifndef PROJECT_COLLECTIONRESULTSTASK_H
#define PROJECT_COLLECTIONRESULTSTASK_H

#include "Subtask.h"

class CollectionResultsTask : public Subtask{
public:
    CollectionResultsTask();
    std::shared_ptr<Task> getComplexTask();

    void complete(std::shared_ptr<Actor> actor) override;
    void work(std::shared_ptr<Actor> actor) override;
};


#endif //PROJECT_COLLECTIONRESULTSTASK_H
