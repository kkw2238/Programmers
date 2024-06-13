/*
    https://programmers.co.kr/learn/courses/30/lessons/92341
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

struct ParkRecord
{
    int totalParkingTime = 0;
    int startParkingTime = -1;

    void Out(int outTime)
    {
        totalParkingTime += (outTime - startParkingTime);
        startParkingTime = -1;
    }

    const int GetFee(const vector<int>& fees)
    {
        int fee = fees[1];
        
        if (startParkingTime >= 0)
        {
            totalParkingTime += 1439 - startParkingTime;
        }

        totalParkingTime -= fees[0];

        if (totalParkingTime > 0)
        {
            int count = totalParkingTime / fees[2] + (int)(totalParkingTime % fees[2] > 0);

            fee += count * fees[3];
        }

        return fee;
    }
};

const int TransferMinute(const string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, ParkRecord> parkingRecords;
    vector<int> answer;

    for (const string& record : records)
    {
        int minute = TransferMinute(record.substr(0, 5));
        string carNumber = record.substr(6, 4);
        string type = record.substr(11);

        switch (type[0])
        {
        case 'I' :
            parkingRecords[carNumber].startParkingTime = minute;
            break;
        case 'O':
            parkingRecords[carNumber].Out(minute);
            break;
        }
    }

    for (auto& parkingRecord : parkingRecords)
    {
        answer.push_back(parkingRecord.second.GetFee(fees));
    }

    return answer;
}