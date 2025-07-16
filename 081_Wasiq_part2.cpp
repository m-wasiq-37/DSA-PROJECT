#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
int counter = 0;
struct node
{
    int id;
    node *left = NULL; // i am using this as next pointer for linklist channing
    node *right = NULL;
};
int primenumber[1500];
int oddnumbers[1500];
int evennumbers[1500];

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

void generateprimes()
{
    for (int num = 2, found = 0; found < 1500; ++num)
    {
        if (isPrime(num))
        {
            primenumber[found] = num;
            ++found;
        }
    }
}

bool isodd(int num)
{
    if (num % 2 == 0)
    {
        return false;
    }
    return true;
}

void generateodd()
{
    for (int num = 2, found = 0; found < 1500; ++num)
    {
        if (isodd(num))
        {
            oddnumbers[found] = num;
            ++found;
        }
    }
}

bool iseven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    return false;
}

void generateeven()
{
    for (int num = 2, found = 0; found < 1500; ++num)
    {
        if (iseven(num))
        {
            evennumbers[found] = num;
            ++found;
        }
    }
}

unsigned int hashing(int id) // rolling hashing
{
    unsigned int hash = 1;
    for (int i = 0; i < sizeof(id); i++)
    {
        hash = hash * 33 + id;
    }

    return hash;
}

int hashindex(int id)
{
    return hashing(id) % 999;
}

class linearprobing
{
private:
    int arraySize;
    node **arr;
    int size;

public:
    int inscertcollisions = 0;
    int searchcollisions = 0;

    linearprobing()
    {
        arraySize = 1081;
        size = 0;
        arr = new node *[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            arr[i] = NULL;
        }
    }

    void resizeArray()
    {
        int oldArraySize = arraySize;
        arraySize++;

        node **newArr = new node *[arraySize];

        for (int i = 0; i < oldArraySize; i++)
        {
            newArr[i] = arr[i];
        }

        newArr[arraySize - 1] = NULL;
        delete[] arr;
        arr = newArr;
    }

    ~linearprobing()
    {
        for (int i = 0; i < arraySize; i++)
        {
            delete arr[i];
        }
        delete[] arr;
    }

    unsigned int linearhashing(int id) // rolling hashing
    {
        unsigned int hash = 1;
        for (int i = 0; i < sizeof(id); i++)
        {
            hash = hash * 33 + id;
        }

        return hash;
    }

    int linearhashindex(int id)
    {
        return linearhashing(id) % arraySize;
    }

    bool insertlinear(node *in)
    {
        int index = linearhashindex(in->id);
        if (index > 1000)
        {
            return true;
        }
        if (arr[index] == NULL || arr[index]->id == -1)
        {
            arr[index] = in;
            size++;
            return false;
        }
        else
        {
            for (int i = index; i < arraySize; i++)
            {
                if (arr[i] == NULL || arr[i]->id == -1)
                {
                    inscertcollisions++;
                    arr[i] = in;
                    size++;
                    return false;
                }
                else if (arr[i]->id == in->id)
                {
                    return true;
                }
                else if (i == arraySize - 1)
                {
                    resizeArray();
                }
            }
        }
        return true;
    }

    bool deletionlinear(int arr1)
    {
        int index = linearhashindex(arr1);
        if (arr[index] != NULL && arr[index]->id == arr1)
        {
            arr[index]->id = -1;
            size--;
            return false;
        }
        counter++;
        for (int i = index + 1; i < arraySize; i++)
        {
            if (arr[i] != NULL && arr[i]->id == arr1)
            {
                arr[i]->id = -1;
                size--;
                return false;
            }
            else if (arr[i] == NULL)
            {
                return true;
            }
            counter++;
        }
        return true;
    }

    node *linearsearch(int arre)
    {
        int index = linearhashindex(arre);
        if (arr[index] != NULL && arr[index]->id == arre)
        {
            return arr[index];
        }
        else
        {
            searchcollisions++;
            for (int i = index + 1; i < arraySize; i++)
            {
                if (arr[i] != NULL && arr[i]->id == arre)
                {
                    if (arr[i]->id != -1)
                    {
                        return arr[i];
                    }
                    return NULL;
                    break;
                }
                else if (arr[i] == NULL)
                {
                    return NULL;
                }
            }
        }
        return NULL;
    }

