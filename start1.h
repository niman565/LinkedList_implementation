#include <iostream>
#include <string>
#include <exception>

#ifndef START1_H
#define START1_H


class StudentRecord{
	struct Student{
		
		int id;                      //identification number of the student
		std::string name;            //name of the student
		Student *nextStudent;        //pointer to next "Student" node in linked list "StudentRecord"
		
		/*
		 * Constructors and Destructor.
		 * Constructors accept Student objects and Student fields as arguments.
		 */
		Student() : id(0) , name("") //default constructor; initializes fields to default values
			{nextStudent = NULL;}    //sets pointer to "NULL" since this is the default constructor
			
		Student(Student& s1) : id(s1.id) , name(s1.name)
			{this->nextStudent = s1.nextStudent;}
		
		//The following two constructors take L-value arguments.
		Student(int& idnum, std::string& newName) : id(idnum) , name(newName)
			{nextStudent = NULL;}
			
		Student(int& idnum, std::string& newName, Student& s2) : id(idnum) , name(newName)
			{nextStudent = &s2;}
			
		//The following two constructors take R-value arguments.
		Student(int&& idnum, std::string&& newName) : id(idnum) , name(newName)
			{nextStudent = NULL;}
			
		Student(int&& idnum, std::string&& newName, Student& s2) : id(idnum) , name(newName)
			{nextStudent = &s2;}
			
		~Student(){
			delete nextStudent;
			nextStudent = NULL;
		}
	};
	
	private:
	
		Student* head;
		int recordLength;
		
	public:
	
		//prints the names of each Student node in the Student Record linked list.
		void printRecord(){
			if(this->isEmpty()){
				std::cout << "The Student Record is empty." << std::endl;
			}
			else{
				Student *temp;
				temp = head;
				while(temp->nextStudent != NULL){
					std::cout << temp->name << ", ";
					temp = temp->nextStudent;
				}
				std::cout << temp->name << std::endl;
				//delete temp;
				temp = NULL;
			}
			return;
		}
		
		/*
		 * This adds a "Student" node to the "StudentRecord" linked list from the head Student node.
		 * One function takes a Student object as an argument and the other function takes the Student fields, an integer and a string, as arguments.
		 */
		void enrollStudent(Student& a){
			if(head != NULL){
				a.nextStudent = head;
				head = &a;
				recordLength++;
			}
			else{
				head = &a;
				recordLength++;
			}
			return;
		}
		
		void enrollStudent(int& idnum, std::string& name){
			Student* tempObject = new Student(idnum, name);
			if(head != NULL){
				Student* temp = head;
				head = tempObject;
				tempObject->nextStudent = temp;
			}
			else{
				head = tempObject;
			}
			tempObject = NULL;
			return;
		}
		
		//This method removes the specific "Student" node that the user specified with the input string from the student record.
		bool dismissStudent(std::string& name1){
			bool successful = false;
			if(isEmpty())
				return successful;
			else if(!searchStudent(name1))
				return successful;
			else{
				Student *a,*b;
				b = head;
				if(b->name.compare(name1) == 0){
					head = head->nextStudent;
					b->nextStudent = NULL;
					delete b;
					b = NULL;
					successful = true;
				}
				else{
					bool notNull = true;
					while(notNull){
						a = b;
						b = b->nextStudent;
						if(b == NULL)
							notNull = false;
						else if(b->name.compare(name1) == 0){
							a->nextStudent = b->nextStudent;
							b->nextStudent = NULL;
							delete b;
							b = NULL;
							successful = true;
							break;
						}
					}
				}
				return successful;																																																																																																																																																																																																																																																																																																																																																																																																																
			}
		}
		
		//This functions checks to see if the studentRecord is empty.
		bool isEmpty(){
			return (head == NULL);
		}
		
		/*
		 * This function takes a string as an argument and returns true if the name is in the studentRecord;
		 * if the name is not in the studentRecord or the studentRecord is empty, the function returns false.
		 * */
		bool searchStudent(std::string& name1){
			Student *a = head;
			bool found = false;
			if(isEmpty())
				found = false;
			else{
				bool notDone = true;
				while(notDone){
					if(a->name.compare(name1) == 0){
						notDone = false;
						found = true;
					}
					else if(a->nextStudent == NULL)
						notDone = false;
					else a = a->nextStudent;
				}
				if(!found)
					found = false;
			}
			return found;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		}
			
			
		/*
		 * Accessor methods for StudentRecord fields. 
		 * There is no need for mutator methods due to the fact that the user will not directly change "head" and "recordLength" fields 
		 */
		int getLength(){
			return recordLength;
		}
		
		std::string getFirstName(){
			return head->name;
		}
		
		Student* getHead(){
			return head;
		}
		
		/*
		 * Constructors and destructor. Constructors can take StudentRecords, Students, and Student fields as arguments.
		 * Destructor uses while loop to traverse and delete all Student objects in the Student Record
		 */
		StudentRecord() : head(NULL) , recordLength(0) {}
		
		StudentRecord(StudentRecord& a) : head(a.getHead()) , recordLength(a.getLength()) {}
		
		StudentRecord(Student& a) : head(&a) , recordLength(1) {}
		
		StudentRecord(int& num, std::string& name) : head() , recordLength(1){
			head = new Student(num, name);
		}
		
		~StudentRecord(){
			bool notDone = true;
			while(notDone){
				if(head == NULL)
					notDone = false;
				/*else if(head->nextStudent == NULL){
					delete head;
					head = NULL;
				}*/
				else{
					Student *a = head;
					head = a->nextStudent;
					a->nextStudent = NULL;
					delete a;
					a = NULL;
				}
			}
			delete head;
			head = NULL;
		}
};
#endif
