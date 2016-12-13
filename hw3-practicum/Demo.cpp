#include <iostream>
#include <string>
#include <stack>

bool correctInput(const std::string& input)
{
	if (input.empty())
	{
		return true;
	}

	std::stack<char> parentesisStorage;
	const char *inputData = input.c_str();
	for (int index = 0; index < input.length(); ++index)
	{
		char currentChar = inputData[index];
		
		if (currentChar == '{' && parentesisStorage.empty())
		{
			return false;
		}

		if (currentChar == '(' || currentChar == '{')
		{
			parentesisStorage.push(currentChar);
		}

		if (currentChar == ')' || currentChar == '}'){
			
			if (parentesisStorage.empty())
			{
				return false;
			}

			char lastChar = parentesisStorage.top();
			if (currentChar == ')' && lastChar == '(' || currentChar == '}' && lastChar == '{')
			{
				parentesisStorage.pop();
			}
			else
			{
				return false;
			}
		}
	}

	return parentesisStorage.empty();
}

void startApplication()
{
	std::cout << "Enter two strings describing a tree-strucure like this - (node {ancestors}): " << std::endl;

	std::string firstTree, secondTree;
	do{
		std::cout << "First string: ";
		getline(std::cin, firstTree);
		std::cout << "Second string: ";
		getline(std::cin, secondTree);
	} while (!correctInput(firstTree) && !correctInput(secondTree));

	std::cout << "Correct!" << std::endl;
}


int main()
{
	//startApplication();
	//std::string str1 = "(5{(9{})(1{(4{})(12{})(42{})})})";
//	std::string str2 = "(7{(15{(7{})(10{})(3{})})})";


	//add another case!!;
	std::string str1 = "(5{9{}(1{(4{})(12{})(42{})})})";
	std::string str2 = "(5{(9{})(1{(4{})(12{})(42{})})})";
	
	std::cout << correctInput(str1) << std::endl;
	std::cout << correctInput(str2) << std::endl;

	return 0;
}