//1.
queue<pair<int, int>> q;
q.push(make_pair(i, j));

//2.
struct DATA
{
    int x;
    int y;
    DATA(){}; //이줄 안적어도됨
    DATA(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

vector<DATA> zero;
zero.push_back(DATA(i, j));