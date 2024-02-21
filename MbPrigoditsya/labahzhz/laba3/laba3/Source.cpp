// main.cpp
// Стек – динамический; очередь – статическая
#include <iostream>
#include <string>
#include <clocale>
#include <random>

struct Task // Структура Задача
{
	std::string taskName; // Название задачи
	uint16_t priority; // Приоритет
	uint16_t taskTime; // Момент поступления
	uint16_t durationTime; // Длительность выполнения
};

void showTask(Task* task) // Функция вывода информации о Задаче
{
	std::cout << "Название задачи: " << task->taskName << " Время поступления задачи: " << task->taskTime << " Приоритет задачи: "
		<< task->priority << " Такты задачи: " << task->durationTime << std::endl;
}

struct TaskList // Структура реализующая динамический Список и Стек
{
	Task* taskValues; // Указатель на Задачу
	TaskList* next; // Указатель на следующий узел
};

bool isEmpty(TaskList* head) // Функция определения пустоты
{
	return head == nullptr; // Если указатель нулевой, то очердь пуста, иначе нет
}

uint16_t popPriorityFrontTask(TaskList* head) // Функцция возвращающая приоритет первого элемента
{
	return head->taskValues->priority; // Вернуть значение приоритета первого элемента
}

void addTaskBack(TaskList*& head, Task* new_task) // Функция добавления нового узла в список
{
	if (head == nullptr) // Если голова списка пустой указатель - то нужно выделить под нее памятьы
	{
		head = new TaskList(); // Выделение памяти под узел головы
		head->taskValues = new_task; // Инициализация указателя задачи в новом узле
		head->next = nullptr; // Инициализация указателя на следующий узел пустным указателем
	}
	else
	{
		TaskList* tmp = head; // Временный указатель для хранения адреса головы
		while (tmp->next != nullptr) // Пока следующий указатель не пустой
			tmp = tmp->next; // Обновление временного указателя на следующий узел

		tmp->next = new TaskList(); // Выделение памяти под следующий узел
		tmp = tmp->next; // Переход с только что созданному узлу

		tmp->taskValues = new_task; // Инициализация указателя задачи в новом узле
		tmp->next = nullptr; // Инициализация указателя на следующий узел пустным указателем
	}
}

void addTaskFront(TaskList*& head, Task* new_task) // Функция добавления нового узла в список
{
	if (head == nullptr) // Если голова списка пустой указатель - то нужно выделить под нее памятьы
	{
		head = new TaskList(); // Выделение памяти под узел головы
		head->taskValues = new_task; // Инициализация указателя задачи в новом узле
		head->next = nullptr; // Инициализация указателя на следующий узел пустным указателем
	}
	else
	{
		TaskList* tmp = head; // Временный указатель для хранения адреса головы

		TaskList* new_head = new TaskList(); // Выделение памяти под узел новой головы
		new_head->taskValues = new_task; // Инициализация указателя задачи в узле
		new_head->next = head; // Инициализация указателя на следующий узел прошлой головой
		head = new_head; // Обновление указателя головы на новую
	}
}

Task* getTaskFront(TaskList*& head) // Функция взятия задачи из списка спереди
{
	if (head != nullptr) // Если голова списка не пустой указатель
	{
		Task* ret_task = head->taskValues; // Переменная для хранения указателя на Задачу
		TaskList* tmp_head = head; // Временный указатель для головы списка
		head = head->next; // Обновить указатель головы стека
		delete[] tmp_head; // Очистить память прошлой головы стека
		return ret_task; // Вернуть Задачу
	}
	return nullptr; // Вернуть пустой указатель
}

void showStruct(TaskList* head) // Функция вывода содержимого структуры
{
	TaskList* tmp_head = head; // Временный указатель для хранения адреса головы
	while (tmp_head != nullptr) // Пока указатель не пустой
	{
		showTask(tmp_head->taskValues); // Вывод задачи
		tmp_head = tmp_head->next; // Обновить временный указатель головы стека
	}
}

struct Queue // Структура реализующая статическую Очередь
{
	uint16_t size; // Размер очереди
	uint16_t count; // Количество элементов в очереди
	Task** tasks; // Массив задач
};

void initQueue(Queue*& head, const uint32_t& size) // Функция инициализации очереди
{
	head = head == nullptr ? new Queue() : head; // Если под указатель головы не была выделена память, то ее нужно выделить, иначе оставить уже существующий
	head->size = size;  // Максимальный размер очереди
	head->count = 0; // Текущее количство элементов в очереди 0
	head->tasks = new Task * [size]; // Выделение памяти под очередь
}

