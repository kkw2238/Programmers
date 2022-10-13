#include <string>
#include <map>
#include <iostream>

using namespace std;

/*
 * Complete the 'getMaximumCombatPower' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING adventures
 *  2. INTEGER k
 */

unsigned long long DEMONINATION = 1000000007;

unsigned long long getPower(map<char, unsigned long long>& tierScore)
{
    unsigned long long result = 0;
    for (auto score : tierScore)
    {
        result += score.second;
        result %= DEMONINATION;
    }

    return result;
}

unsigned long long scorePow(int score, int count)
{
    unsigned long long result = 1;
    for (int i = 0; i < count; ++i)
    {
        result *= (unsigned long long)score;
        result %= DEMONINATION;
    }

    return result;
}

void expelParty(map<char, unsigned long long>& tierScore, map<char, unsigned long long>& tierCount, char expel)
{
    unsigned long long expelScore = expel - 'a' + 1;
    --tierCount[expel];

    if (tierCount[expel] > 0)
    {
        tierScore[expel] = scorePow(expelScore, tierCount[expel]);
    }
    else
    {
        tierScore[expel] = 0;
    }
}

int getMaximumCombatPower(string adventures, int k) {
    map<char, unsigned long long> tierScore;
    map<char, unsigned long long> tierCount;
    unsigned long long power = 0;

    for (int i = 0; i < adventures.length(); ++i)
    {
        if (i >= k)
        {
            expelParty(tierScore, tierCount, adventures[i - k]);
        }

        if (tierCount[adventures[i]] == 0)
        {
            tierScore[adventures[i]] = 1;
        }

        unsigned long long score = (adventures[i] - 'a' + 1);

        ++tierCount[adventures[i]];
        tierScore[adventures[i]] = (tierScore[adventures[i]] * score) % DEMONINATION;
        if (i >= k - 1)
        {
            power = max(power, getPower(tierScore));
        }
    }

    return (int)(power % DEMONINATION);
}

int main()
{
    unsigned long long n = DEMONINATION * 2;
    string s = "ocrdfuddufbimbwyslmnhfumscrxiqksszfpfakezcqimqokndfavewrfigbbwbiwklhnehrjbubmxcuihujofwpgplsrwxzvhmpzxftbdmzarmnfyvubefwgbtcekzkzqhwkmhenmyfxlroldnuycwrsualxrjutlbxrbxjmxglhbfehlmeoukfkoaqqfexvwhbdodedbjwikcdubcfbauglstsuezxrmrggaqrqmxbynzwbojvhipzeqbevwanubmhqhbiabybgibegccaokxdjmejoaksfqveaopiufxosnzoldqcrueljreqtmmbbktglgstksmaamoqeohttvhlhdlwleuvnbknxpkszzfzonimalotrzksjtoxlljlyoadhkjntqkppgdnczdrrrwadzzfmqwljioqxfpheycwhusvuyglxfpjhtqqozyiccppoocsblokbomzqmwmgippuwfmlxoiehhjfujmuovnueqvxslkprwspvhoqveayrbkluvqywjumdwlkbcbgdxvlnrsouvmodutqkvbczkxgbrammmlvsblneiigptnjudsluxrwaauhugenldfslptlycibdvquhiqqdsxwwzxhqrdzerthqksgatzpfsddpsiwzpufsiokmeaiwhkmueyhefqttazlupsolfchvdvxiykmzpvcfrveicoosfleyqcelijlxpttxacxvzxtjltsyspjrzxnpqsrdzofxkwexlxnpfsylhzomtegizcvhpgnfrivuieveklumhmylojwczudzrigpeixguogdhuydfiqfqalplkpqxcnvpaevqpyrwzytqldlbgapikzruhojhetsvwkyoyqwbquuhtgqmzupepoygqfpemdtrckvpzzpwnbgnimqelfygbaqcxqhxucfsydouhveoddrvkkgqasqhrnvkjzwjcieahlvbnpuzrecqnapgqomyltqkzcisrjbjuvwcmzuvp";
    getMaximumCombatPower(s, 927);
}