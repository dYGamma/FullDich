// ���� � ������������; ������� � �����������
#include <iostream>
#include <string>
#include <clocale>
#include <random>

struct Task 
{
	std::string taskName; 
	uint16_t priority; 
	uint16_t taskTime; 
	uint16_t durationTime; 
};

void showTask(Task* task) 
{
	std::cout << "�������� ������: " << task->taskName << " ����� ����������� ������: " << task->taskTime << " ��������� ������: "
		<< task->priority << " ����� ������: " << task->durationTime << std::endl;
}

struct TaskList // ��������� ����������� ������������ ������ � ����
{
	Task* taskValues; 
	TaskList* next;
};

bool isEmpty(TaskList* head) 
{
	return head == nullptr; 
}

uint16_t popPriorityFrontTask(TaskList* head) 
{
	return head->taskValues->priority; 
}

void addTaskBack(TaskList*& head, Task* new_task) 
{
	if (head == nullptr)
	{
		head = new TaskList(); 
		head->taskValues = new_task; 
		head->next = nullptr; 
	}
	else
	{
		TaskList* tmp = head; 
		while (tmp->next != nullptr) 
			tmp = tmp->next;

		tmp->next = new TaskList();
		tmp = tmp->next;

		tmp->taskValues = new_task;
		tmp->next = nullptr; 
	}
}

void addTaskFront(TaskList*& head, Task* new_task) 
{
	if (head == nullptr) 
	{
		head = new TaskList();
		head->taskValues = new_task; 
		head->next = nullptr;
	}
	else
	{
		TaskList* tmp = head; 

		TaskList* new_head = new TaskList(); 
		new_head->taskValues = new_task; 
		new_head->next = head; 
		head = new_head; 
	}
}

Task* getTaskFront(TaskList*& head) 
{
	if (head != nullptr) 
	{
		Task* ret_task = head->taskValues; 
		TaskList* tmp_head = head;
		head = head->next; 
		delete[] tmp_head; 
		return ret_task; 
	}
	return nullptr; 
}

void showStruct(TaskList* head) 
{
	TaskList* tmp_head = head;
	while (tmp_head != nullptr) 
	{
		showTask(tmp_head->taskValues); 
		tmp_head = tmp_head->next; 
	}
}

struct Queue // ��������� ����������� ����������� �������
{
	uint16_t size; // ������ �������
	uint16_t count; // ���������� ��������� � �������
	Task** tasks; // ������ �����
};

void initQueue(Queue*& head, const uint32_t& size) 
{
	head = head == nullptr ? new Queue() : head; 
	head->size = size; 
	head->count = 0; 
	head->tasks = new Task * [size];
}

void freeQueue(Queue*& head) 
{
	delete[] head->tasks;
	delete head;
}

uint16_t popPriorityFrontTaskQueue(Queue* head) 
{
	return head->tasks[0]->priority; 
}

bool isEmpty(Queue* head) 
{
	return head->count == 0;
}

void showQueue(Queue* head) 
{
	for (uint16_t i = 0; i < head->count; i++)
		showTask(head->tasks[i]);
}

bool pushToQueue(Queue*& head, Task* new_task) 
{
	if (isEmpty(head)) 
	{
		head->tasks[0] = new_task; 
	}
	else 
	{
		if (head->count == head->size) 
			return false; 
		head->tasks[head->count] = new_task; 
	}
	head->count++; 
	return true; 
}

Task* getFromQueueFront(Queue*& head) 
{
	if (!isEmpty(head)) 
	{
		Task* ret_task = head->tasks[0]; 

		for (int i = 0; i < head->size - 1; i++)
			head->tasks[i] = head->tasks[i + 1]; 

		head->count--; 
		return ret_task; 
	}
	return nullptr; 
}

void fromTaskGeneratorToQueue(TaskList*& generator, TaskList*& backup, Queue*& queueF, const uint16_t& timer)
{
	while (!isEmpty(backup))
	{
		Task* task = getTaskFront(backup); 
		bool isAddSuccess = pushToQueue(queueF, task); 
		if (!isAddSuccess)
		{
			addTaskFront(backup, task); 
		}
	}
	while (!isEmpty(generator) && (generator->taskValues->taskTime == timer)) 
	{
		Task* task = getTaskFront(generator); 
		bool isAddSuccess = pushToQueue(queueF, task); 
		if (!isAddSuccess) 
		{
			addTaskBack(backup, task);
		}
	}
}

void taskDistributor(TaskList*& stackS0, TaskList*& stackS1, Queue*& queueF)
{
	if (!isEmpty(queueF)) 
	{
		if (isEmpty(stackS0)) 
		{
			addTaskFront(stackS0, getFromQueueFront(queueF)); 
		}
		else 
		{
			if (popPriorityFrontTaskQueue(queueF) <= popPriorityFrontTask(stackS0)) 
			{
				addTaskFront(stackS0, getFromQueueFront(queueF));  
			}
			else 
			{
				addTaskFront(stackS1, getFromQueueFront(queueF)); 
			}
		}
	}
}

void fromStackToProcessor(TaskList*& stackS0, TaskList*& stackS1, Task*& processorP) 
{
	if (processorP == nullptr) 
	{
		if (!isEmpty(stackS0)) 
		{
			processorP = getTaskFront(stackS0); 
		}
		else if (!isEmpty(stackS1))
		{
			processorP = getTaskFront(stackS1); 
		}
	}
}