    void DisplayAll()
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (arr[j] != NULL)
            {
                if (arr[j]->id != -1)
                {
                    cout << "\nID:" << arr[j]->id << endl;
                }
            }
        }
    }
} linear;

class linklistchanning
{
private:
    int size, arraySize;
    node **arr;

public:
    int inscertcollisions = 0;
    int searchcollisions = 0;

    linklistchanning()
    {
        arraySize = 1000;
        size = 0;
        arr = new node *[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            arr[i] = NULL;
        }
    }

    ~linklistchanning()
    {
        delete[] arr;
    }

    bool listinsert(node *in)
    {
        int index = hashindex(in->id);
        if (index > 999)
        {
            return true;
        }
        if (arr[index] == NULL)
        {
            arr[index] = in;
            return false;
        }
        else
        {
            if (arr[index]->id == in->id)
            {
                return true;
            }
            node *temp = arr[index];
            while (temp->left)
            {
                if (temp->left->id == in->id)
                {
                    return true;
                }
                temp = temp->left;
            }
            inscertcollisions++;
            temp->left = in;
            return false;
        }
        return true;
    }

    bool listdeletion(int arrr)
    {
        int index = hashindex(arrr);
        if (arr[index]->id == arrr)
        {
            node *temp = arr[index];
            arr[index] = arr[index]->left;
            delete temp;
            return false;
        }
        else
        {
            node *ptr = arr[index];
            while (ptr->left)
            {
                if (ptr->left->id == arrr)
                {
                    node *temp = ptr->left;
                    ptr->left = ptr->left->left;
                    delete temp;
                    return false;
                }
                ptr = ptr->left;
            }
            return true;
        }
        return true;
    }

    node *listsearch(int arrr)
    {
        int index = hashindex(arrr);
        if (arr[index] == NULL)
        {
            return NULL;
        }
        if (arr[index]->id == arrr)
        {
            return arr[index];
        }
        else
        {
            searchcollisions++;
            node *ptr = arr[index];
            while (ptr->left != NULL)
            {
                if (ptr->left->id == arrr)
                {
                    return arr[index]->left;
                }
                ptr = ptr->left;
            }
            return NULL;
        }
        return NULL;
    }

    void DisplayALL()
    {
        node *temp = NULL;
        for (int j = 0; j < arraySize; j++)
        {
            if (arr[j] != NULL)
            {
                temp = arr[j];
                while (temp != NULL)
                {
                    cout << "\nID:" << temp->id << endl;
                    temp = temp->left;
                }
            }
        }
    }
} list;

class bstchanning
{
private:
    int size, arraySize;
    node **arr;

    void makeDeletion(node *&nodePtr)
    {
        node *tempNodePtr;
        if (nodePtr->right == NULL)
        {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->left;
            delete tempNodePtr;
        }
        else if (nodePtr->left == NULL)
        {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        }
        else
        {
            tempNodePtr = nodePtr->right;
            while (tempNodePtr->left)
            {
                tempNodePtr = tempNodePtr->left;
            }
            tempNodePtr->left = nodePtr->left;
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        }
    }

    void deleteNode(int id, node *&nodePtr)
    {
        if (nodePtr == NULL)
            cout << "\nID not Found\n";
        else if (nodePtr->id > id)
            deleteNode(id, nodePtr->left);
        else if (nodePtr->id < id)
            deleteNode(id, nodePtr->right);
        else
            makeDeletion(nodePtr);
    }

public:
    int inscertcollisions = 0;
    int searchcollisions = 0;

    bstchanning()
    {
        arraySize = 1000;
        size = 0;
        arr = new node *[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            arr[i] = NULL;
        }
    }

    ~bstchanning()
    {
        delete[] arr;
    }

