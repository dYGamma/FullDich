#include <iostream>
#include <conio.h>
#include <limits.h>
using namespace std;

struct Tree
{
	int value; //содержимое узла
	int height;
	Tree* Left; //указатель на меньшее дочернее звено
	Tree* Right; //указатель на большее дочернее звено
	Tree* Parent; //указатель на предка
};

//поиск элемента дерева
Tree* SearchTreeElem(Tree*& Root, int value, int n = 0)
{
	if (!Root)
	{
		//зашли в тупик => не найдено

		//выводим количество шагов
		cout << "not found in " << n << " steps" << endl << endl;
		return NULL;
	}
	else if (Root->value == value)
	{
		//нашли
		//выводим количество шагов
		cout << "found in " << n << " steps" << endl << endl;
		return Root;
	}
	else if (value > Root->value)
	{
		return SearchTreeElem(Root->Right, value, n + 1);
	}
	else
	{
		return SearchTreeElem(Root->Left, value, n + 1);
	}

}

//печать дерева в консоль слева родитель - справа листья, сверху меньшие
void PrintTree(Tree* p, int level = 0, bool printHeights = false)
{
	if (p)
	{
		PrintTree(p->Left, level + 1, printHeights); //сначала выводим левую ветвь, потому она выше правой
		for (int i = 0; i < level; i++) cout << "   "; //печатаем пробелы, соответствующие глубине дерева
		if (printHeights)
			//если printHeight=true, выводим высоту дерева с корнем *p
			cout << p->height << endl; //и меняем строчку (endl), чтобы ни одно звено не было на одной и той же строке
		else
			//если printHeight=false, выводим содержимое звена *p
			cout << p->value << endl; //и меняем строчку (endl), чтобы ни одно звено не было на одной и той же строке
		PrintTree(p->Right, level + 1, printHeights); //потом выводим правую ветвь
		if (!p->Parent) //если мы в корне дерева (а исходя из структуры функции, это значит, что мы уже напечатали всё дерево) добавляем дополнительную пустую строчку
			cout << endl;
	}
}

int GetHeightTree(Tree* tree)
{
	if (!tree) //у пустого дерева высота 0 (и также tree->height выдало бы ошибку)
		return 0;
	return tree->height; //выдаём хранящуюся в дереве высоту
}
void UpdateHeightTree(Tree* Tree) //обновляем высоту дерева на основе двух дочерних
{
	if (Tree->Left && Tree->Right) //максимум двух высот
		Tree->height = max(Tree->Left->height, Tree->Right->height) + 1;
	else if (Tree->Left) //раз нет правой, максимум равен высоте левой
		Tree->height = Tree->Left->height + 1;
	else if (Tree->Right) //аналогично правой
		Tree->height = Tree->Right->height + 1;
	else //нет дочерних => высота равна 1
		Tree->height = 1;
}

//поворот дерева вправо
void TreeRotateRight(Tree*& Root)
{


	if (Root->Left)
	{
		Tree* Temp;
		Temp = Root->Left;
		Temp->Parent = Root->Parent;
		if (Temp->Parent)
		{
			if (Temp->Parent->Left == Root)
				Temp->Parent->Left = Temp;
			else
				Temp->Parent->Right = Temp;
		}
		Root->Left = Temp->Right;
		if (Root->Left) Root->Left->Parent = Root;

		Temp->Right = Root;
		Temp->Right->Parent = Temp;

		Root = Temp;

		//т.к. после смен позиций высоты деревьев с такими-то корнями поменялись, обновляем
		UpdateHeightTree(Root->Right);
		UpdateHeightTree(Root);

	}



}
//поворот дерева влево
void TreeRotateLeft(Tree*& Root)
{
	if (Root->Right)
	{
		Tree* temp;

		temp = Root->Right;
		temp->Parent = Root->Parent;
		if (temp->Parent)
		{
			if (temp->Parent->Left == Root)
				temp->Parent->Left = temp;
			else
				temp->Parent->Right = temp;
		}

		Root->Right = temp->Left;
		if (Root->Right) Root->Right->Parent = Root;

		temp->Left = Root;
		temp->Left->Parent = temp;

		Root = temp;

		//т.к. после смен позиций высоты деревьев с такими-то корнями поменялись, обновляем
		UpdateHeightTree(Root->Left);
		UpdateHeightTree(Root);
	}
}
//двойной поворот вправо
void TreeRotateRightLeft(Tree*& Root)
{
	TreeRotateRight(Root->Right);
	TreeRotateLeft(Root);
}
//двойной поворот влево
void TreeRotateLeftRight(Tree*& Root)
{
	TreeRotateLeft(Root->Left);
	TreeRotateRight(Root);
}

