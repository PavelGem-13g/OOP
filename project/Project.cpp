//
// Created by Павел on 14.12.2023.
//

#include "Project.h"
#include "ComplexTask.h"

void Project::addActor(const Actor& actor) {
    actors.emplace_back(actor);
}

void Project::distributeTasks() {
    // Сортировка задач по приоритету
    sortTasksAscending();
    std::vector<Task> simpleTasks = std::vector<Task>();
    for (auto task: tasks) {
        switch (task->getType()) {
            case TaskType::TTask:
                simpleTasks.push_back(*task);
                break;
            case TaskType::TComplexTask:
                for (auto subtask: dynamic_cast<ComplexTask*>(task)->getSubtasks()) {
                    simpleTasks.push_back(subtask);
                }
                break;
            case TaskType::TNone:
                break;
            case TaskType::TSubTask:
                break;
        }
    }

    // Распределение задач по исполнителям
    for (const auto task : simpleTasks) {
        // Сортировка исполнителей по доступным часам в неделю
        std::sort(actors.begin(), actors.end(), [](const Actor& a, const Actor& b) {
            return a.getHours() > b.getHours();
        });

        // Выбор первого доступного исполнителя
        Actor& member = actors.front();
        member.assignTask(task);
    }
}


void Project::addTask(Task *task) {
//    if(task->getHours()>threshold){
//        ComplexTask complexTask = ComplexTask(*task);
//        tasks.push_back(&complexTask);
//    }
//    else{
//        tasks.push_back(task);
//    }
    tasks.push_back(task);
}

void Project::addTask(const std::string& name, int hours, int priority) {
    Task task = Task{name, hours, priority};
    addTask(&task);
}

std::vector<Actor> Project::getActors() const{
    return actors;
}

std::vector<Task *> Project::getTasks() const{
    return tasks;
}

void Project::sortTasksAscending() {
    auto compare = [](Task *a, const Task *b) {
        if(a->getPriority() != b->getPriority()){
            return a->getPriority() > b->getPriority();
        }
        if(a->getHours() != b->getHours()){
            return a->getHours() > b->getHours();
        }
        if(a->getType() != b->getType()){
            return a->getType() > b->getType();
        }
        return a->getProgress() > b->getProgress();
    };
    sortTasks(compare);
}

template<class Compare>
void Project::sortTasks(Compare comparator) {
    std::sort(tasks.begin(), tasks.end(), comparator);
}

void Project::show() {
    std::cout<<"Tasks"<<std::endl;
    for (auto& item: tasks) {
        item->show();
    }

    std::cout<<"Actors"<<std::endl;
    for (auto& item: actors) {
        item.show();
    }
}