void freeQueue(Queue*& head) // Функция очистки очереди
{
	delete[] head->tasks;
	delete head;
}

uint16_t popPriorityFrontTaskQueue(Queue* head) // Функцция возвращающая приоритет первого элемента очереди
{
	return head->tasks[0]->priority; // Вернуть значение приоритета первого элемента
}

bool isEmpty(Queue* head) // Функция определения пуста ли очередь
{
	return head->count == 0; // Если количество элементов очереди равно 0, то очердь пуста, иначе нет
}

void showQueue(Queue* head) // Функция вывода элементов очереди
{
	for (uint16_t i = 0; i < head->count; i++)
		showTask(head->tasks[i]);
}

bool pushToQueue(Queue*& head, Task* new_task) // Функция добавления задачи в очередь
{
	if (isEmpty(head)) // Если очередь пустая
	{
		head->tasks[0] = new_task; // Добавить задачу в начало
	}
	else // Если очередь не пустая
	{
		if (head->count == head->size) // Если количество элементов равно максимальному размеру очереди
			return false; // Добавление не удалось
		head->tasks[head->count] = new_task; // Добавить задачу в конец очереди
	}
	head->count++; // Увеличить количество элементов в очереди на 1
	return true; // Добавление прошло успешно
}

Task* getFromQueueFront(Queue*& head) // Функция получения первого элемента из очереди
{
	if (!isEmpty(head)) // Если очередь не пуста
	{
		Task* ret_task = head->tasks[0]; // Переменная для хранения указателя на первую Задачу

		for (int i = 0; i < head->size - 1; i++)
			head->tasks[i] = head->tasks[i + 1]; // Сдвинуть очередь влево

		head->count--; // Уменьшить количество элементов в очереди на 1
		return ret_task; // Вернуть Задачу
	}
	return nullptr; // Вернуть пустой указатель
}

void fromTaskGeneratorToQueue(TaskList*& generator, Queue*& queueF, const uint16_t& timer) // Функция толкающая задачу из генератора в очередь
{
	while (!isEmpty(generator) && (generator->taskValues->taskTime == timer)) // Пока генератор не пустой и время поступления задачи совпадает с таймером
	{
		Task* task = getTaskFront(generator); // Получить задачу из генератора
		bool isAddSuccess = pushToQueue(queueF, task); // Отправить задачу из генератора в очередь F 
		if (!isAddSuccess) // Если добавление в очередь прошло не успешно
		{
			std::cout << "Задача '" << task->taskName << "' не была добавлена в очередь из-за переполнения и проигнорировалась." << std::endl; // Добавить задачу на хранение, чтобы потом попробовать ее еще раз добавить в очередь
			delete task;
		}
	}
}

void taskDistributor(TaskList*& stackS0, TaskList*& stackS1, Queue*& queueF)
{
	if (!isEmpty(queueF)) // Если очередь F не пустая
	{
		if (isEmpty(stackS0)) // Если стек S0 оказался пустым
		{
			addTaskFront(stackS0, getFromQueueFront(queueF)); // То положить в стек S0 задачу из очереди
		}
		else // Если стек S0 не пустой
		{
			if (popPriorityFrontTaskQueue(queueF) <= popPriorityFrontTask(stackS0)) // Если приоритет новой задачи равен или больше приоритета стека S0 (1<=2)
			{
				addTaskFront(stackS0, getFromQueueFront(queueF));  // То положить в стек S0 задачу из очереди
			}
			else // Иначе, если приоритет оказался ниже, чем приоритет стека S0 (2>3)
			{
				addTaskFront(stackS1, getFromQueueFront(queueF)); // То положить в стек S1 задачу из очереди
			}
		}
	}
}

void fromStackToProcessor(TaskList*& stackS0, TaskList*& stackS1, Task*& processorP) // Функция толкающая задачу из стека в процессор
{
	if (processorP == nullptr) // Если процессор не содержит задачу (указатель нулевой)
	{
		if (!isEmpty(stackS0)) // Если стек S0 не пустой
		{
			processorP = getTaskFront(stackS0); // Отправить задачу из стека S0 в процессор P
		}
		else if (!isEmpty(stackS1)) // Если стек S1 не пустой
		{
			processorP = getTaskFront(stackS1); // Отправить задачу из стека S1 в процессор P
		}
	}
}

