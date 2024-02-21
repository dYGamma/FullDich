#include <iostream>
#include <conio.h>
#include <limits.h>
using namespace std;

struct Tree
{
	int value; //���������� ����
	int height;
	Tree* Left; //��������� �� ������� �������� �����
	Tree* Right; //��������� �� ������� �������� �����
	Tree* Parent; //��������� �� ������
};

//����� �������� ������
Tree* SearchTreeElem(Tree*& Root, int value, int n = 0)
{
	if (!Root)
	{
		//����� � ����� => �� �������

		//������� ���������� �����
		cout << "not found in " << n << " steps" << endl << endl;
		return NULL;
	}
	else if (Root->value == value)
	{
		//�����
		//������� ���������� �����
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

//������ ������ � ������� ����� �������� - ������ ������, ������ �������
void PrintTree(Tree* p, int level = 0, bool printHeights = false)
{
	if (p)
	{
		PrintTree(p->Left, level + 1, printHeights); //������� ������� ����� �����, ������ ��� ���� ������
		for (int i = 0; i < level; i++) cout << "   "; //�������� �������, ��������������� ������� ������
		if (printHeights)
			//���� printHeight=true, ������� ������ ������ � ������ *p
			cout << p->height << endl; //� ������ ������� (endl), ����� �� ���� ����� �� ���� �� ����� � ��� �� ������
		else
			//���� printHeight=false, ������� ���������� ����� *p
			cout << p->value << endl; //� ������ ������� (endl), ����� �� ���� ����� �� ���� �� ����� � ��� �� ������
		PrintTree(p->Right, level + 1, printHeights); //����� ������� ������ �����
		if (!p->Parent) //���� �� � ����� ������ (� ������ �� ��������� �������, ��� ������, ��� �� ��� ���������� �� ������) ��������� �������������� ������ �������
			cout << endl;
	}
}

int GetHeightTree(Tree* tree)
{
	if (!tree) //� ������� ������ ������ 0 (� ����� tree->height ������ �� ������)
		return 0;
	return tree->height; //����� ���������� � ������ ������
}
void UpdateHeightTree(Tree* Tree) //��������� ������ ������ �� ������ ���� ��������
{
	if (Tree->Left && Tree->Right) //�������� ���� �����
		Tree->height = max(Tree->Left->height, Tree->Right->height) + 1;
	else if (Tree->Left) //��� ��� ������, �������� ����� ������ �����
		Tree->height = Tree->Left->height + 1;
	else if (Tree->Right) //���������� ������
		Tree->height = Tree->Right->height + 1;
	else //��� �������� => ������ ����� 1
		Tree->height = 1;
}

//������� ������ ������
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

		//�.�. ����� ���� ������� ������ �������� � ������-�� ������� ����������, ���������
		UpdateHeightTree(Root->Right);
		UpdateHeightTree(Root);

	}



}
//������� ������ �����
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

		//�.�. ����� ���� ������� ������ �������� � ������-�� ������� ����������, ���������
		UpdateHeightTree(Root->Left);
		UpdateHeightTree(Root);
	}
}
//������� ������� ������
void TreeRotateRightLeft(Tree*& Root)
{
	TreeRotateRight(Root->Right);
	TreeRotateLeft(Root);
}
//������� ������� �����
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

		//������ ����� ������� ������� - ���������� ����������
		if (GetHeightTree(MainTree->Right) - GetHeightTree(MainTree->Left) == 2)
		{
			if (GetHeightTree(MainTree->Right->Right) - GetHeightTree(MainTree->Right->Left) == 0)
				TreeRotateLeft(MainTree);
			else if (GetHeightTree(MainTree->Right->Right) - GetHeightTree(MainTree->Right->Left) == 1)
				TreeRotateLeft(MainTree);
			else
				TreeRotateLeftRight(MainTree);
		}
		//����� ����� ������� �������� - ���������� ����������
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

//������� �������� � ������
void TreeInsert(Tree*& Root, Tree*& NewElem)
{
	NewElem->height = 1;
	Tree* MainTree = Root;
	if (!Root) //���� ������ ������, ������ ������
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
			if (NewElem->value < MainTree->value) //�������� ������� ����� � ����� �����
			{
				if (MainTree->Left) //���� ���� ����� ����� ���������� ����� � ���
					MainTree = MainTree->Left;
				else //����� �� ����� ����� ��� ������ �������� - ������
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
			else //�������� ������� ����� ��������� � ������ �����
			{

				if (MainTree->Right) //���� ���� ������ ����� ���������� ����� � ���
					MainTree = MainTree->Right;
				else //����� �� ����� ����� ��� ������ �������� - ������
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
//�������� �������� ������
void DeleteTreeElem(Tree*& Root, Tree*& DeleteElem)
{
	Tree* MainTree = Root;
	Tree* Temp = NULL;
	Tree* Temp2 = NULL;

	//���� �������
	while (true)
	{
		if (MainTree)
		{
			if (DeleteElem->value == MainTree->value) //���� �������� ���������, �� �����
			{


				if (MainTree->Parent || GetHeightTree(MainTree) > 1) //���� ���� ��������(�������� ������) ��� ��������, ����� ������������� ���������� ������
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
	//������ ���������� �������� �� ����� ������� �� ������
	if (abs(minx) > abs(maxx))
		maxx = min(minx + 100, maxx);
	else
		minx = max(minx, maxx - 100);

	//������� ����� ����������� � ������������ ���������� ��������� - ��������� ����� ����
	return (maxx + minx) / 2;
}


//��������� ������������ ������� ������� ������������ ������� ������
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
		//min(maxx,Root->value), ����� ���� ������ Root->value
		Root->Left = new Tree;
		Root->Left->value = nvalue;
		Root->Left->height = mheight;
		Root->Left->Parent = Root;
		Root->Left->Left = NULL;
		Root->Left->Right = NULL;
	}
	if (!Root->Right)
	{
		int nvalue = FillTreeNumber(max(minx, Root->value), maxx); //������� ����� ����������� � ������������ ���������� ��������� - ��������� ����� ����
		//max(min,Root->value), ����� ���� ������ Root->value
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
//��������� ������ �� ����������� ������� �������
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

