//
// Created by Павел on 14.12.2023.
//

#include "Project.h"
#include "ComplexTask.h"

void Project::addActor(const std::shared_ptr<Actor> actor) {
    actors.push_back(actor);
}

void Project::distributeTasks() {
    // Сортировка задач по приоритету
    sortTasksDescending();
    std::vector<std::shared_ptr<Task>> simpleTasks = getSimpleTasks();

// Распределение задач по исполнителям
    for (auto& task : simpleTasks) {
        // Сортировка исполнителей по доступным часам в неделю
        sortActorsDescending();

        // Выбор первого доступного исполнителя
        std::shared_ptr<Actor> actor = actors.front();
        if (task->check(actor)) {
            task->assign(actor);
        }
    }
}


void Project::addTask(const std::shared_ptr<Task> task) {
    tasks.push_back(task);
}

void Project::addTask(const std::string& name, int hours, int priority) {
    auto task = Task{name, hours, priority};
    auto task_ptr = std::make_shared<ComplexTask>(task);
    addTask(task_ptr);
}

std::vector<std::shared_ptr<Actor>> Project::getActors() const{
    return actors;
}

std::vector<std::shared_ptr<Task>> Project::getTasks() const{
    return tasks;
}

void Project::sortTasksDescending() {
    auto compare = [](const std::shared_ptr<Task> a, const std::shared_ptr<Task> b) {
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
void Project::sortTasks(const Compare &comparator) {
    std::sort(tasks.begin(), tasks.end(), comparator);
}

void Project::show() {
    std::cout<<"Tasks"<<std::endl;
    for (auto& item: tasks) {
        item->show();
    }

    std::cout<<"Actors"<<std::endl;
    for (auto& item: actors) {
        item->show();
    }
}

std::vector<std::shared_ptr<Task>> Project::getSimpleTasks() {
    std::vector<std::shared_ptr<Task>> result;

    for (const auto& task : tasks) {
        switch (task->getType()) {
            case TaskType::TTask:
                result.push_back(task);
                break;
            case TaskType::TComplexTask: {
                auto complexTask = std::dynamic_pointer_cast<ComplexTask>( task);
                auto subtasks = complexTask->getSubtasks();
                result.insert(result.end(), subtasks.begin(), subtasks.end());
                break;
            }
            case TaskType::TNone:
                break;
            case TaskType::TSubTask:
                break;
        }
    }
    return result;
}

template<class Compare>
void Project::sortActors(const Compare &comparator) {
    std::sort(actors.begin(), actors.end(), comparator);
}

void Project::sortActorsDescending() {
    auto compare = [](const std::shared_ptr<Actor> a, const std::shared_ptr<Actor> b) {
        if(a->getHours() != b->getHours()){
            return a->getHours() > b->getHours();
        }
        return a->getName() > b->getName();
    };
    sortActors(compare);
}
