#include <iostream>
using namespace std;

class String
{
public:
    String() = default;
    String(const char *string)
    {
        m_Size = strLen(string);

    }

private:
    char *c_Data;
    uint32_t m_Size;
};

int main()
{
    cin.get();
}
