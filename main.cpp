#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class LinkedList {
private:
    node* list;
public:
    LinkedList() : list(NULL) {}

    node* createNode() {
        node* p = new node;
        p->next = NULL;
        return p;
    }

    void freeNode(node* n) {
        delete n;
    }

    void add_first(int value) {
        node* p = createNode();
        p->data = value;
        p->next = list;
        list = p;
    }

    void add_last(int value) {
        node* p = createNode();
        p->data = value;

        if (list == NULL) {
            list = p;
            return;
        }

        node* temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }

    int remove_first() {
        if (list == NULL) {
            cout << "List is empty!\n";
            return -1;
        }

        node* temp = list;
        int value = temp->data;
        list = temp->next;
        freeNode(temp);
        return value;
    }

    int remove_last() {
        if (list == NULL) {
            cout << "List is empty!\n";
            return -1;
        }

        node* temp = list;
        node* prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        int value = temp->data;

        if (prev == NULL) {
            list = NULL; // only one node
        } else {
            prev->next = NULL;
        }

        freeNode(temp);
        return value;
    }

    void del(int value) {
        if (list == NULL) {
            cout << "List is empty!\n";
            return;
        }

        node* p = list;
        node* prev = NULL;

        while (p != NULL && p->data != value) {
            prev = p;
            p = p->next;
        }

        if (p == NULL) {
            cout << "Value not found!\n";
            return;
        }

        if (prev == NULL) {
            list = list->next;
        } else {
            prev->next = p->next;
        }

        freeNode(p);
        cout << "Deleted value " << value << endl;
    }

    int countNodes() {
        int count = 0;
        node* temp = list;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool search(int value) {
        node* temp = list;
        while (temp != NULL) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        if (list == NULL) {
            cout << "List is empty!\n";
            return;
        }

        node* temp = list;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList ll;
    int choice, value;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Add First\n";
        cout << "2. Add Last\n";
        cout << "3. Remove First\n";
        cout << "4. Remove Last\n";
        cout << "5. Delete by Value\n";
        cout << "6. Display\n";
        cout << "7. Count Nodes\n";
        cout << "8. Search Value\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            ll.add_first(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            ll.add_last(value);
            break;
        case 3:
            cout << "Removed: " << ll.remove_first() << endl;
            break;
        case 4:
            cout << "Removed: " << ll.remove_last() << endl;
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            ll.del(value);
            break;
        case 6:
            ll.display();
            break;
        case 7:
            cout << "Number of nodes: " << ll.countNodes() << endl;
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> value;
            if (ll.search(value))
                cout << "Value found!\n";
            else
                cout << "Value not found!\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
