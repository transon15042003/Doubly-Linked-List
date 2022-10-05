#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class IntDLinkedList
{
private:
    class Node;

private:
    Node *head;
    Node *tail;
    int count;

public:
    IntDLinkedList()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    ~IntDLinkedList()
    {
        this->clear();
    };
    // {{ STUDENT_ANSWER }}
    void dump()
    {
        if (this->count == 0)
        {
            assert(this->head == NULL);
            assert(this->tail == NULL);
            cout << "List: []" << endl;
            cout << "Reverse list: []" << endl;
            return;
        }

        cout << "List: [";
        Node *temp = this->head;
        while (temp != this->tail)
        {
            cout << temp->value << ",";
            temp = temp->next;
        }
        cout << temp->value << "]" << endl;

        cout << "Reverse list: [";
        temp = this->tail;
        while (temp != this->head)
        {
            cout << temp->value << ",";
            temp = temp->prev;
        }
        cout << temp->value << "]" << endl;
    }

    void add(int element)
    {
        Node *newNode = new Node(element);
        if (count == 0)
        {
            head = tail = newNode;
            count++;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            count++;
        }
    }

    void add(int index, int element)
    {
        Node *newNode = new Node(element);
        Node *pre = head;
        Node *temp = NULL;
        if (index > count || index < 0)
        {
            throw std::out_of_range("Invalid");
        }
        if (index == 0)
        {
            if (count == 0)
            {
                head = tail = newNode;
                count++;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                count++;
            }
        }
        else if (index == count)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            count++;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                pre = pre->next;
            }
            temp = pre->next;
            newNode->next = temp;
            temp->prev = newNode;
            newNode->prev = pre;
            pre->next = newNode;
            count++;
        }
    }

    int size()
    {
        return count;
    }

    bool empty()
    {
        return count == 0;
    }

    int removeAt(int index)
    {
        int result;
        Node *pre = head;
        Node *temp = head;
        if (index < 0 || index >= count || count <= 0)
        {
            throw std::out_of_range("Invalid");
        }
        else if (count == 1)
        {
            result = head->value;
            head = tail = NULL;
            count = 0;
            return result;
        }
        else if (index == 0)
        {
            result = head->value;
            head = head->next;
            head->prev = NULL;
            free(temp);
            count--;
            return result;
        }
        else if (index == count - 1)
        {
            int result = tail->value;
            tail = tail->prev;
            free(tail->next);
            tail->next = NULL;
            count--;
            return result;
        }
        else
        {
            for (int i = 0; i < index - 2; i++)
            {
                pre = pre->next;
            }
            temp = pre->next;
            pre->next = temp->next;
            (temp->next)->prev = pre;
            result = temp->value;
            free(temp);
            count--;
            return result;
        }
    }

    bool removeItem(int element)
    {
        Node *pre = NULL;
        Node *temp = head;
        if (temp == NULL)
        {
            return false;
        }
        if (temp->value == element)
        {
            head = temp->next;
            free(temp);
            head->prev = NULL;
            count--;
            return true;
        }
        while (temp != NULL && temp->value != element)
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return false;
        }
        pre->next = temp->next;
        (temp->next)->prev = pre;
        free(temp);
        count--;
        return true;
    }

    int get(int index)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Invalid index");
        }
        Node *temp = NULL;
        if (index < count / 2)
        {
            temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp->value;
        }
        else
        {
            temp = tail;
            for (int i = 0; i < count - index - 1; i++)
            {
                temp = temp->prev;
            }
            return temp->value;
        }
    }

    void set(int index, int element)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Invalid index");
        }
        Node *temp = NULL;
        if (index < count / 2)
        {
            temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->value = element;
        }
        else
        {
            temp = tail;
            for (int i = 0; i < count - index - 1; i++)
            {
                temp = temp->prev;
            }
            temp->value = element;
        }
    }

    int indexOf(int element)
    {
        Node *temp = head;
        int index = 0;
        while (temp != NULL && temp->value != element)
        {
            temp = temp->next;
            index++;
        }
        if (temp == NULL)
        {
            return -1;
        }
        return index;
    }

    bool contains(int element)
    {
        if (indexOf(element) != -1)
        {
            return true;
        }
        return false;
    }

    void clear()
    {
        Node *current = head;
        Node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }
        head = NULL;
        tail = NULL;
        count = 0;
    }

private:
    class Node
    {
    public:
        int value;
        Node *prev;
        Node *next;
        Node(int value = 0, Node *prev = NULL, Node *next = NULL) : value(value), prev(prev), next(next) {}
    };
};