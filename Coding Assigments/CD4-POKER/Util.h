#include <iostream>
template<typename T> class EbukaVector
{
    public:
        EbukaVector()
        {
            size = 0;
            capacity = 100;
            int* testData = new int[capacity];
            data = new T[capacity];
         
        }
        EbukaVector(int capacity)
        {
            size = 0;
            this->capacity = capacity;
            data = T[capacity];
        }
        void push_back(T value)
        {
            if(size == capacity)
            {
                T *temp = new T[capacity * 2];
                for(int i = 0; i < size; i++)
                {
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
                capacity *= 2;
            }
            data[size] = value;
            size++;
        }
        T pop()
        {
            T value = data[size - 1];
            size--;
            return value;
        }
        T get(int index)
        {
            return data[index];
        }
        int getSize()
        {
            return size;
        }
        void print()
        {
            for(int i = 0; i < size; i++)
            {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }

        void randomize(){
            for(int i = 0; i < size; i++){
                int randomIndex = rand() % size;
                T temp = data[i];
                data[i] = data[randomIndex];
                data[randomIndex] = temp;
            }
        }
        ~EbukaVector()
        {
            for (int i = 0; i < size; i++)
            {
                delete data[i];
            }
            delete[] data;
        }

        // T& EbukaVector::operator[](int index)
        // {
        //     if (index >= size) {
        //         cout << "Array index out of bound, exiting";
        //         exit(0);
        //     }
        //     return data[index];
        // }



    private:
        int size;
        int capacity;
        T *data = T[10];

};

