#include <iostream>
#include "Project.h"
#include "ComplexTask.h"

int main() {
    Project project = Project();

    Actor actor1 = Actor{"A1", 5};
    Actor actor2 = Actor{"A2", 5};
    Actor actor3 = Actor{"A3", 5};

    project.addActor(actor1);
    project.addActor(actor2);
    project.addActor(actor3);

    Task task1 = Task{"Simple task1",3, 8};
    Task task2 = Task{"Simple task2",2, 15};
    Task task3 = Task{"Simple task3", 1, 4};

    ComplexTask complexTask1 = ComplexTask{"Complex task1",13, 8};
    ComplexTask complexTask2 = ComplexTask{"Complex task2",9, 20};
    ComplexTask complexTask3 = ComplexTask{"Complex task3",15, 8};

    //TODO Добавить фабрику классов
    project.addTask(&task1);
    project.addTask(&task2);
    project.addTask(&task3);
    project.addTask(&complexTask1);
    project.addTask(&complexTask2);
    project.addTask(&complexTask3);

    for (auto & i : project.getTasks()) {
        i->show();
    }


    //project.splitTasks();

    //project.distributeTasks();
}
