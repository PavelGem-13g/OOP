//
// Created by Павел on 19.12.2023.
//

#ifndef PROJECT_COLLECTIONRESULTSTASK_H
#define PROJECT_COLLECTIONRESULTSTASK_H

#include "Subtask.h"

class CollectionResultsTask : public Subtask{
public:
    CollectionResultsTask();
    CollectionResultsTask(std::string &name, int hours, int priority, ComplexTask *complexTask);
    CollectionResultsTask(const CollectionResultsTask &collectionResultsTask);

    ComplexTask* getComplexTask();

    void complete(std::shared_ptr<Actor> actor) override;
    void work(std::shared_ptr<Actor> actor) override;
};


#endif //PROJECT_COLLECTIONRESULTSTASK_H
