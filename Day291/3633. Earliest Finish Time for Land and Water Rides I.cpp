class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                          vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinish = INT_MAX;
        
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStartAfterLand = max(waterStartTime[j], landFinish);
                int finish1 = waterStartAfterLand + waterDuration[j];
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStartAfterWater = max(landStartTime[i], waterFinish);
                int finish2 = landStartAfterWater + landDuration[i];
                
                minFinish = min(minFinish, min(finish1, finish2));
            }
        }
        
        return minFinish;
    }
};