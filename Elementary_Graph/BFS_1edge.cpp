void enqueue(int x){
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	struct node* thead = head;
	temp->data = x;
	if(head == NULL){
		front = temp;
		rear = temp;
		temp->next = temp;
		head = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
		temp->next = head;
	}
}

void dequeue(){
	front = front->next;
	head = head->next;
	rear->next = head;
}

void BFS(int n){
    struct node* head = front = rear = NULL;
    bool visit[n];
    for(int i = 0; i < n; i++)
        visit[i] = false;

}
