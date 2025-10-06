#include<iostream>
#include<ctime>
#include<cmath>
#include"coordinate.h"
void add_coordinate(Coordinate *list_end, float x, float y, int coord_id){


	Coordinate *new_coord = (Coordinate*)malloc(sizeof(Coordinate));

	new_coord->x = x;
	new_coord->y = y;
	new_coord->coord_id = coord_id;

	new_coord->next = NULL;
	new_coord->previous = list_end;

	list_end->next = new_coord;

	
}

void forward_display(Coordinate *list_beginning){

	Coordinate* temp = list_beginning;

	std::cout << "----------Forwards Display----------" << std::endl;

	while(temp != NULL){


		std::cout << "Linked List " << temp->coord_id << std::endl;
		std::cout << "Coordinate ID " << temp->coord_id << std::endl;
		std::cout << "X Coordinate " << temp->x << std::endl;
		std::cout << "Y Coordinate " << temp->y << std::endl;
		temp = temp->next;

	}
	
	delete temp;
}


void backward_display(Coordinate *list_end){

	Coordinate* temp = list_end;
	
	std::cout << "----------Backwards Display----------" << std::endl;

	while(temp!= NULL){

		std::cout << "Linked List " << temp->coord_id << std::endl;
		std::cout << "Coordinate ID " << temp->coord_id << std::endl;
		std::cout << "X Coordinate " << temp->x << std::endl;
		std::cout << "Y Coordinate " << temp->y << std::endl;
		
		temp = temp->previous;

	}

	delete temp;
}
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete){


	Coordinate* temp = list_beginning;

	while(temp != NULL){
		
		if(temp->coord_id == coord_id_to_delete){
			if(temp->previous != NULL){
				temp->previous->next = temp->next;
			}

			if(temp->next != NULL){
				temp->next->previous = temp->previous;
			
			}

		delete temp;
		std::cout << "Coordinate " << coord_id_to_delete << " Deleted Successfully!" << std::endl;
		return;

		} 
		
		temp = temp->next;
	}

	std::cout << "Coordinate ID was not found" << std::endl;

}
int list_length(Coordinate *list_beginning){

	Coordinate* temp = list_beginning;
	int length = 0;

	while(temp != NULL){

		length++;
		temp = temp->next;
	}
	

	delete temp;
	return length;
}
void closest_to(Coordinate *list_beginning, float x, float y){


	Coordinate* cur_coord = list_beginning;
	Coordinate* min_coord = list_beginning;

	double dist;
	double min_dist;

	min_dist = sqrt(pow(min_coord->x - x, 2) + pow(min_coord->y - y, 2));
	while(cur_coord != NULL){
		
		dist = sqrt(pow(cur_coord->x - x, 2) + pow(cur_coord->y - y, 2));
		if(dist < min_dist){

			min_dist = dist;
			min_coord = cur_coord;
		}

		cur_coord = cur_coord->next;

	}
	
	std::cout << "Closest Coordinate to " << x << " & " << y << " is " << min_coord->coord_id << std::endl;
}

int main(int argc, char* argv[]){

	srand(time(NULL));
	int size = atoi(argv[1]);
	int to_delete = 3;
	Coordinate* list_beginning = (Coordinate *)malloc(sizeof(Coordinate));
	
	list_beginning->next = NULL;
	list_beginning->previous = NULL;

	list_beginning->x = (float)(rand()%100);
	list_beginning->y = (float)(rand()%100);
	list_beginning->coord_id = 0;
	Coordinate* list_end = list_beginning;
	

	for(int i = 1; i < size; i++){
		float x = (float)(rand()%100);
		float y = (float)(rand()%100);
		add_coordinate(list_end, x, y, i);
		
		list_end = list_end->next;

	}

	list_end->coord_id = size;

	forward_display(list_beginning);
	backward_display(list_end);
	
	int length = list_length(list_beginning);
	
	float x = 10, y = 20;
	closest_to(list_beginning, x, y);

	delete_coordinate(list_beginning, to_delete);
	
	forward_display(list_beginning);
	backward_display(list_end);
	
	delete list_end;
  delete list_beginning;
}
