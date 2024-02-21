#include<iostream>
#include <string>
#include <vector>

using namespace std;


struct node //������� ������
{
    int value;
    node* left;
    node* right;
    int height;
};

class AVL_tree
{
    node* root;

    void  del_tree(node* element) //������ ��� ������
    {
        vector<int> v;
        order(root, v);
        for (int i = 0; i < v.size(); i++)
            remove(v[i]);
    }

    node* insert(int value, node* element) //��������� ������� � ����������� ������
        //���� ����� ������� ��� � ������ - �� ���������
    {
        if (element == NULL)
        {
            element = new node;
            element->value = value;
            element->height = 0;
            element->left = element->right = NULL;
        }
        else if (value < element->value)
        {
            element->left = insert(value, element->left);
            if (height(element->left) - height(element->right) == 2)
            {
                if (value < element->left->value)
                    element = rightRotate(element);
                else
                    element = bigRightRotate(element);
            }
        }
        else if (value > element->value)
        {
            element->right = insert(value, element->right);
            if (height(element->right) - height(element->left) == 2)
            {
                if (value > element->right->value)
                    element = leftRotate(element);
                else
                    element = bigLeftRotate(element);
            }
        }
        element->height = max(height(element->left), height(element->right)) + 1;
        return element;
    }

    node* rightRotate(node*& element) //4 ������ ���������, ������� ������������ ��� ������, ����� � �����, ������ (�� 2 ����� ������)
    {
        node* u = element->left;
        element->left = u->right;
        u->right = element;
        element->height = max(height(element->left), height(element->right)) + 1;
        u->height = max(height(u->left), element->height) + 1;
        return u;
    }

    node* leftRotate(node*& element)
    {
        node* u = element->right;
        element->right = u->left;
        u->left = element;
        element->height = max(height(element->left), height(element->right)) + 1;
        u->height = max(height(element->right), element->height) + 1;
        return u;
    }

    node* bigLeftRotate(node*& element)
    {
        element->right = rightRotate(element->right);
        return leftRotate(element);
    }

    node* bigRightRotate(node*& element)
    {
        element->left = leftRotate(element->left);
        return rightRotate(element);
    }

    node* findMin(node* element) //����������� ������� � ���������
    {
        if (element == NULL)
            return NULL;
        else if (element->left == NULL)
            return element;
        else
            return findMin(element->left);
    }

    int getBalance(node* element) //������������ � ���������
    {
        return height(element->right) - height(element->left);
    }

    void fixheight(node* element)//������������ �������� ������ ��������� ����
    {
        element->height = max(height(element->left), height(element->right)) + 1;
    }

    node* balance(node* p) // ������������ ���� p
    {
        fixheight(p);
        if (getBalance(p) == 2)
        {
            if (getBalance(p->right) < 0)
                p->right = rightRotate(p->right);
            return leftRotate(p);
        }
        if (getBalance(p) == -2)
        {
            if (getBalance(p->left) > 0)
                p->left = leftRotate(p->left);
            return rightRotate(p);
        }
        return p; // ������������ �� �����
    }

    node* removeMin(node* p) // �������� ���� � ����������� ������ �� ��������� p
    {
        if (p->left == 0)
            return p->right;
        p->left = removeMin(p->left);
        return balance(p);
    }

    node* remove(node* p, int k) // �������� ����� k �� ������ p
    {
        if (!p) return 0;
        if (k < p->value)
            p->left = remove(p->left, k);
        else if (k > p->value)
            p->right = remove(p->right, k);
        else //  k == p->key 
        {
            node* q = p->left;
            node* r = p->right;
            delete p;
            if (!r) return q;
            node* min = findMin(r);
            min->right = removeMin(r);
            min->left = q;
            return balance(min);
        }
        return balance(p);
    }

    int height(node* element) //������ ����
    {
        if (element == NULL)
            return -1;
        else
            return element->height;
    }

    void node_Height(node*& element, int val, int& h) { //������� ������ ��� �������. � ������ �������� ������ ���� � ���������, ��� ������� ���� ������ �� �����
        h++;                                            //������� ���� �� ����� � ������ ��� +1, ���� �� ������. ��� � ����� ������ �� ����� (�� ���� ������� ����� ��� � ������)
        if (val < element->value) {
            if (element->left == NULL) {
                return;
            }

            node_Height(element->left, val, h);
        }
        else {
            if (element->right == NULL) {
                return;
            }
            node_Height(element->right, val, h);
        }
    }

