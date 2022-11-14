#include <iostream>
#include <cstring> //strcpy, strcmp

using namespace std;


class String
{
private:
	char* _chars;

public:
	String(){}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] } //string은 null 포함시켜야 하기 때문에 +1
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
		//<=의 반대는 >
		return !(*this > str);
	}

	//여기서부터 추가로 작성한 코드입니다.
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


	//추가 코드 확인코드
	if (str0 != str1)
		cout << "str0!= str1" << endl;

	if (str0 < str1)
		cout << "str0 < str1" << endl;

	if (str0 >= str1)
		cout << " str0 >= str1" << endl;
}