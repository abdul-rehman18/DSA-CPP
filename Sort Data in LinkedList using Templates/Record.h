#include<string>
using namespace std;
class Record
{
public:
	int ID;
	string name;
	Record() = default;
	Record(int i, string n);
};
Record::Record(int i, string n)
{
	ID = i;
	name = n;
}