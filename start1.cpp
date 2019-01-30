#include <iostream>
#include <string>
#include <exception>
#include "start1.h"

int main(){
	
	// Asks user if the user wants to make a Student Record
	std::cout << "Hello. Would you like to make a new Student Record today? (y-yes/n-no)" << std::endl;
	char input;
	std::cin >> input;
	
	if(input == 'y'){
		
		// Creates a new StudentRecord object to store the students in and a boolean for the while-loop
		StudentRecord newRecord;
		
		std::cout << "Congratulations! You have just created a Student Record." << std::endl;
		
		bool notDone = true;
		
		while(notDone){
			
			/*
			 * This stanza flushes both the input and output buffers.
			 * It has been placed before output and input statements to ensure that no errors occur in the output and input streams while the program is running.
			 */
			std::cout.flush();
			std::cin.clear();
			std::cin.ignore();
			
			// Asks user if the user wants to do anything with the Student Record
			std::cout << "Would you like to do anything with the record? (y-yes/n-no)" << std::endl;
			input = 0;
			std::cin >> input;
			
			// If user answered no, the boolean created above, "notDone", will be set to false so that the program can exit the while loop.
			if(input == 'n')
				notDone = false;
				
			/* 
			 * If user answered, the user will be asked whether the user wants to search the record for a student, add a student, remove a student, or do nothing.
			 * After the program performs the task desired by the user, the students currently in the Student Record will be printed.
			 */
			else if(input == 'y'){
				std::cout << "What would you like to do? Would you like to search for a student, enroll/add a student, or dismiss/remove a student? "
						  << "(a-add, s-search, r-remove, n-nothing)" << std::endl;
				char input2;
				std::cin >> input2;
				
				// This section is to add a student to the Student Record
				if(input2 == 'a'){
					std::cout.flush();
					std::cin.clear();
					std::cin.ignore();
					
					std::cout << "Please enter the full name of the student in the following format: FirstName LastName" << std::endl;
					std::string name;
					/*
					 * Here, the "std::getline" function is used instead of "std::cin" because "std::cin" only collects the user input until the space character is detected while
					 * the "std::getline" function gathers user input until the newline character is detected.
					 */
					std::getline(std::cin, name);
		
					std::cout << "Please enter the student identification number." << std::endl;
					int id;
					std::cin >> id;
				
					newRecord.enrollStudent(id, name);
				
					std::cout << "You have just added a new student to the record!" << std::endl;
				}
				
				// This section of code is to search for a student in the Student Record
				else if(input2 == 's'){
					std::cout.flush();
					std::cin.clear();
					std::cin.ignore();
					
					std::cout << "Please enter the full name of the student you wish to search for in the following format: "
							  << "FirstName LastName" << std::endl;
					std::string fullName1;
					std::getline(std::cin, fullName1);
					if(newRecord.searchStudent(fullName1))
						std::cout << "The student you are looking for DOES exist in this Student Record." << std::endl;
					else{
						std::cout << "The student you are looking for DOES NOT exist in this Student Record." << std::endl;
					}
				}
				
				// This section of code is to remove a student for the Student Record
				else if(input2 == 'r'){
					std::cout.flush();
					std::cin.clear();
					std::cin.ignore();
					
					std::string fullName;
					std::cout << "Please enter the name of the Student you would like to remove from the Student Record in the following format: " 
							  << "FirstName LastName" << std::endl;
					
					std::getline(std::cin, fullName);
					if(newRecord.dismissStudent(fullName)){
						std::cout << "You have successfully removed the student from the Student Record." << std::endl;
					}
					else{
						std::cout << "The student you are looking for DOES NOT exist in this Student Record." << std::endl;
					}
				}
				
				// This section of code does nothing except inform the user that the user has chosen to do nothing; this section is mainly for convenience.
				else if(input2 == 'n'){
					std::cout << "You have chosen to do nothing." << std::endl;
				}
				else{
					std::cout << "Invalid input." << std::endl;
				}
			}
			else{
				std::cout << "Invalid input: please try again." << std::endl;
			}
			// Prints out the names of all the students currently in the Student Record
			std::cout << "The students in the Student Record are:" << std::endl;
			newRecord.printRecord();
		}
		std::cout << "The students in the final Student Record are:" << std::endl;
		newRecord.printRecord();
	}
	std::cout << "Thanks for using this program. This program was written by Nihal Manjunath." << std::endl;
}