    bool bstinsert(node *in)
    {
        int index = hashindex(in->id);
        if (index > 999)
        {
            return true;
        }
        if (arr[index] == NULL)
        {
            arr[index] = in;
            return false;
        }
        else
        {
            node *nodePtr = arr[index];
            while (nodePtr != NULL)
            {
                if (nodePtr->id > in->id)
                {
                    if (nodePtr->left)
                    {
                        nodePtr = nodePtr->left;
                    }
                    else
                    {
                        inscertcollisions++;
                        nodePtr->left = in;
                        return false;
                    }
                }
                else if (nodePtr->id < in->id)
                {
                    if (nodePtr->right)
                        nodePtr = nodePtr->right;
                    else
                    {
                        inscertcollisions++;
                        nodePtr->right = in;
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }
        }
        return true;
    }

    void bstdeletion(int arrr)
    {
        int index = hashindex(arrr);
        deleteNode(arrr, arr[index]);
    }

    node *bstsearch(int id)
    {
        int index = hashindex(id);
        if (arr[index] == NULL)
        {
            return NULL;
        }
        else
        {
            searchcollisions++;
            node *nodePtr = arr[index];
            while (nodePtr != NULL)
            {
                if (nodePtr->id > id)
                {
                    nodePtr = nodePtr->left;
                }
                else if (nodePtr->id < id)
                {
                    nodePtr = nodePtr->right;
                }
                else
                {
                    return nodePtr;
                }
            }
        }
        return NULL;
    }

    void preorder(node *temp)
    {
        if (temp != NULL)
        {
            cout << "\nID:" << temp->id << endl;
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void DisplayALL()
    {
        for (int i = 0; i < arraySize; i++)
        {
            if (arr[i] != NULL)
            {
                preorder(arr[i]);
            }
        }
    }
} bst;

node *createnode(int a)
{
    node *temp = new node;
    if (a == 1)
    {
        temp->id = primenumber[rand() % 1501];
    }
    else if (a == 2)
    {
        temp->id = evennumbers[rand() % 1501];
    }
    else
    {
        temp->id = oddnumbers[rand() % 1501];
    }
    return temp;
}

node *linearinsert(int a)
{
    node *temp = NULL;
    do
    {
        temp = createnode(a);
    } while (linear.insertlinear(temp));
    return temp;
}

node *listinsert(int a)
{
    node *temp = NULL;
    do
    {
        temp = createnode(a);
    } while (list.listinsert(temp));
    return temp;
}

node *bstinsert(int a)
{
    node *temp = NULL;
    do
    {
        temp = createnode(a);
    } while (bst.bstinsert(temp));
    return temp;
}

int main()
{
    int a = 0;
    cout << "1.Prime NUMBERS\n2.Even NUMBERS\n3.Odd NUMBERS\n";
    cout << "Enter YOUR choice:";
    cin >> a;
    if (a == 1)
    {
        generateprimes();
    }
    else if (a == 2)
    {
        generateeven();
    }
    else
    {
        generateodd();
    }
    for (int i = 0; i < 1000; i++)
    {
        linearinsert(a);
    }
    for (int i = 0; i < 1000; i++)
    {
        listinsert(a);
    }
    for (int i = 0; i < 1000; i++)
    {
        bstinsert(a);
    }
    node *temp = NULL;
    int id = 0;
    for (int i = 0; i < 100; i++)
    {
        temp = NULL;
        id = 0;
        do
        {
            if (a == 1)
            {
                id = primenumber[rand() % 1501];
            }
            else if (a == 2)
            {
                id = evennumbers[rand() % 1501];
            }
            else
            {
                id = oddnumbers[rand() % 1501];
            }
            temp = linear.linearsearch(id);
        } while (temp == NULL);
    }
    for (int i = 0; i < 100; i++)
    {
        temp = NULL;
        id = 0;
        do
        {
            if (a == 1)
            {
                id = primenumber[rand() % 1501];
            }
            else if (a == 2)
            {
                id = evennumbers[rand() % 1501];
            }
            else
            {
                id = oddnumbers[rand() % 1501];
            }
            temp = list.listsearch(id);
        } while (temp == NULL);
    }
    for (int i = 0; i < 100; i++)
    {
        temp = NULL;
        id = 0;
        do
        {
            if (a == 1)
            {
                id = primenumber[rand() % 1501];
            }
            else if (a == 2)
            {
                id = evennumbers[rand() % 1501];
            }
            else
            {
                id = oddnumbers[rand() % 1501];
            }
            temp = bst.bstsearch(id);
        } while (temp == NULL);
    }
    cout << "\n\nLINEAR PROBING";
    cout << "\nCollision In insertion: " << linear.inscertcollisions;
    cout << "\nCollision  In  Searching: " << linear.searchcollisions;
    cout << "\n\nLinkList Channing";
    cout << "\nCollision In insertion: " << list.inscertcollisions;
    cout << "\nCollision  In  Searching: " << list.searchcollisions;
    cout << "\n\nBST Channing";
    cout << "\nCollision In insertion: " << bst.inscertcollisions;
    cout << "\nCollision  In  Searching: " << bst.searchcollisions;
    return 0;
}
