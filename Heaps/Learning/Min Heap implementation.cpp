void push(priority_queue<int, vector<int>, greater<int>> &pq, int x)
{
    pq.push(x);
}

void pop(priority_queue<int, vector<int>, greater<int>> &pq)
{
    if (!pq.empty())
        pq.pop();
    else
        return;
}

int top(priority_queue<int, vector<int>, greater<int>> &pq)
{
    if (!pq.empty())
        return pq.top();
    else
        return -1;
}