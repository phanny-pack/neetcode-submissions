class DynamicArray {
private:
    // int* arr;
    std::vector<int> vec;
    int capacity;
    int size;

public:

    DynamicArray(int capacity) {
        // constructor
        this->vec = std::vector<int>(capacity);
        // this->vec = new int(capacity);
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int i) {
        return this->vec[i];
    }

    void set(int i, int n) {
        this->vec[i] = n;
    }

    void pushback(int n) {
        if (this->size == this->capacity) {
            this->resize();
        }

        
        this->vec[this->size] = n;
        this->size++;
    }

    int popback() {
        this->size--;
        return this->vec[this->size];
    }

    void resize() {
        this->capacity = this->capacity * 2;
        std::vector<int> resized_vec = std::vector<int>(this->capacity);
        for (int i = 0; i < this->size; i++) {
            resized_vec[i] = this->vec[i];
        }

        this->vec = resized_vec;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};
