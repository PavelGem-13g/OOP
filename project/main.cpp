#include <iostream>
#include <cassert>
#include "Project.h"
#include "ComplexTask.h"

int main() {
    Project project = Project();

    std::shared_ptr<Actor> actor1 = std::make_shared<Actor>(Actor{"A1", 5});
    std::shared_ptr<Actor> actor2 = std::make_shared<Actor>(Actor{"A2", 8});
    std::shared_ptr<Actor> actor3 = std::make_shared<Actor>(Actor{"A3", 4});

    project.addActor(actor1);
    project.addActor(actor2);
    project.addActor(actor3);

    std::shared_ptr<Task> task1 = std::make_shared<Task>(Task{"Simple task1", 3, 8});
    assert(task1->getName()=="Simple task1");

    std::shared_ptr<Task> task2 = std::make_shared<Task>(Task{"Simple task2",2, 15});
    std::shared_ptr<Task> task3 = std::make_shared<Task>(Task{"Simple task3", 1, 4});

    std::shared_ptr<ComplexTask> complexTask1 = std::make_shared<ComplexTask>(ComplexTask{"Complex task1",13, 8});
    assert(complexTask1->getName()=="Complex task1");

    std::shared_ptr<ComplexTask> complexTask2 = std::make_shared<ComplexTask>(ComplexTask{"Complex task2",9, 20});
    std::shared_ptr<ComplexTask> complexTask3 = std::make_shared<ComplexTask>(ComplexTask{"Complex task3",15, 8});

    //TODO Добавить фабрику классов
    project.addTask(task1);
    project.addTask(task2);
    project.addTask(task3);
    project.addTask(complexTask1);
    project.addTask(complexTask2);
    project.addTask(complexTask3);

    assert(complexTask1->getSubtasks().size()==4);
    //project.show();

    project.distributeTasks();
    //project.show();
}
