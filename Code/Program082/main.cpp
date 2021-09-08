/*
Created by  : Vaisakh Dileep
Date		: 24, January, 2021
Description : This program helps to understand shared_ptr(smart_pointer) in C++.
*/

#include<iostream>

#include<vector>

#include<memory> // We need this header file to use "shared_ptr".

using namespace std;

class Test
{
private:
	int data;
public:
	Test() // No-args constructor
		: data {0}
	{
		cout<<"No-args constructor called for Test.\n";
	}

	Test(int data) // Overloaded constructor
		: data {data}
	{
		cout<<"Overloaded constructor called for Test ["<<data<<"]\n";
	}

	~Test() // Destructor
	{
		cout<<"Destructor called for Test ["<<data<<"]\n";
	}

	int get_data() const
	{
		return data;
	}
};

int main()
{
/*
shared_ptr<T>: It provides shared ownership of heap objects.

Properties of shared_ptr:
1. It's not unique, there can be many shared_ptr pointing to the same object on the heap.
2. It establishes a shared ownership relationship.
3. They can be assigned and copied.
4. They can be moved.
5. When the use count is zero, the managed object on the heap is destroyed.
6. They don't support managing arrays by default.
*/
	shared_ptr<int> pointer_1 {new int {100}};

	cout<<"Use count[pointer_1]: "<<pointer_1.use_count()<<"\n\n";

	shared_ptr<int> pointer_2 {pointer_1};

	cout<<"Use count[pointer_1]: "<<pointer_1.use_count()<<"\n";
	cout<<"Use count[pointer_2]: "<<pointer_2.use_count()<<"\n\n";

	pointer_2.reset();

	cout<<"Use count[pointer_1]: "<<pointer_1.use_count()<<"\n";
	cout<<"Use count[pointer_2]: "<<pointer_2.use_count()<<"\n\n";

	// shared_ptr<int> pointer_3 = new int {200}; // This will give an error.

	shared_ptr<int> pointer_4 = make_shared<int>(200);

	cout<<"Use count[pointer_1]: "<<pointer_1.use_count()<<"\n";
	cout<<"Use count[pointer_2]: "<<pointer_2.use_count()<<"\n";
	cout<<"Use count[pointer_4]: "<<pointer_4.use_count()<<"\n\n";

	shared_ptr<Test> test_1 = make_shared<Test>(11);
	shared_ptr<Test> test_2 = make_shared<Test>(22);
	shared_ptr<Test> test_3 = make_shared<Test>(33);

	cout<<"Use count[test_1]: "<<test_1.use_count()<<"\n";
	cout<<"Use count[test_2]: "<<test_2.use_count()<<"\n";
	cout<<"Use count[test_3]: "<<test_2.use_count()<<"\n\n";

	vector<shared_ptr<Test>> test_vector;

	test_vector.push_back(test_1); // Here "test_1" is copied and not moved.
	test_vector.push_back(test_2);
	test_vector.push_back(test_3);

	cout<<"Use count[test_1]: "<<test_1.use_count()<<"\n";
	cout<<"Use count[test_2]: "<<test_2.use_count()<<"\n";
	cout<<"Use count[test_3]: "<<test_3.use_count()<<"\n\n";

	for(const auto test : test_vector) // This will work unlike "unique_ptr".
	{
		cout<<"Data: "<<test->get_data()<<"\n";

		cout<<"Use count[test_1]: "<<test_1.use_count()<<"\n";
		cout<<"Use count[test_2]: "<<test_2.use_count()<<"\n";
		cout<<"Use count[test_3]: "<<test_3.use_count()<<"\n";
	}

	cout<<"\n";

	for(const auto &test: test_vector)
	{
		cout<<"Data: "<<test->get_data()<<"\n";

		cout<<"Use count[test_1]: "<<test_1.use_count()<<"\n";
		cout<<"Use count[test_2]: "<<test_2.use_count()<<"\n";
		cout<<"Use count[test_3]: "<<test_3.use_count()<<"\n";
	}

	cout<<"\n";

	shared_ptr<Test> test_4 = make_shared<Test>(44);
	shared_ptr<Test> test_5 = make_shared<Test>(55);
	shared_ptr<Test> test_6 = make_shared<Test>(66);

	cout<<"Use count[test_4]: "<<test_4.use_count()<<"\n";
	cout<<"Use count[test_5]: "<<test_5.use_count()<<"\n";
	cout<<"Use count[test_6]: "<<test_6.use_count()<<"\n\n";

	vector<shared_ptr<Test>> test_vector_move;

	test_vector_move.push_back(move(test_4));
	test_vector_move.push_back(move(test_5));
	test_vector_move.push_back(move(test_6));

	cout<<"Use count[test_4]: "<<test_4.use_count()<<"\n"; // Since "test_4" is moved it becomes a null pointer, it's count is equal to '0'.
	cout<<"Use count[test_5]: "<<test_5.use_count()<<"\n";
	cout<<"Use count[test_6]: "<<test_6.use_count()<<"\n\n";

	for(const auto test : test_vector_move)
	{
		cout<<"Data: "<<test->get_data()<<"\n";

		cout<<"Use count[test_vector_move[0]]: "<<test_vector_move.at(0).use_count()<<"\n";
		cout<<"Use count[test_vector_move[1]]: "<<test_vector_move.at(1).use_count()<<"\n";
		cout<<"Use count[test_vector_move[2]]: "<<test_vector_move.at(2).use_count()<<"\n";
	}

	cout<<"\n";

	for(const auto &test: test_vector_move)
	{
		cout<<"Data: "<<test->get_data()<<"\n";

		cout<<"Use count[test_vector_move[0]]: "<<test_vector_move.at(0).use_count()<<"\n";
		cout<<"Use count[test_vector_move[1]]: "<<test_vector_move.at(1).use_count()<<"\n";
		cout<<"Use count[test_vector_move[2]]: "<<test_vector_move.at(2).use_count()<<"\n";
	}

	cout<<"\n";

	return 0;
}