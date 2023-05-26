#include<iostream>
#include<string>
#define N 20
#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1

using namespace std;
string Q[N];
int Pr[N];
int r = -1,f = -1;
void enqueue(string data,int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
		cout<<"Queue is full";
	else {
		if(f==-1) { //if Queue is empty
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == N-1) { //if there there is some elemets in Queue
			for(i=f;i<=r;i++) { 
                                Q[i-f] = Q[i]; 
                                Pr[i-f] = Pr[i];
                                r = r-f; 
                                f = 0;
                                for(i = r;i>f;i--) {
					if(p>Pr[i]) {
						Q[i+1] = Q[i];
						Pr[i+1] = Pr[i];
					}
					else break;
						
					Q[i+1] = data;
					Pr[i+1] = p;
					r++;
				}
			}
		}
		else {
			for(i = r;i>=f;i--) {
				if(p>Pr[i]) {
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
	}

}
void print() { //print the data of Queue
	int i;
	for(i=f;i<=r;i++) {
		cout << "Patient's Name - "<<Q[i];
		switch(Pr[i]) {
			case 1: 
				cout << " Priority - 'Checkup' " << endl;
			break;
			case 5:
				cout << " Priority - 'Non-serious' " << endl;
			break;
			case 10:
				cout << " Priority - 'Serious' " << endl;
			break;
			default:
				cout << "Priority not found" << endl;
		}
	}
}

void dequeue() { //remove the data from front
	if(f == -1) {
		cout<<"Queue is Empty";
	}	
	else {
	cout<<"deleted Element ="<<Q[f]<<endl;
	cout<<"Its Priority = "<<Pr[f]<<endl;
		if(f==r) f = r = -1;
		else f++;
	}
}

int main() {
	string data;
	int opt,n,i,p;
	cout<<"Enter Your Choice:-"<<endl;
	do {
	cout << "1 for Insert the Data in Queue" << endl << "2 for show the Data in Queue " << endl << "3 for Delete the data from the Queue" 
		<< endl << "0 for Exit"<< endl;
	cin >> opt;
		switch(opt) {
			case 1:
				cout << "Enter the number of patinent" << endl;
				cin >> n;
				i = 0;
				while(i < n) {
					cout << "Enter your name of the patient : ";
					cin >> data;
					ifnotdoagain: 
						cout << "Enter your Prioritys (0: serious, 1: non-serious, 2: genral checkup) : ";
						cin >> p;
						switch(p) {
							case 0: 
								enqueue(data,SERIOUS);
							break;
							case 1: 
								enqueue(data,NONSERIOUS);
							break;
							case 2: 
								enqueue(data,CHECKUP);
							break;
							default:
								goto ifnotdoagain;
						}
						
					i++;
				}
			break;
			case 2:
			    if(f==-1 && r==-1)
	             {
	             cout<<"Queue is Empty";
                 }
	    		else print();
			break;
			case 3:
				 dequeue();
			break;
			case 0:
				cout << "Bye Bye !" << endl;
			break;
			default:
			cout<<"Incorrect Choice"<<endl;

		}
	}while(opt!=0);
        return 0;
}