void BalanceTree(Tree*& Root, Tree*& NewElem)
{
	Tree* MainTree = NewElem;
	while (true)
	{
		UpdateHeightTree(MainTree);

		//правая ветвь слишком высокая - исправляем поворотами
		if (GetHeightTree(MainTree->Right) - GetHeightTree(MainTree->Left) == 2)
		{
			if (GetHeightTree(MainTree->Right->Right) - GetHeightTree(MainTree->Right->Left) == 0)
				TreeRotateLeft(MainTree);
			else if (GetHeightTree(MainTree->Right->Right) - GetHeightTree(MainTree->Right->Left) == 1)
				TreeRotateLeft(MainTree);
			else
				TreeRotateLeftRight(MainTree);
		}
		//левая ветвь слишком глубокая - исправляем поворотами
		else if (GetHeightTree(MainTree->Right) - GetHeightTree(MainTree->Left) == -2)
		{
			if (GetHeightTree(MainTree->Left->Right) - GetHeightTree(MainTree->Left->Left) == 0)
				TreeRotateRight(MainTree);
			else if (GetHeightTree(MainTree->Left->Right) - GetHeightTree(MainTree->Left->Left) == -1)
				TreeRotateRight(MainTree);
			else
				TreeRotateRightLeft(MainTree);
		}
		if (MainTree->Parent)
			MainTree = MainTree->Parent;
		else break;
	}
	Root = MainTree;
}

//вставка элемента в дерево
void TreeInsert(Tree*& Root, Tree*& NewElem)
{
	NewElem->height = 1;
	Tree* MainTree = Root;
	if (!Root) //если дерево пустое, создаём корень
	{
		Root = new Tree;
		Root->value = NewElem->value;
		Root->height = 1;
		Root->Parent = NULL;
		Root->Left = NULL;
		Root->Right = NULL;
	}
	else
	{


		while (true)
		{
			if (NewElem->value < MainTree->value) //значения меньшие корня в левой ветви
			{
				if (MainTree->Left) //если есть левая ветвь продолжаем поиск в ней
					MainTree = MainTree->Left;
				else //иначе мы нашли место для нового элемента - создаём
				{
					MainTree->Left = new Tree;
					MainTree->Left->value = NewElem->value;
					MainTree->Left->height = 1;
					MainTree->Left->Parent = NULL;
					MainTree->Left->Left = NULL;
					MainTree->Left->Right = NULL;
					MainTree->Left->Parent = MainTree;
					break;
				}
			}
			else //значения большие корня поддерева в правой ветви
			{

				if (MainTree->Right) //если есть правая ветвь продолжаем поиск в ней
					MainTree = MainTree->Right;
				else //иначе мы нашли место для нового элемента - создаём
				{
					MainTree->Right = new Tree;
					MainTree->Right->value = NewElem->value;
					MainTree->Right->height = 1;
					MainTree->Right->Parent = NULL;
					MainTree->Right->Left = NULL;
					MainTree->Right->Right = NULL;
					MainTree->Right->Parent = MainTree;
					break;
				}
			}

		}
		BalanceTree(Root, MainTree);
	}
}
//удаление элемента дерева
void DeleteTreeElem(Tree*& Root, Tree*& DeleteElem)
{
	Tree* MainTree = Root;
	Tree* Temp = NULL;
	Tree* Temp2 = NULL;

	//ищем элемент
	while (true)
	{
		if (MainTree)
		{
			if (DeleteElem->value == MainTree->value) //если значение совпадает, то нашли
			{


				if (MainTree->Parent || GetHeightTree(MainTree) > 1) //если есть дочерние(проверка высоты) или родитель, нужно пересоединять оставшиеся звенья
				{
					Temp2 = MainTree;
					if (MainTree->Left || MainTree->Right)
					{
						if (MainTree->Right)
							MainTree = MainTree->Right;
						Temp = Temp2->Parent;
						while (MainTree->Left)
							MainTree = MainTree->Left;
						if (MainTree->Parent)
						{
							if (MainTree->Parent->Right == MainTree)
								MainTree->Parent->Right = NULL;
							else
								MainTree->Parent->Left = NULL;
						}
						if (Temp)
						{
							if (Temp->Right)
							{
								if (Temp->Right == Temp2)
									Temp->Right = MainTree;
								else
									Temp->Left = MainTree;
							}
							else
								Temp->Left = MainTree;
						}
						if (MainTree->Parent != Temp2)
							Temp = MainTree->Parent;
						else Temp = MainTree;
						MainTree->Parent = Temp2->Parent;
						if (Temp2->Right != MainTree)
						{
							MainTree->Right = Temp2->Right;
							if (MainTree->Right)
								MainTree->Right->Parent = MainTree;
						}
						else
							MainTree->Right = NULL;
						if (Temp2->Left != MainTree)
						{
							MainTree->Left = Temp2->Left;
							if (MainTree->Left)
								MainTree->Left->Parent = MainTree;
						}
						else
							MainTree->Left = NULL;
						BalanceTree(Root, Temp);
					}
					else
					{
						Temp = MainTree->Parent;
						if (Temp)
						{
							if (Temp->Right)
							{
								if (Temp->Right == MainTree)
									Temp->Right = NULL;
								else
									Temp->Left = NULL;
							}
							else
								Temp->Left = NULL;
						}
						BalanceTree(Root, Temp);
					}
					cout << "elem was deleted" << endl << endl;

					return;
				}
				else
				{
					Root = NULL;
					cout << "Tree is Empty Now" << endl << endl;
					_getch();
					return;
				}
			}
			else if (DeleteElem->value > MainTree->value)
				MainTree = MainTree->Right;
			else
				MainTree = MainTree->Left;

		}
		else
		{
			cout << "No such elem in tree!" << endl;
			_getch();
			return;
		}
	}
}







