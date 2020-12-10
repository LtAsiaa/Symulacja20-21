#include <iostream>
#include "transportCompany.h"
#include "truck.h"
#include "even_list.h"

int main()
{
	TransportCompany* transportcompany = new TransportCompany;
	const auto event_list = new Event_list;
	Process* current_process = new Truck(event_list, 0);
	current_process->activate(0);
	current_process = nullptr;

	int terminated_counter = 0;
	int highest_id = 0;


	cout << "\nProcesses created: " << highest_id << endl;
	cout << "Processes deleted: " << terminated_counter << endl;

	
	system("Pause");
}