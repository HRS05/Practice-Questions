class Twitter {
public:
    map<int,vector<pair<int,int>> > post;
    map<int,unordered_set<int> > folo;
    int counter;
    Twitter() {
        counter=0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({counter,tweetId});
        counter++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> list;
        //if(post.find(userId)==post.end()) return list;
        int x=0;
        for(int i=post[userId].size()-1;i>=0 && x<10;i--,x++)
        {
            list.push_back(post[userId][i]);
        }
        if(folo.find(userId)!=folo.end())
        {
            for(int id : folo[userId])
            {
                if(post.find(id)==post.end())  continue;
                x=0;
                for(int i=post[id].size()-1;i>=0 && x<10;i--,x++)
                {
                    list.push_back(post[id][i]);
                }
            }
        }
        sort(list.begin(),list.end());
        x=0;
        vector<int> l;
        for(int i=list.size()-1;i>=0 && x<10;i--,x++) l.push_back(list[i].second);
        return l;
    }
    
    void follow(int followerId, int followeeId) {
        folo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(folo.find(followerId)!=folo.end())
        {
            if(folo[followerId].find(followeeId) != folo[followerId].end())
                folo[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */