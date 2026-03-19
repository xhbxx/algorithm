#include<iostream>
#include <stack>
#include<string>
using namespace std;
bool Priority(char ch, char topch)
{		
	if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
		return true;
	if (topch == '(' && ch != ')')
		return true;
	return false;
}
string middletoendexpr(string expr)
{
	string result;
	stack<char>s;
	for (char ch : expr)
	{
		if (ch >= '0' && ch <= '9')
		{
			result.push_back(ch);
		}	
		else
		{
			for (;;)
			{
				if (s.empty() || ch == '(')
				{
					s.push(ch);
					break;
				}
				char topch = s.top();
				if (Priority(ch, topch))
				{
					s.push(ch);
					break;
				}
				else
				{
					s.pop();
					if (topch == '(')
						break;
					result.push_back(topch);
				}
			}
		}
	}	
	while (!s.empty())
		{
			char topch = s.top();
			result.push_back(topch);
			s.pop();
		}
		return result;
	}


int main()
{
	cout << middletoendexpr("2*3+(5-6)/2") << endl;
	return 0;
}