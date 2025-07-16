#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

struct node
{
    char id[14];
    string name;
    string fathername;
    string gender;
    string address = "Random Address";
    node *left = NULL; // i am using this as next pointer for linklist channing
    node *right = NULL;
};

int getposition(char arr[], char arrr[])
{
    for (int i = 0; i < 13; i++)
    {
        if (arr[i] > arrr[i])
        {
            return -1;
        }
        else if (arr[i] < arrr[i])
        {
            return 1;
        }
    }
    return 0;
}

unsigned int hashing(char arr[]) // rolling hashing
{
    unsigned int hash = 5381;
    for (int i = 0; i < 13; i++)
    {
        hash = (hash * 33) ^ arr[i];
    }

    return hash;
}

int hashindex(char arr[])
{
    return hashing(arr) % 999;
}

class linearprobing
{
private:
    int arraySize;
    node **arr;
    int size;

public:
    int searchc = 0;

    linearprobing()
    {
        arraySize = 1000;
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
        delete[] arr;
    }

    unsigned int linearhashing(char arr1[]) // rolling hashing
    {
        unsigned int hash = 5381;
        for (int i = 0; i < 13; i++)
        {
            hash = (hash * 33) ^ arr1[i];
        }

        return hash;
    }

    int linearhashindex(char arr1[])
    {
        return linearhashing(arr1) % (arraySize - 1);
    }