    int calc_height(int val) { //������ ������� ������� ������ ��������
        int h = 0;
        node_Height(root, val, h);
        return h;
    }

    bool search(node*& element, int val, int k = 0) { //���� �� ������� � ������
        if (val == element->value) { //������� ������
            cout << "����� ��: " << k << endl;
            return true;
        }
        k++;
        if (val < element->value) { //������� ������ - ���� �����
            if (element->left == NULL) {
                return false;
            }
            search(element->left, val, k);
        }
        else { //������ - ������
            if (element->right == NULL) {
                return false;
            }
            search(element->right, val, k);
        }
    }

    void printBT(const std::string& prefix, const node* node, bool isLeft) //����� ������
    {
        if (node != NULL)
        {
            cout << prefix;
            cout << (isLeft ? "|->>" : "L_>>");
            cout << node->value << std::endl;
            printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
            printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
        }
    }

    void order(node* root, vector<int>& v) { //����������� ����� �� �������
        if (root->left)
            order(root->left, v);
        v.push_back(root->value);
        if (root->right)
            order(root->right, v);

    }

    void task_order(node* root, int& mx, int& k) {
        // k - ������� ��� �� �������� ��������

        if (root->left || root->right) { //���� ���� ����(�� ��������) - ���������� �����
            if (root->left)
                task_order(root->left, mx, k);
            if (root->right)
                task_order(root->right, mx, k);
        }
        else { //����� ��������� �� ��������
            if (mx != calc_height(root->value)) {
                mx = max(calc_height(root->value), mx);
                k++;
            }
        }
    }

    void task(node* root) { //���� �������
        int max_height = -1, k = 0;
        task_order(root, max_height, k);
        int tmp = max_height;
        cout << endl << "������������ ������� = " << max_height << endl;
        while (k > 1 && max_height <= tmp) { //�� �������� ������ 1 ���� - �� ��� ������ �����, �� � ����� ���� ����� ������ ����� ������ ��������� - ���� �����������
            cout << "\n������� ��� �������� � ������ ��� �������\n";
            int add;
            cin >> add;
            insert(add);
            k = 0;
            task_order(root, max_height, k);
            print();
            cout << endl;
        }
        if (max_height > tmp) {
            cout << "������������ ������ ��������� �����������\n";
        }
        else
            cout << "��� ������ ��������� �����\n";
    }
public:
    AVL_tree()//�����������
    {
        root = NULL;
    }

    void task() {
        task(root);
    }

    void insert(int value) //������� �� �����
    {
        root = insert(value, root);
    }

    void remove(int value) //�������� �� �������� �� �����
    {
        root = remove(root, value);
    }

    void print() //����� ������ �� �����
    {
        printBT("", root, false);
    }

    void order() { //����������� ����� ������, �� ��������� �� ����� ������
        vector<int> v;
        order(root, v);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }

    bool search(int value) { //����� �� ��������
        return search(root, value);
    }
};



int main()
{
    setlocale(0, "");
    AVL_tree element;
    int choise = 96;
    for (;;) {
        cout << "1 �������� �������\n";
        cout << "2 �������� ������\n";
        cout << "3 ����� �������\n";
        cout << "4 ������� �������\n";
        cout << "5 ������ ������(�����������)\n";
        cout << "6 ������ �������\n";
        cout << "0 �����\n";
        cout << "\n";
        cout << "�������� �����: ";
        cin >> choise;
        cout << "\n";
        switch (choise) {
        case 1: {
            cout << "���� �������� ��� ���������� � ������, ���������� ������ ����������\n";
            int value;
            cin >> value;
            element.insert(value);
            break;
        }
        case 2: {
            element.print();
            break;
        }
        case 3: {
            cout << "����� ��������\n";
            int value;
            cin >> value;
            element.search(value);
            break;
        }
        case 4: {
            cout << "���� �������� ��� �������� �� ������\n";
            int value;
            cin >> value;
            element.remove(value);
            break;
        }
        case 5: {
            element.order();
            break;
        }
        case 6: {
            element.task();
            break;
        }
        case 0: {
            return 0;
        }
        }
    }
}