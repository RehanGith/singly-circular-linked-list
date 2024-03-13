#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int num = 0) : data(num) , next(nullptr) {

	}
};
int search(node*& head, int sinfo) {
	node* temp = head;
	int n{1};
	do {
		if (temp->data == sinfo)
			return n;
		n++;
		temp = temp->next;
	} while (temp != head);
	return false;
}

void insert_at_head(node*& head, int n) {
	
	if (head == nullptr) {
		head = new node(n);
		head->next = head;
		return;
	}
	node* nnode = new node(n);
	head->next = nnode;
	nnode->next = head;
	head = nnode;
}
void add_at_end(node*& head, int n) {
	if (head == nullptr) {
		head = new node(n);
		head->next = head;
		return;
	}
	node* nnode = new node(n), *temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = nnode;
	nnode->next = head;
}

void display(node* head) {
	node* temp = nullptr;
	temp = head;
	do{
		cout << temp->data << endl;
		temp = temp->next;
	} while (temp != head);
}
int main() {
	node* head = nullptr;
	insert_at_head(head, 1);
	insert_at_head(head, 2);
	add_at_end(head, 3);
	display(head);
}