    bool insertlinear(node *in)
    {
        int index = linearhashindex(in->id);
        if (arr[index] == NULL || arr[index]->address == "NA")
        {
            arr[index] = in;
            size++;
            return false;
        }
        else
        {
            for (int i = index; i < arraySize; i++)
            {
                if (arr[i] == NULL || arr[i]->address == "NA")
                {
                    arr[i] = in;
                    size++;
                    return false;
                }
                else if (getposition(arr[i]->id, in->id) == 0)
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

    bool deletionlinear(char arr1[])
    {
        int index = linearhashindex(arr1);
        if (getposition(arr[index]->id, arr1) == 0)
        {
            arr[index]->address = "NA";
            size--;
            return false;
        }
        for (int i = index + 1; i < arraySize; i++)
        {
            if (getposition(arr[i]->id, arr1) == 0)
            {
                arr[i]->address = "NA";
                size--;
                return false;
            }
            else if (arr[i] == NULL)
            {
                return true;
            }
        }
        return true;
    }

    node *linearsearch(char arre[])
    {
        int index = linearhashindex(arre);
        if (getposition(arr[index]->id, arre) == 0)
        {
            if (arr[index]->address == "NA")
            {
                return NULL;
            }
            return arr[index];
        }
        else
        {
            searchc++;
            for (int i = index + 1; i < arraySize; i++)
            {
                if (getposition(arr[i]->id, arre) == 0)
                {
                    if (arr[i]->address != "NA")
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
                if (arr[j]->address != "NA")
                {
                    cout << "\nCNIC: ";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << arr[j]->id[i];
                    }
                    cout << "-";
                    for (int i = 5; i < 12; i++)
                    {
                        cout << arr[j]->id[i];
                    }
                    cout << "-";
                    cout << arr[j]->id[12] << endl;
                    cout << "Name: " << arr[j]->name << endl;
                    cout << "Father Name: " << arr[j]->fathername << endl;
                    cout << "Gender: " << arr[j]->gender << endl;
                    cout << "Address: " << arr[j]->address << endl
                         << endl;
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
    int searchc = 0;

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
        if (arr[index] == NULL)
        {
            arr[index] = in;
            return false;
        }
        else
        {
            if (getposition(arr[index]->id, in->id) == 0)
            {
                return true;
            }
            node *temp = arr[index];
            while (temp->left)
            {
                if (getposition(temp->left->id, in->id) == 0)
                {
                    return true;
                }
                temp = temp->left;
            }
            temp->left = in;
            return false;
        }
        return true;
    }

    bool listdeletion(char arrr[])
    {
        int index = hashindex(arrr);
        if (getposition(arr[index]->id, arrr) == 0)
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
                if (getposition(ptr->left->id, arrr) == 0)
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

    node *listsearch(char arrr[])
    {
        int index = hashindex(arrr);
        if (arr[index] == NULL)
        {
            return NULL;
        }
        if (getposition(arr[index]->id, arrr) == 0)
        {
            return arr[index];
        }
        else
        {
            searchc++;
            node *ptr = arr[index];
            while (ptr->left != NULL)
            {
                if (getposition(ptr->left->id, arrr) == 0)
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
                    cout << "\nCNIC: ";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << temp->id[i];
                    }
                    cout << "-";
                    for (int i = 5; i < 12; i++)
                    {
                        cout << temp->id[i];
                    }
                    cout << "-";
                    cout << temp->id[12] << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Father Name: " << temp->fathername << endl;
                    cout << "Gender: " << temp->gender << endl;
                    cout << "Address: " << temp->address << endl
                         << endl;
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

    void deleteNode(char id[], node *&nodePtr)
    {
        if (nodePtr == NULL)
            cout << "\nID not Found\n";
        else if (getposition(nodePtr->id, id) < 0)
            deleteNode(id, nodePtr->left);
        else if (getposition(nodePtr->id, id) > 0)
            deleteNode(id, nodePtr->right);
        else
            makeDeletion(nodePtr);
    }

public:
    int searchc = 0;
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
                if (getposition(nodePtr->id, in->id) < 0)
                {
                    if (nodePtr->left)
                    {
                        nodePtr = nodePtr->left;
                    }
                    else
                    {
                        nodePtr->left = in;
                        return false;
                    }
                }
                else if (getposition(nodePtr->id, in->id) > 0)
                {
                    if (nodePtr->right)
                        nodePtr = nodePtr->right;
                    else
                    {
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

    void bstdeletion(char arrr[])
    {
        int index = hashindex(arrr);
        deleteNode(arrr, arr[index]);
    }

    node *bstsearch(char id[])
    {
        int index = hashindex(id);
        if (arr[index] == NULL)
        {
            return NULL;
        }
        else
        {
            searchc++;
            node *nodePtr = arr[index];
            while (nodePtr != NULL)
            {
                if (getposition(nodePtr->id, id) < 0)
                {
                    nodePtr = nodePtr->left;
                }
                else if (getposition(nodePtr->id, id) > 0)
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
            cout << "\nCNIC: ";
            for (int i = 0; i < 5; i++)
            {
                cout << temp->id[i];
            }
            cout << "-";
            for (int i = 5; i < 12; i++)
            {
                cout << temp->id[i];
            }
            cout << "-";
            cout << temp->id[12] << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Father Name: " << temp->fathername << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Address: " << temp->address << endl
                 << endl;
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

string getboysname()
{
    ifstream file("Namesboys.txt");
    if (!file.is_open())
    {
        cout << "Error: Unable to open the file." << endl;
    }
    int count = rand() % 10;
    string name, randomName;

    while (getline(file, name))
    {
        if (rand() % (++count) == 0)
        {
            randomName = name;
            break;
        }
    }
    file.close();

    return randomName;
}

string getgirlsname()
{
    ifstream file("Namesgirls.txt");
    if (!file.is_open())
    {
        cout << "Error: Unable to open the file." << endl;
    }
    int count = rand() % 10;
    string name, randomName;

    while (getline(file, name))
    {
        if (rand() % (++count) == 0)
        {
            randomName = name;
            break;
        }
    }
    file.close();

    return randomName;
}

string getaddress()
{
    ifstream file("Address.txt");
    if (!file.is_open())
    {
        cout << "Error: Unable to open the file." << endl;
    }
    int count = rand() % 10;
    string name, randomName;

    while (getline(file, name))
    {
        if (rand() % (++count) == 0)
        {
            randomName = name;
            break;
        }
    }
    file.close();

    return randomName;
}

node *createnode()
{
    node *temp = new node;
    for (int i = 0; i < 13; i++)
    {
        temp->id[i] = rand() % 10 + '0';
    }
    if (rand() % 3 == 2)
    {
        temp->gender = "Male";
        temp->name = getboysname();
        temp->fathername = getboysname();
    }
    else
    {
        temp->gender = "Female";
        temp->name = getgirlsname();
        temp->fathername = getboysname();
    }
    temp->address = getaddress();
    return temp;
}

node *linearinsert()
{
    node *temp = NULL;
    do
    {
        temp = createnode();
    } while (linear.insertlinear(temp));
    return temp;
}

node *listinsert()
{
    node *temp = NULL;
    do
    {
        temp = createnode();
    } while (list.listinsert(temp));
    return temp;
}

node *bstinsert()
{
    node *temp = NULL;
    do
    {
        temp = createnode();
    } while (bst.bstinsert(temp));
    return temp;
}

void Linearprobing()
{
    char choice;
    while (true)
    {
        cout << "\t-:'Linear probing':-\n";
        cout << "1. For Insertion\n";
        cout << "2. For Deletion\n";
        cout << "3. For searching\n";
        cout << "4. For Display ALL\n";
        cout << "5. To Return\n";
        cout << "Enter your Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case '1':
        {
            node *temp = linearinsert();
            cout << "\nCNIC: ";
            for (int i = 0; i < 5; i++)
            {
                cout << temp->id[i];
            }
            cout << "-";
            for (int i = 5; i < 12; i++)
            {
                cout << temp->id[i];
            }
            cout << "-";
            cout << temp->id[12] << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Father Name: " << temp->fathername << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Address: " << temp->address << endl
                 << endl;
        }
        break;
        case '2':
        {
            char c[14];
            cout << "Enter The ID No You Want To DELETE(xxxxxxxxxxxxx):";
            scanf("%[^\n]", &c);
            if (linear.deletionlinear(c))
            {
                cout << "\nID Not Found\n";
            }
            else
            {
                cout << "\nID Successfully Deleted\n";
            }
        }
        break;
        case '3':
        {
            char ch[14];
            node *temp = NULL;
            int i = 1;
            do
            {
                if (i > 1)
                {
                    cout << "ID Not Found\n";
                    cout << "Press 0 to exit Or 1 To continue:";
                    cin >> i;
                    cin.ignore();
                    continue;
                }
                else if (i == 0)
                {
                    break;
                }
                else if (i == 1)
                {
                    i++;
                    cout << "Enter The ID No You Want To Search(xxxxxxxxxxxxx):";
                    scanf("%[^\n]", &ch);
                    cin.ignore();
                    temp = linear.linearsearch(ch);
                }
            } while (temp == NULL);
            if (temp != NULL)
            {
                cout << "\nCNIC: ";
                for (int i = 0; i < 5; i++)
                {
                    cout << temp->id[i];
                }
                cout << "-";
                for (int i = 5; i < 12; i++)
                {
                    cout << temp->id[i];
                }
                cout << "-";
                cout << temp->id[12] << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Father Name: " << temp->fathername << endl;
                cout << "Gender: " << temp->gender << endl;
                cout << "Address: " << temp->address << endl
                     << endl;
            }
        }
        break;
        case '4':
            linear.DisplayAll();
            break;
        case '5':
            cout << "THANK YOU\n";
            return;
        default:
            cout << "Invalid choice\n";
        }
    }
}

void Linklistchanning()
{
    char choice;
    while (true)
    {
        cout << "\t-:'Linklist Channing':-\n";
        cout << "1. For Insertion\n";
        cout << "2. For searching\n";
        cout << "3. For Deletion\n";
        cout << "4. For DIsplay All\n";
        cout << "5. To Return\n";
        cout << "Enter your Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case '1':
        {
            node *temp = listinsert();
            cout << "\nCNIC: ";
            for (int i = 0; i < 5; i++)
            {
                cout << temp->id[i];
            }
            cout << "-";
            for (int i = 5; i < 12; i++)
            {
                cout << temp->id[i];
            }
            cout << "-";
            cout << temp->id[12] << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Father Name: " << temp->fathername << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Address: " << temp->address << endl
                 << endl;
        }
        break;
        case '2':
        {
            char ch[14];
            node *temp = NULL;
            int i = 1;
            do
            {
                if (i > 1)
                {
                    cout << "ID Not Found\n";
                    cout << "Press 0 to exit Or 1 To continue:";
                    cin >> i;
                    continue;
                }
                else if (i == 0)
                {
                    break;
                }
                else if (i == 1)
                {
                    i++;
                    cout << "Enter The ID No You Want To Search(xxxxxxxxxxxxx):";
                    scanf("%[^\n]", &ch);
                    cin.ignore();
                    temp = list.listsearch(ch);
                }
            } while (temp == NULL);
            if (temp != NULL)
            {
                cout << "\nCNIC: ";
                for (int i = 0; i < 5; i++)
                {
                    cout << temp->id[i];
                }
                cout << "-";
                for (int i = 5; i < 12; i++)
                {
                    cout << temp->id[i];
                }
                cout << "-";
                cout << temp->id[12] << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Father Name: " << temp->fathername << endl;
                cout << "Gender: " << temp->gender << endl;
                cout << "Address: " << temp->address << endl
                     << endl;
            }
        }
        break;
        case '3':
        {
            char c[14];
            int i = 1;
            cout << "Enter The ID No You Want To DELETE(xxxxxxxxxxxxx):";
            scanf("%[^\n]", &c);
            if (list.listdeletion(c))
            {
                cout << "\nID Not Found\n";
            }
            else
            {
                cout << "\nID Successfully Deleted\n";
            }
        }
        break;
        case '4':
            list.DisplayALL();
            break;
        case '5':
            cout << "THANK YOU\n";
            return;
        default:
            cout << "Invalid choice\n";
        }
    }
}

void Bstchanning()
{
    char choice;
    while (true)
    {
        cout << "\t-:'BST CHANNING':-\n";
        cout << "1. For Insertion\n";
        cout << "2. For searching\n";
        cout << "3. For Deletion\n";
        cout << "4. For Display ALL\n";
        cout << "5. To Return\n";
        cout << "Enter your Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case '1':
        {
            node *temp = bstinsert();
            cout << "\nCNIC: ";
            for (int i = 0; i < 5; i++)
            {
                cout << temp->id[i];
            }
            cout << "-";
            for (int i = 5; i < 12; i++)
            {
                cout << temp->id[i];
            }
            cout << "-";
            cout << temp->id[12] << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Father Name: " << temp->fathername << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Address: " << temp->address << endl
                 << endl;
        }
        break;
        case '2':
        {
            char ch[14];
            node *temp = NULL;
            int i = 1;
            do
            {
                if (i > 1)
                {
                    cout << "ID Not Found\n";
                    cout << "Press 0 to exit Or 1 To continue:";
                    cin >> i;
                    continue;
                }
                else if (i == 0)
                {
                    break;
                }
                else if (i == 1)
                {
                    i++;
                    cout << "Enter The ID No You Want To Search(xxxxxxxxxxxxx):";
                    scanf("%[^\n]", &ch);
                    cin.ignore();
                    temp = bst.bstsearch(ch);
                }
            } while (temp == NULL);
            if (temp != NULL)
            {
                cout << "\nCNIC: ";
                for (int i = 0; i < 5; i++)
                {
                    cout << temp->id[i];
                }
                cout << "-";
                for (int i = 5; i < 12; i++)
                {
                    cout << temp->id[i];
                }
                cout << "-";
                cout << temp->id[12] << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Father Name: " << temp->fathername << endl;
                cout << "Gender: " << temp->gender << endl;
                cout << "Address: " << temp->address << endl
                     << endl;
            }
        }
        break;
        case '3':
        {
            char c[14];
            cout << "Enter The ID No You Want To DELETE(xxxxxxxxxxxxx):";
            scanf("%[^\n]", &c);
            bst.bstdeletion(c);
        }
        break;
        case '4':
            bst.DisplayALL();
            break;
        case '5':
            cout << "THANK YOU\n";
            return;
        default:
            cout << "Invalid choice\n";
        }
    }
}

void mainmenu()
{
    char choice;
    while (true)
    {
        cout << "1. For Linear probing\n";
        cout << "2. For Linklist Channing\n";
        cout << "3. For BST Channing\n";
        cout << "4. Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case '1':
        {
            Linearprobing();
        }
        break;
        case '2':
        {
            Linklistchanning();
        }
        break;
        case '3':
        {
            Bstchanning();
        }
        break;
        case '4':
            cout << "THANK YOU\n";
            exit(0);
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    }
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        linearinsert();
    }
    for (int i = 0; i < 1000; i++)
    {
        listinsert();
    }
    for (int i = 0; i < 1000; i++)
    {
        bstinsert();
    }
    mainmenu();
    return 0;
}
