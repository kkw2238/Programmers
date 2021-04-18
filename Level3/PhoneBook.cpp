#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int phone_index = 0; phone_index < phone_book.size() - 1; ++phone_index)
    {
        if (phone_book[phone_index + 1].length() >= phone_book[phone_book].length())
        {
            continue;
        }

        if (phone_book[phone_index].compare(phone_book[phone_index + 1].substr(phone_book[phone_index].length())) == 0)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    vector<string> phone_book{ "119", "97674223", "1195524421" };

    solution(phone_book);
}