int FillTreeNumber(int minx, int maxx)
{
	//делаем выдаваемое значение не очень большим по модулю
	if (abs(minx) > abs(maxx))
		maxx = min(minx + 100, maxx);
	else
		minx = max(minx, maxx - 100);

	//среднее между минимальным и максимальным подходящим значением - находится между ними
	return (maxx + minx) / 2;
}


//получение максимальной глубины листьев симметричным обходом дерева
int getmdepth(Tree*& root, int maxx = 0)
{
	if (root)
	{
		int n = getmdepth(root->Left, maxx + 1);
		int m = getmdepth(root->Right, maxx + 1);
		return max(maxx, max(n, m));
	}
	else
	{
		return maxx;
	}
}
void FillIterTree(Tree*& Root, int mheight, int minx, int maxx)
{
	if (!Root->Left)
	{
		int nvalue = FillTreeNumber(minx, min(maxx, Root->value));
		//min(maxx,Root->value), чтобы было меньше Root->value
		Root->Left = new Tree;
		Root->Left->value = nvalue;
		Root->Left->height = mheight;
		Root->Left->Parent = Root;
		Root->Left->Left = NULL;
		Root->Left->Right = NULL;
	}
	if (!Root->Right)
	{
		int nvalue = FillTreeNumber(max(minx, Root->value), maxx); //среднее между минимальным и максимальным подходящим значением - находится между ними
		//max(min,Root->value), чтобы было меньше Root->value
		Root->Right = new Tree;
		Root->Right->value = nvalue;
		Root->Right->height = mheight;
		Root->Right->Parent = Root;
		Root->Right->Left = NULL;
		Root->Right->Right = NULL;
	}
	if (mheight != 1)
	{
		FillIterTree(Root->Left, mheight - 1, minx, min(maxx, Root->value));
		FillIterTree(Root->Right, mheight - 1, max(minx, Root->value), maxx);
	}
}
//заполнить дерево до равномерной глубины листьев
void FillTree(Tree*& Root)
{
	//int maxdepth=GetHeightTree(Root)-1;
	int maxdepth = getmdepth(Root) - 1;
	FillIterTree(Root, maxdepth, INT_MIN, INT_MAX);
}


int main(int argc, char* argv[]) {
	Tree* temp = new Tree;
	temp->value = 1;
	Tree* root = NULL;
	TreeInsert(root, temp);
	temp->value = 0;
	TreeInsert(root, temp);
	temp->value = 2;
	TreeInsert(root, temp);
	temp->value = 10;
	TreeInsert(root, temp);
	temp->value = 20;
	TreeInsert(root, temp);
	temp->value = 25;
	TreeInsert(root, temp);



	temp->value = 5;
	SearchTreeElem(root, 5);
	TreeInsert(root, temp);
	SearchTreeElem(root, 5);


	cout << "heights:" << endl;
	PrintTree(root, 0, 1);



	cout << "tree:" << endl;
	PrintTree(root);

	DeleteTreeElem(root, temp);



	PrintTree(root);
	cout << "filled tree:" << endl << endl;
	FillTree(root);
	PrintTree(root);




	return 0;
}

