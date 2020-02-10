class TweetCounts {
    struct Twt{
        string twt_name;
        int sec;
        Twt(string twt_name, int sec){
            this->twt_name = twt_name;
            this->sec = sec;
        }
    };
public:
    int minute;
    int hour;
    int day;
    unordered_map<string, multiset<int> > m;
    vector<Twt> twt;
    TweetCounts() {
        minute = 60;
        hour = 3600;
        day = 3600 * 24;
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ans;
        int interval = 0;
        if(freq == "minute") interval = minute;
        else if(freq == "hour") interval = hour;
        else if(freq == "day") interval = day;
            for(int t = startTime; t <= endTime; t += interval){
                int start = t;
                int end = min(t + interval, endTime + 1);
                int cnt = 0;
                auto it = m[tweetName].lower_bound(startTime);
                if(it == m[tweetName].end() || (*it) > end) ans.push_back(0);
                else{
                    while(it != m[tweetName].end()){
                        if((*it) >= start && *(it) < end){
                            cnt++;
                        }
                        it++;
                    }
                    ans.push_back(cnt);
                }
            }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */