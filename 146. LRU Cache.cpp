struct Node
{
    int key;
    int value;
};

class LRUCache{
public:
    LRUCache(int capacity) 
    {
        maxSize = capacity;
    }
    
    int get(int key) 
    {
        map<int, list<Node>::iterator>::iterator it = mp.find(key);
        if(it == mp.end())      //没有命中
        {
            return -1;
        }
        else  //在cache中命中了
        {
            list<Node>::iterator listIt = mp[key];
            Node newNode;
            newNode.key = key;
            newNode.value = listIt->value;
            cacheList.erase(listIt);               //先删除命中的节点      
            cacheList.push_front(newNode);   //将命中的节点放到链表头部
            mp[key] = cacheList.begin();
        }
        return cacheList.begin()->value;
    }
    
    void set(int key, int value) 
    {
        map<int, list<Node>::iterator >::iterator it = mp.find(key);
        if(it == mp.end())   //没有命中
        {
            if(cacheList.size() == maxSize)  //cache满了
            {
                mp.erase(cacheList.back().key);    
                cacheList.pop_back();
            }
            Node newNode;
            newNode.key = key;
            newNode.value = value;
            cacheList.push_front(newNode);
            mp[key] = cacheList.begin();
        }
        else  //命中
        {
            list<Node>::iterator listIt = mp[key];
            cacheList.erase(listIt);               //先删除命中的节点          
            Node newNode;
            newNode.key = key;
            newNode.value = value;
            cacheList.push_front(newNode);   //将命中的节点放到链表头部
            mp[key] = cacheList.begin();
        }
    }
    
private:    
    int maxSize ;
    list<Node> cacheList;
    map<int, list<Node>::iterator> mp;
};