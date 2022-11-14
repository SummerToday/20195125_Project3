#include <iostream>
#include <cstring> //strcpy, strcmp

using namespace std;


class String
{
private:
	char* _chars;

public:
	String(){}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] } //string�� null ���Խ��Ѿ� �ϱ� ������ +1
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	bool operator==(const String& str)const {
		return strcmp(_chars, str._chars) == 0;
	}
	
	bool operator> (const String& str)const {
		return strcmp(_chars, str._chars) > 0;
	}

	bool operator<=(const String& str)const {
		//<=�� �ݴ�� >
		return !(*this > str);
	}

	//���⼭���� �߰��� �ۼ��� �ڵ��Դϴ�.
	bool operator!=(const String& str)const {
		return !(*this == str);
	}

	bool operator<(const String& str)const {
		return strcmp(_chars, str._chars) < 0;
	}
	bool operator>=(const String& str)const {
		return !(*this < str);
	}
};

int main() {
	String str0{ "abc" };
	String str1{ "cde" };

	if (str0 == str1) //str0.operator==(str1)
 		cout << "equal" << endl;

	if (str0 > str1) //str0.operator>(str1)
		cout << "str0>str1" << endl;

	if (str0 <= str1)
		cout << "str0<=str1" << endl;


	//�߰� �ڵ� Ȯ���ڵ�
	if (str0 != str1)
		cout << "str0!= str1" << endl;

	if (str0 < str1)
		cout << "str0 < str1" << endl;

	if (str0 >= str1)
		cout << " str0 >= str1" << endl;
}