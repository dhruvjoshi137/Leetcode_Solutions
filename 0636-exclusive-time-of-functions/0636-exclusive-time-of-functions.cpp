#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exclusiveTimes(n, 0);
        vector<int> functionStack;
        int previousTimestamp = 0;

        for (const string& log : logs) {
            stringstream logStream(log);
            string idString, eventType, timestampString;

            getline(logStream, idString, ':');
            getline(logStream, eventType, ':');
            getline(logStream, timestampString, ':');

            int functionId = stoi(idString);
            int currentTimestamp = stoi(timestampString);

            if (eventType == "start") {
                if (!functionStack.empty()) {
                    int runningFunctionId = functionStack.back();
                    exclusiveTimes[runningFunctionId] += currentTimestamp - previousTimestamp;
                }
                functionStack.push_back(functionId);
                previousTimestamp = currentTimestamp;
            } else {
                int finishedFunctionId = functionStack.back();
                exclusiveTimes[finishedFunctionId] += currentTimestamp - previousTimestamp + 1;
                functionStack.pop_back();
                previousTimestamp = currentTimestamp + 1;
            }
        }
        return exclusiveTimes;
    }
};