void processorFOperation(Task*& processorP) // Функция работы процессора
{
	if (processorP != nullptr) // Если процессор содержит задачу (указатель не нулевой)
	{
		if (processorP->durationTime) // Если время выполнения не равно 0
		{
			processorP->durationTime--; // Декремент времени (Уменьшение на 1)
		}
		if (processorP->durationTime <= 0) // Если время выполнения задачи меньше равно 0
		{
			delete processorP; // Удаляем задачу из памяти
			processorP = nullptr; // Делаем указатель процессора P на задачу нулевым
		}
	}
}

void generateNewTask(TaskList*& generator) // Функция генерации новой задачи
{
	static uint16_t id = 6U; // Статическая переменная для хранения id задачи
	static uint16_t timer = 6U; // Статическая переменная для хранения id задачи
	const uint16_t timer_end = 7U; // Конец времени для генерации новой задачи
	if (timer <= timer_end) // Если текущее время меньше равно времени конца генерации, то генерировать новую задачу
	{
		static std::random_device dev;
		std::mt19937 rng(dev()); // Генератор псевдослучайных чисел на основе вихря Мерсенна
		std::uniform_int_distribution<uint16_t> priority(1, 3); // Генератор приоритета. Равномерное распределение от 1 до 3
		std::uniform_int_distribution<uint16_t> taskTime(timer, timer + 1U); // Генератор момента поступления. Равномерное распределение от текущего времени до текущего+1;
		std::uniform_int_distribution<uint16_t> durationTime(3, 10); // Генератор длительности выполнения. Равномерное распределение от 3 до 10
		Task* new_task = new Task(); // Создание новой задачи
		new_task->taskName = "Task " + std::to_string(id); // Навзание задачи
		new_task->priority = priority(rng); // Приоритет
		new_task->taskTime = taskTime(rng); // Момент поступления
		new_task->durationTime = durationTime(rng);  // Длительность выполнения
		addTaskBack(generator, new_task); // Добавление новой задачи в генератор
		id++; // Увеличение id задачи на 1
		timer++; // Увеличение времени поступления на 1
	}
}

void processorLoop(TaskList*& IncomingTask)
{
	TaskList* StackS0 = nullptr; // Стек S0
	TaskList* StackS1 = nullptr; // Стек S1
	Queue* queueF = nullptr; // Очередь F
	initQueue(queueF, 2); // Инициализация очереди размером 2 элемента

	Task* processorP = nullptr; // Процессор P

	int timer = 1;
	while (true)
	{
		std::cout << std::endl << "Идет " << timer << " такт" << std::endl;
		fromTaskGeneratorToQueue(IncomingTask, queueF, timer); // Вызов функции продвижения задачи из генератора в очередь
		taskDistributor(StackS0, StackS1, queueF); // Вызов функции распределителя задач из очереди в стеки
		fromStackToProcessor(StackS0, StackS1, processorP); // Вызов функции продвижения задачи из стека в процессор

		if (!isEmpty(IncomingTask)) // Если генератор задач не пустой
		{
			std::cout << "Входные задания" << std::endl;
			showStruct(IncomingTask); // Вывести содержимое генератора задач
		}
		if (!isEmpty(queueF)) // Если очередь F не свободна
		{
			std::cout << "Содержимое очереди F" << std::endl;
			showQueue(queueF); // Вывести содержимое очереди F
		}
		if (!isEmpty(StackS0)) // Если стек S0 не свободен
		{
			std::cout << "Содержимое стэка S0" << std::endl;
			showStruct(StackS0); // Вывести содержимое стека S0
		}
		if (!isEmpty(StackS1)) // Если стек S1 не свободен
		{
			std::cout << "Содержимое стэка S1 " << std::endl;
			showStruct(StackS1); // Вывести содержимое стека S1
		}
		if (processorP != nullptr) // Если процессор P не свободен
		{
			std::cout << "Содержимое процессора P" << std::endl;
			showTask(processorP); // Вывести содержимое процессора P
		}
		else // Иначе если процессор P свободен
		{
			std::cout << "Процессор свободен" << std::endl;
		}

		processorFOperation(processorP); // Функция работы процессора P
		timer++; // Иинкрементирование таймера (Увеличение на 1)
		if (isEmpty(IncomingTask) && isEmpty(queueF) && isEmpty(StackS0) && isEmpty(StackS1) && processorP == nullptr) // Если Generator, backup, F, S0, S1, P пустые и свободные
			break; // Выйти из цикла
		generateNewTask(IncomingTask); // Вызов функции генерации новой задачи
	}
	freeQueue(queueF); // Очистить память очереди
}

void exec()
{
	// Обычная работа
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
	// Работа с переполнением очереди
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