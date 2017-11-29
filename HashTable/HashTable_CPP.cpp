#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

#define SIZE 100

class HashTable
{
    public:
        vector< list<string> > table;
        
    HashTable (int size)
    {
        table.resize(size);
    }

    int hash (string val)
    {
        int x = 0;

        for (int i = 0; val[i] != '\0'; ++i)
        {
            x = val[i];
        }

        return x % SIZE;
    }

    bool lookUp (string val)
    {
        int hashVal = hash(val);

        list<string>::iterator it;

        if (!table[hashVal].empty())
        {
            for (it = table[hashVal].begin(); it != table[hashVal].end(); it++)
            {
                if (*it == val)
                {
                    return true;
                }
            }
        }

        return false;
    }

    void add (string val)
    {
        int hashVal = hash(val);
        bool present = lookUp(val);

        if (!present)
        {
            table[hashVal].push_front(val);
            cout << val << " added!" << endl;
        }
    }

    void removeString (string val)
    {
        bool present = lookUp (val);
        int hashVal = hash(val);

        if (present)
        {
            table[hashVal].remove(val);
            cout << val << " removed!" << endl;
        }
        else
        {
            cout << "String: " << val << " does not exist in the Hash Table" << endl;
        }
    }

    ~HashTable()
    {}
};

int main (int argc, char** args)
{
    HashTable myTable(SIZE);

    myTable.add("Hello");
    myTable.add("H");
    myTable.add("ello");
    myTable.add("lo");
    myTable.add("llo");
    myTable.add("o");
    myTable.add("Hllo");
    myTable.add("Helo");
    myTable.add("Hello");

    myTable.removeString("Helloo");
    myTable.removeString("Hello");

    return 0;
}
