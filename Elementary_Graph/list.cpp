#include<iostream>

using namespace std;

struct node
{
	int data;
	int weight;
	int degree;

	struct node *next;
};

struct node* myinsert(int data,  struct node *head, int w)
{
	struct node *myinsert=(struct node*)malloc(sizeof(struct node));
	myinsert->next = NULL;
	myinsert->data = data;
	myinsert->weight = w;
	if(head!=NULL)
	{
		myinsert->next = head->next;
		head->next = myinsert;
	}
	else
	{
		myinsert->next = NULL;
	 	return myinsert;
	}

	return head;

}

struct node* myDelete(int data, struct node* head){
	struct node* temp = head;
	struct node* prev;
	if(head->data == data)
		head = head->next;
	else{
		while(temp){
			if(temp->data == data){
				prev->next = temp->next;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	return head;
}

void printList(struct node *head)
{
	struct node *temp = head;

	while(temp!=NULL)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
}
