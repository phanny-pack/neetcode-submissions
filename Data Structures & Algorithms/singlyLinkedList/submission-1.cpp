class LinkedListNode
{
public:
    int val;
    LinkedListNode* next;

    LinkedListNode(int val) : val(val), next(nullptr) {}
    LinkedListNode(int val, LinkedListNode* next) : val(val), next(next) {}
};

class LinkedList 
{
private:
    LinkedListNode* m_head;
    LinkedListNode* m_tail;
    int m_size;

public:
    LinkedList() : 
        m_head(nullptr),
        m_tail(m_head),
        m_size(0)
    {
        
    }

    int get(int index) 
    {
        if (index >= 0 && index < m_size)
        {
            LinkedListNode* current = m_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->val;
        }
        return -1;
    }

    void insertHead(int val) 
    {
        LinkedListNode* newNode = new LinkedListNode(val);
        newNode->next = m_head;
        m_head = newNode;
        if (newNode->next == nullptr) {
            m_tail = newNode;
        }
        ++m_size;
    }
    
    void insertTail(int val) 
    {
        auto newNode = new LinkedListNode(val);
        if (m_tail == nullptr) {
            m_head = newNode;
            m_tail = newNode;
        }
        else {
            m_tail->next = newNode;
            m_tail = newNode;
        }
        ++m_size;
    }

    bool remove(int index) 
    {
        if (index < 0 || index >= m_size) {
            return false;
        }

        if (index == 0) {
            LinkedListNode* nodeToDelete = m_head;
            m_head = m_head->next;
            if (m_size == 1) {
                m_tail = nullptr;
            }
            delete nodeToDelete;
            --m_size;
            return true;
        }
        
        if (0 <= index && index < m_size)
        {
            LinkedListNode* current = m_head;
            
            for (int i = 0; i < index-1; ++i)
            {
                current = current->next;
            }
            LinkedListNode* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            if (nodeToDelete == m_tail) {
                m_tail = current;
            }
            delete nodeToDelete;
            --m_size;
            return true;
        }
        return false;
    }

    vector<int> getValues() 
    {
        auto values = vector<int>(m_size);
        LinkedListNode* current = m_head;
        for (int i = 0; i < m_size; i++)
        {
            values[i] = current->val;
            current = current->next;
        }
        return values;
    }
};
