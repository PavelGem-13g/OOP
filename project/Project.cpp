//
// Created by Павел on 14.12.2023.
//

#include "Project.h"
#include "ComplexTask.h"

void Project::addActor(const Actor& actor) {
    actors.emplace_back(actor);
}

void Project::splitTasks() {
    for (int i=0; i < tasks.size(); ++i) {
        if (tasks[i]->getType() == TaskType::TTask) {
            //splitTask(tasks[i]);
        }
    }
}

void Project::distributeTasks() {
    // Сортировка задач по приоритету
//    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
//        return a.getPriority() > b.getPriority();
//    });

    // Распределение задач по исполнителям
    for (const auto& task : tasks) {
        // Сортировка исполнителей по доступным часам в неделю
        std::sort(actors.begin(), actors.end(), [](const Actor& a, const Actor& b) {
            return a.getHours() > b.getHours();
        });

        // Выбор первого доступного исполнителя
        Actor& member = actors.front();
        //member.assignTask(task);
    }
}

void Project::splitTask(Task &task) {
    // Предположим, что порог времени для разделения задачи составляет 5 часов
    const int splitThreshold = 5;

    if (task.getHours() > splitThreshold) {
        Subtask subtask1{task.getPriority() + 1, splitThreshold};
        Subtask subtask2{task.getPriority() - 1, task.getHours() - splitThreshold};
        //tasks.push_back(subtask1);
        //tasks.push_back(subtask2);
    } else {
        //task.
        //tasks.push_back(Subtask{task.getPriority(), task.getHours()});
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
