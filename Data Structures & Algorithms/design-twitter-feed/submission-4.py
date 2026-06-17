class Twitter:

    def __init__(self):
        self.untweets = {}
        self.tweets = {}
        self.users = {}

    def postTweet(self, userId: int, tweetId: int) -> None:
        user = self.users.get(userId, {
            "tweets": [],
            "followers": set(),
        })
        user["tweets"].append(tweetId)
        self.users[userId] = user
        self.untweets[len(self.tweets)] = tweetId
        self.tweets[tweetId] = len(self.tweets)

    def getNewsFeed(self, userId: int) -> List[int]:
        heap = []
        user = self.users.get(userId)
        for followerId in user["followers"]:
            for tweetId in self.users.get(followerId)["tweets"]:
                heapq.heappush(heap, -self.tweets[tweetId])
        for tweetId in user["tweets"]:
            heapq.heappush(heap, -self.tweets[tweetId])
        
        newsFeed = []
        for i in range(10):
            if len(heap) == 0:
                return newsFeed
            val = self.untweets[-heapq.heappop(heap)]
            newsFeed.append(val)
        return newsFeed

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId: return
        user = self.users.get(followerId, {
            "tweets": [],
            "followers": set()
        })
        user["followers"].add(followeeId)
        self.users[followerId] = user

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId: return
        user = self.users.get(followerId, {
            "tweets": [],
            "followers": set()
        })
        if not followeeId in user["followers"]: return
        user["followers"].remove(followeeId)
        self.users[followerId] = user
