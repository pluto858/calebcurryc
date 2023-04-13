#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <fstream>

using namespace std;

template<typename T> //some type we will call T
void print(T collection, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << collection[i] << endl;
	}
	
}

template<typename T>
void print(T collection)
{
	print(collection, collection.size());
}

class Food {
	public:
		string name;
		double cost;
		
		void print()
		{
			cout << name << " " << cost << endl;
		}
		
		static void printFoods(deque<Food> foods)
		{
			for(Food food: foods)
			{
				food.print();
			}	
		}
		
		static deque<Food> readFoods()
		{
			deque<Food> savedFoods;
			ifstream file("foods.txt");
			string name;
			double cost;
			
			while(file >> name >> cost)
			{
				savedFoods.push_back(Food(name, cost));
			}
			return savedFoods;
			file.close();
		}
		
		static void readFoods(deque<Food> &foods)
		{
			ifstream file("foods.txt");
			string name;
			double cost;
			
			while(file >> name >> cost)
			{
			foods.push_back(Food(name, cost));
			}
			file.close();
		}



		static void writeFoods(deque<Food> foods)
		{
			ofstream file("foods.txt");

			for(Food food: foods)
			{
				file << food.name << " " << food.cost << endl;
			}
		}

		Food(string name, double cost)
		{
			this->name=name;
			this->cost=cost;
		}
		Food()
		{

		}
		 
};


int main()
{
	deque<Food> foods; 
	Food::readFoods(foods);

	int response = 0;
	while(response != -1 && response != -2)
	{
		cout << "Choose an option:\n";
		cout << "1. display foods\n";
		cout << "2. add food to the front\n";
		cout << "3. add food to the back\n";
		cout << "4. remove from front\n";
		cout << "5. remove from back\n";
		cout << "-1. save and quit\n";
		cout << "-2. quit without saving\n";
		cout << "Your response: ";
	
		cin >> response;
		
		string name;
		double cost;
		switch(response)
		{
			case 1:
				Food::printFoods(foods);
				break;
			case 2:
				cout << "Food and cost? Example: pizza 43.32\n";
				cin >> name >> cost;
				foods.push_front(Food(name, cost));
				break;
			case 3:
				cout << "Food and cost? Example: pizza 43.32\n";
				cin >> name >> cost;
				foods.push_back(Food(name, cost));
				break;
			case 4:
				cout << "removing " << foods.front().name << "...\n";
				foods.pop_front();
				break;	
			case 5:
				cout << "removing " << foods.front().name << "...\n";
				foods.pop_back();
				break;	
			case -1:
				Food::writeFoods(foods);
			case -2:
				break;
	
		}
		cout << endl;
	}
	return 0;
}