void processorFOperation(Task*& processorP)
{
	if (processorP != nullptr) 
	{
		if (processorP->durationTime)
		{
			processorP->durationTime--; 
		}
		if (processorP->durationTime <= 0) 
		{
			delete processorP; 
			processorP = nullptr; 
		}
	}
}

void generateNewTask(TaskList*& generator) 
{
	static uint16_t id = 6U; // ����������� ���������� ��� �������� id ������
	static uint16_t timer = 6U; // ����������� ���������� ��� �������� id ������
	const uint16_t timer_end = 10U; // ����� ������� ��� ��������� ����� ������
	if (timer <= timer_end) // ���� ������� ����� ������ ����� ������� ����� ���������, �� ������������ ����� ������
	{
		static std::random_device dev;
		std::mt19937 rng(dev()); // ��������� ��������������� ����� �� ������ ����� ��������
		std::uniform_int_distribution<uint16_t> priority(1, 3); // ��������� ����������. ����������� ������������� �� 1 �� 3
		std::uniform_int_distribution<uint16_t> taskTime(timer, timer + 1U); // ��������� ������� �����������. ����������� ������������� �� �������� ������� �� ��������+1;
		std::uniform_int_distribution<uint16_t> durationTime(3, 10); // ��������� ������������ ����������. ����������� ������������� �� 3 �� 10
		Task* new_task = new Task(); // �������� ����� ������
		new_task->taskName = "Task " + std::to_string(id); // �������� ������
		new_task->priority = priority(rng); // ���������
		new_task->taskTime = taskTime(rng); // ������ �����������
		new_task->durationTime = durationTime(rng);  // ������������ ����������
		addTaskBack(generator, new_task); // ���������� ����� ������ � ���������
		id++; // ���������� id ������ �� 1
		timer++; // ���������� ������� ����������� �� 1

	}
}

void processorLoop(TaskList*& IncomingTask)
{
	TaskList* StackS0 = nullptr;
	TaskList* StackS1 = nullptr;
	TaskList* backup = nullptr; 
	Queue* queueF = nullptr; 
	initQueue(queueF, 2); 

	Task* processorP = nullptr; 

	int timer = 1;
	while (true)
	{
		fromTaskGeneratorToQueue(IncomingTask, backup, queueF, timer); 
		taskDistributor(StackS0, StackS1, queueF); 
		fromStackToProcessor(StackS0, StackS1, processorP); 

		std::cout << std::endl << "���� " << timer << " ����" << std::endl;
		if (!isEmpty(IncomingTask)) 
		{
			std::cout << "������� �������" << std::endl;
			showStruct(IncomingTask); 
		}
		if (!isEmpty(queueF)) 
		{
			std::cout << "���������� ������� F" << std::endl;
			showQueue(queueF);
		}
		if (!isEmpty(backup)) 
		{
			std::cout << "������� �� �������� � ������� � ���������� �� ��������: " << std::endl;
			showStruct(backup); 
		}
		if (!isEmpty(StackS0)) 
		{
			std::cout << "���������� ����� S0" << std::endl;
			showStruct(StackS0); 
		}
		if (!isEmpty(StackS1)) 
		{
			std::cout << "���������� ����� S1 " << std::endl;
			showStruct(StackS1); 
		}
		if (processorP != nullptr) 
		{
			std::cout << "���������� ���������� P" << std::endl;
			showTask(processorP); 
		}
		else 
		{
			std::cout << "��������� ��������" << std::endl;
		}

		processorFOperation(processorP); 
		timer++; 
		if (isEmpty(IncomingTask) && isEmpty(backup) && isEmpty(queueF) && isEmpty(StackS0) && isEmpty(StackS1) && processorP == nullptr) 
			break; 
		generateNewTask(IncomingTask); 
	}
	freeQueue(queueF); 
}

void exec()
{
	// ������� ������
	{
		//TaskList* tl = nullptr;
		//addTaskBack(tl, new Task{ "Task 1", 1, 1, 9 });
		//addTaskBack(tl, new Task{ "Task 2", 3, 2, 7 });
		//addTaskBack(tl, new Task{ "Task 3", 2, 3, 5 });
		//addTaskBack(tl, new Task{ "Task 4", 3, 4, 3 });
		//addTaskBack(tl, new Task{ "Task 5", 1, 5, 10 });
		//showStruct(tl);
		//processorLoop(tl);
	}
	// ������ � ������������� �������
	{
		TaskList* tl = nullptr;
		addTaskBack(tl, new Task{ "Task 1", 1, 1, 9 });
		addTaskBack(tl, new Task{ "Task 2", 3, 2, 7 });
		addTaskBack(tl, new Task{ "Task 3", 2, 2, 10 });
		addTaskBack(tl, new Task{ "Task 4", 3, 2, 4 });
		addTaskBack(tl, new Task{ "Task 5", 2, 3, 5 });
		addTaskBack(tl, new Task{ "Task 6", 1, 4, 3 });
		addTaskBack(tl, new Task{ "Task 7", 1, 5, 10 });
		showStruct(tl);
		processorLoop(tl);
	}
}

int main()
{
	setlocale(LC_ALL, "");
	exec();
	return 0;
}