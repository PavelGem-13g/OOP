#include <iostream>
#include <cassert>
#include "Project.h"
#include "ComplexTask.h"

int main() {
    Actor act1 = Actor();
    assert(act1.getName()=="Actor");
    assert(act1.getHours()==10);

    Actor act2 = Actor("Name", 20);
    assert(act2.getName()=="Name");
    assert(act2.getHours()==20);

    Actor act3 = Actor(act2);
    assert(act3.getName()=="Name");
    assert(act3.getHours()==20);

    act3.changeHours(-5);
    assert(act3.getHours()==15);



    Project proj = Project();
    assert(proj.getThreshold()==5);

    Project proj2 = Project(10);
    assert(proj2.getThreshold()==10);

    Project proj3 = Project(proj2);
    assert(proj3.getThreshold()==10);

    Task simpleTask = Task();
    assert(simpleTask.getName()=="Name");
    assert(simpleTask.getHours()==0);
    assert(simpleTask.getPriority()==0);
    assert(simpleTask.getProgress()==TaskProgressType::TFree);


    Task simpleTask2 = Task("Name2", 10, 4, TaskProgressType::TWork);
    assert(simpleTask2.getName()=="Name2");
    assert(simpleTask2.getHours()==10);
    assert(simpleTask2.getPriority()==4);
    assert(simpleTask2.getProgress()==TaskProgressType::TWork);

    Task simpleTask3 = Task(simpleTask2);
    assert(simpleTask3.getName()=="Name2");
    assert(simpleTask3.getHours()==10);
    assert(simpleTask3.getPriority()==4);
    assert(simpleTask3.getProgress()==TaskProgressType::TWork);

    ComplexTask hardTask1 = ComplexTask();
    assert(hardTask1.getName()=="Name");
    assert(hardTask1.getHours()==0);
    assert(hardTask1.getPriority()==0);
    assert(hardTask1.getProgress()==TaskProgressType::TFree);

    ComplexTask hardTask2 = ComplexTask("Name2", 10, 4);
    assert(hardTask2.getName()=="Name2");
    assert(hardTask2.getHours()==10);
    assert(hardTask2.getPriority()==4);
    assert(hardTask2.getProgress()==TaskProgressType::TFree);


    Project project = Project();


    std::shared_ptr<Actor> actor1 = std::make_shared<Actor>(Actor{"A1", 5});
    std::shared_ptr<Actor> actor2 = std::make_shared<Actor>(Actor{"A2", 8});
    std::shared_ptr<Actor> actor3 = std::make_shared<Actor>(Actor{"A3", 4});

    assert(actor1.use_count()==1);

    project.addActor(actor1);
    project.addActor(actor2);
    project.addActor(actor3);


    std::shared_ptr<Task> task1 = std::make_shared<Task>(Task{"Simple task1", 3, 8});
    assert(task1->getName()=="Simple task1");

    std::shared_ptr<Task> task2 = std::make_shared<Task>(Task{"Simple task2",2, 15});
    std::shared_ptr<Task> task3 = std::make_shared<Task>(Task{"Simple task3", 1, 4});

    std::shared_ptr<ComplexTask> complexTask1 = std::make_shared<ComplexTask>(ComplexTask{"Complex task1",13, 8});
    assert(complexTask1->getName()=="Complex task1");

    //project.show();

    std::shared_ptr<ComplexTask> complexTask2 = std::make_shared<ComplexTask>(ComplexTask{"Complex task2",9, 20});
    std::shared_ptr<ComplexTask> complexTask3 = std::make_shared<ComplexTask>(ComplexTask{"Complex task3",15, 8});

    project.addTask(task1);
    project.addTask(task2);
    project.addTask(task3);
    project.addTask(complexTask1);
    project.addTask(complexTask2);
    project.addTask(complexTask3);

    project.distributeTasks();

    assert(complexTask1->getSubtasks().size()==4);

    assert(complexTask2->getActors().size()==3);
    assert(complexTask2->getActors().count(actor1)==1);
    assert(complexTask2->getActors().count(actor2)==1);
    assert(complexTask2->getActors().count(actor3)==1);

    assert(complexTask2->getProgress()==TaskProgressType::TComplete);
    assert(complexTask2->getSubtasks()[0]->getProgress()==TaskProgressType::TComplete);
    assert(complexTask2->getSubtasks()[1]->getProgress()==TaskProgressType::TComplete);
    assert(complexTask2->getSubtasks()[2]->getProgress()==TaskProgressType::TComplete);

    assert(complexTask3->getActors().size()==3);
    assert(complexTask3->getActors().count(actor1)==1);
    assert(complexTask3->getActors().count(actor2)==1);
    assert(complexTask3->getActors().count(actor3)==1);

    assert(simpleTask.getProgress()==TaskProgressType::TFree);

    assert(complexTask3->getSubtasks().size()==4);
    assert(complexTask3->getSubtasks()[0]->getType()==TaskType::TSubTask);

    //project.show();
}
