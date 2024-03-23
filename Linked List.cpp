#include<iostream>
using namespace std;
struct node{
	int data;
	node* link;	
};
class linkedlist{
	node* head=NULL;
	public:
		void insertbeg(int data){
			node* newnode=new node();
			newnode->data=data;
			newnode->link=head;
			head=newnode;
			cout<<"Insertion successful."<<endl;
		}
		void insertmiddle(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->link==NULL){
				cout<<"There is only node node in the list."<<endl;
				cout<<"Please enter 1 or 3 "<<"depending on the position of the node to be inserted."<<endl;
			}
			else{
				int index=0;
				cout<<"Enter the index: ";
				cin>>index;
				if(index>count()||index<0){
					cout<<"Invalid index."<<endl;
				}else{		
					int data;
					cout<<"Enter the element: ";
					cin>>data;
					if(index==0){
						insertbeg(data);
					}else if(index==count()){
						insertend(data);
					}else{
						node* newnode=new node();
						newnode->data=data;
						int count=1;
						node* temp=head;
						node* temp2;
						while(count!=index){		
							temp=temp->link;
							count++;
						}
						temp2=temp->link;
						temp->link=newnode;
						newnode->link=temp2;
						cout<<"Insertion successful."<<endl;
					}	
				}
			}	
		}
		void insertend(int data){
			node* newnode=new node();
			newnode->data=data;
			newnode->link=NULL;
			if(head==NULL){
				head=newnode;
			}else{
				node* temp=head;
				while(temp->link!=NULL){
					temp=temp->link;
				}
				temp->link=newnode;
			}
			cout<<"Insertion Successful."<<endl;
		}
		void deletebeg(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				node* temp=head;
				head=head->link;
				delete temp;
				cout<<"Deletion successful."<<endl;
			}
		}
		void deletemiddle(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->link==NULL){
				cout<<"There is only one node in the list."<<endl;
				cout<<"Please enter 4 or 6 if the node has to be deleted."<<endl;
			}
			else{
				int index;
				cout<<"Enter the index: ";
				cin>>index;
				if(index>count()||index<0){
					cout<<"Invalid index."<<endl;
				}else{
					if(index==0){
						deletebeg();
					}else if(index==count()){
						deletend();
					}else{
						node* temp=head;
						int count=1;
						while(count!=index){
							temp=temp->link;
							count++;
						}	
						node* temp2=temp->link;
						temp->link=temp2->link;
						delete temp2;
						cout<<"Deletion successful."<<endl;
					}					
				}
			}	
		}
		void deletend(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->link==NULL){
				node* temp=head;
				delete temp;
				head=NULL;
				cout<<"Deletion successful."<<endl;
			}else{
				node* prev;
				node* temp=head;
				while(temp->link!=NULL){
					prev=temp;
					temp=temp->link;
				}
				prev->link=NULL;
				delete temp;
				cout<<"Deletion successful."<<endl;
			}		
		}
		void display(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}
			else{
				node* temp=head;
				cout<<"The elements of the list are: "<<endl;
				while(temp!=NULL){
					cout<<temp->data<<endl;
					temp=temp->link;
				}
			}
		}
		int count(){
			int c=1;
			if(head==NULL){
				c=0;
			}else{
				node* temp=head;
				while(temp->link!=NULL){
					temp=temp->link;
					c++;
				}
			}
			return c;
		}
		void search(){
			node* temp=head;
			int c=0;
			if(head==NULL){
				cout<<"The list is empty."<<endl;
			}else{
				int element;
				cout<<"Enter the element: ";
				cin>>element;
				bool found=false;
				while(temp->link!=NULL){	
					if(temp->data==element){
						cout<<element<<" is present at index: "<<c<<endl;
						found=true;
						break;
					}	
					c++;
					temp=temp->link;	
				}		
				if(!found){
					cout<<element<<" is not present in the list."<<endl;
				}
			}
		}
};

int main(){
	linkedlist li;
	int choice;
	do{
		cout<<endl<<"1. Insert an element in the beginning."<<endl;
		cout<<"2. Insert an element in the middle."<<endl;
		cout<<"3. Insert an element in the end."<<endl;
		cout<<"4. Delete an element in the beginning."<<endl;
		cout<<"5. Delete an element in the middle."<<endl;
		cout<<"6. Delete an element in the end."<<endl;
		cout<<"7. Display the list."<<endl;
		cout<<"8. Count the number of the nodes in the list."<<endl;
		cout<<"9. Search for an element in the list."<<endl;
		cout<<"10. Exit."<<endl<<endl;
		cout<<"Choice: ";
		int element;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the element: ";
				cin>>element;
				li.insertbeg(element);
				break;
			case 2:
				li.insertmiddle();
				break;
			case 3:
				cout<<"Enter the element: ";
				cin>>element;
				li.insertend(element);
				break;
			case 4:
				li.deletebeg();
				break;
			case 5:
				li.deletemiddle();
				break;
			case 6:
				li.deletend();
				break;
			case 7:
				li.display();
				break;
			case 8:
				cout<<"The number of nodes are: "<<li.count()<<endl;
				break;
			case 9:
				li.search();
				break;
			case 10:
				cout<<"Exited.";
				break;
			default:
				cout<<"Enter your choice from 1 to 10."<<endl;
				break;
		}
	}while(choice!=10);
	return 0;
}
