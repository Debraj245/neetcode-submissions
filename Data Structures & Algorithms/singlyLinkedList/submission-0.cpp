#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    int get(int i) {
        Node* curr = head;
        int index = 0;

        while (curr != nullptr) {
            if (index == i)
                return curr->val;
            curr = curr->next;
            index++;
        }

        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    bool remove(int i) {
        if (head == nullptr)
            return false;

        if (i == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* curr = head;
        int index = 0;

        while (curr != nullptr && index < i - 1) {
            curr = curr->next;
            index++;
        }

        if (curr == nullptr || curr->next == nullptr)
            return false;

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node* curr = head;

        while (curr != nullptr) {
            result.push_back(curr->val);
            curr = curr->next;
        }

        return result;
    }
};