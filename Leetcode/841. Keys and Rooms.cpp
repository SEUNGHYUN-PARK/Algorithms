class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> is_opened(rooms.size());
        is_opened[0]=true;
        go(rooms, is_opened, 0);
        for(int i=1;i<is_opened.size();i++)
        {
            if(is_opened[i]==false) return false;
        }
        return true;
    }
    void go(vector<vector<int>>& rooms, vector<bool> &is_opened, int _room)
    {
        is_opened[_room] = true;
        for(int i=0;i<rooms[_room].size();i++)
        {
            if(rooms[_room][i]>=0&&is_opened[rooms[_room][i]]==false)
                go(rooms, is_opened, rooms[_room][i]);
        }
    }
    
};